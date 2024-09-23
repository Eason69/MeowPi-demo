#ifndef IPC_HELPER_H
#define IPC_HELPER_H

#include <thread>
#include "version.h"

static std::string k_http = "http";
static std::string k_alive = "alive";
static std::string k_del_firmware = "del_firmware";
static std::string v_http_start = "start";
static std::string v_http_stop = "stop";

class IpcHelper {
public:
    static IpcHelper &GetInstance() {
        static IpcHelper instance;
        return instance;
    }

    IpcHelper(const IpcHelper &) = delete;

    IpcHelper &operator=(const IpcHelper &) = delete;

private:
    std::string s_fifo_path = "/tmp/s_fifo";
    std::string d_fifo_path = "/tmp/d_fifo";
    int d_fd = -1;

    std::thread m_thread;
    std::thread m_alive_thread;
public:
    void sender(const std::string& key, const std::string& value) const;

    void reader() const;

    void listening();

    void threadJoin();
private:
    IpcHelper();

    ~IpcHelper();

    void init();

    void unInit() const;
};

#endif //IPC_HELPER_H
