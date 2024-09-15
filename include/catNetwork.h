#ifndef DEMO_NETWORK_H
#define DEMO_NETWORK_H

#include <vector>
#include <cmath>
#include <chrono>
#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <unistd.h>
#include <sstream>
#include <arpa/inet.h>
#include <algorithm>
#include <iomanip>
#include <sys/time.h>
#include <linux/input.h>
#include "catbox_cmd.h"
#include "hid_controller.h"
#include "configuration.h"

class catnetwork {
public:
    static catnetwork &GetInstance() {
        static catnetwork instance;
        return instance;
    }

    void netStart();

    void neteJoin();

    void mouse_listen(struct input_event &ev);

    void keyboard_listen(struct input_event &ev);

    bool iskeyboardBlocked(int key);

    bool ismouseBlocked(int key);

    void set_is_catnet(bool state){is_catnet = state;}

private:

    catnetwork();

    ~catnetwork();

    void net_receive();

    void net_handle(client_tx data);

    void net_hid_send();

    void mouse_move_beizer(int x, int y, int ms, int x1, int y1, int x2, int y2);

    void mouse_automove(int x, int y, int ms);

    void handleKeyChanges(soft_keyboard_t current_report);

    int findKeyByValue(int value);

    std::string exec(const char* cmd);

private:

    std::thread network_thread;

    uint16_t server_port;

    int sockServerfd;

    int len;

    client_tx tx;							//发送的内容
    client_tx rx;							//接收的内容
    client_tx rx_enc;

    uint8_t enc_key[16] = { 0 };

    standard_mouse_report_t		mouse_report;   //硬件鼠标消息
    standard_keyboard_report_t	keyboard_report;//硬件键盘消息

    struct sockaddr_in addrSrv, addrClient, addrServer;

    socklen_t addrClientLen = sizeof(addrClient);

    Mouse m_mouse;
    Keyboard m_keyboard;

    //屏蔽的按键
    std::set<int> blocked_keyboard = {};
    std::set<int> blocked_mouse = {};

    //用于查找发过来的按键值
    soft_keyboard_t previous_report = {0};

    uint32_t server_uuid;

    bool is_listen = false;

    bool is_catnet = false;

};

#endif //DEMO_NETWORK_H
