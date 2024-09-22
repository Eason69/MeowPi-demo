#include <atomic>
#include <iostream>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <fstream>
#include <filesystem>
#include <cstring>
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
    if (!std::filesystem::exists(msg_path)) {
        std::ofstream outfile(msg_path);
        if (!outfile) {
            return;
        }
        outfile.close();
    }
    key_t key = ftok(msg_path.c_str(), 99);
    if (key == -1) {
        return;
    }
    m_msg_id = msgget(key, 0666 | IPC_CREAT);
}

void IpcHelper::unInit() const {
    msgctl(m_msg_id, IPC_RMID, nullptr);
}

void IpcHelper::listening() {
//    m_thread = std::thread([this] { reader(); });
}

void IpcHelper::threadJoin() {
    if (m_thread.joinable()) {
        m_thread.join();
    }
}

void IpcHelper::sender(int msg_type, const std::string& data) const {
    message msg{};
    msg.msg_type = msg_type;
    strncpy(msg.msg_text, data.c_str(), sizeof(msg.msg_text) - 1);
    msg.msg_text[sizeof(msg.msg_text) - 1] = '\0';

    msgsnd(m_msg_id, &msg, sizeof(msg.msg_text), 0);
}

void IpcHelper::reader() const {
    message msg{};

    while (!is_stop) {
        int ret = msgrcv(m_msg_id, &msg, sizeof(msg.msg_text), 1, IPC_NOWAIT);
        if (ret == -1 && errno == ENOMSG) {
            std::this_thread::sleep_for(std::chrono::milliseconds(100));
            continue;
        }
        std::cout << "msg: " << msg.msg_text << std::endl;
        if (msg.msg_type == heartbeat_demo) {
//                sender(heartbeat_sentry, "alive");
        }
    }
}

