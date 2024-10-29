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

    void set_is_catnet(bool state){is_catnet = state;}

private:

    catnetwork();

    ~catnetwork();

    void net_receive();

private:

    std::thread network_thread;

    uint16_t server_port;

    int sockServerfd;

    int len;

    struct sockaddr_in addrSrv, addrClient, addrServer;

    uint32_t server_uuid;

    bool is_catnet = false;

};

#endif //DEMO_NETWORK_H
