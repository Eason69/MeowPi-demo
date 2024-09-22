#ifndef IPC_HELPER_H
#define IPC_HELPER_H

#include <thread>

class IpcHelper {
public:
    static IpcHelper &GetInstance() {
        static IpcHelper instance;
        return instance;
    }

    IpcHelper(const IpcHelper &) = delete;

    IpcHelper &operator=(const IpcHelper &) = delete;
public:
    static const int http_switch = 10;
    static const int heartbeat_sentry = 20;
    static const int heartbeat_demo = 21;

private:
    struct message {
        long msg_type;
        char msg_text[100];
    };

    std::string msg_path = "/tmp/ipc_key_file";

    int m_msg_id = -1;
    std::thread m_thread;
public:
    void sender(int msg_type, const std::string& data) const;

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
