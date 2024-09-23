#include <atomic>
#include <iostream>
#include <fcntl.h>
#include <poll.h>
#include <unistd.h>
#include <sys/stat.h>
#include "ipcHelper.h"

extern std::atomic<bool> is_stop;

IpcHelper::IpcHelper() {
    init();
};

IpcHelper::~IpcHelper() {
    threadJoin();
    unInit();
};

void IpcHelper::init() {
    if (mkfifo(d_fifo_path.c_str(), 0666) == -1) {
        if (errno != EEXIST) {
            perror("[IpcHelper] mkfifo failed");
            return;
        }
    }

    d_fd = open(d_fifo_path.c_str(), O_RDONLY | O_NONBLOCK);
    if (d_fd == -1) {
        perror("open failed");
        return;
    }
}

void IpcHelper::unInit() const {
    close(d_fd);
    unlink(d_fifo_path.c_str());
}

void IpcHelper::listening() {
    m_thread = std::thread([this] { reader(); });
    m_alive_thread = std::thread([this] {
        while (!is_stop) {
            sender(k_alive, "I'm alive.version:" + std::string(VERSION));
            std::this_thread::sleep_for(std::chrono::milliseconds(1000));
        }
    });
}

void IpcHelper::threadJoin() {
    if (m_thread.joinable()) {
        m_thread.join();
    }
    if (m_alive_thread.joinable()) {
        m_alive_thread.join();
    }
}

void IpcHelper::sender(const std::string& key, const std::string& value) const {
    int s_fd = open(s_fifo_path.c_str(), O_WRONLY | O_NONBLOCK);
    if (s_fd == -1) {
        perror("s_fd open failed");
        return;
    }
    std::string text = key + "," + value;
    write(s_fd, text.c_str(), text.size() + 1);
    close(s_fd);
}

void IpcHelper::reader() const {
    struct pollfd fds = {d_fd, POLLIN, 0};

    while (!is_stop) {
        int result = poll(&fds, 1, 100);
        if (result > 0) {
            char buffer[1024];
            ssize_t bytesRead = read(d_fd, buffer, sizeof(buffer));
            if (bytesRead > 0) {
                std::string full_message = std::string (buffer);

                size_t delimiter_pos = full_message.find(',');
                if (delimiter_pos != std::string::npos) {
                    std::string key = full_message.substr(0, delimiter_pos);
                    std::string value = full_message.substr(delimiter_pos + 1);

                }
            }
        }
    }
}
