#include "catNetwork.h"
#include <iostream>


extern std::atomic<bool> is_stop;

catnetwork::catnetwork() {
}

catnetwork::~catnetwork() {
    neteJoin();
}

void catnetwork::netStart() {
    network_thread = std::thread([this] { net_receive(); });
}

void catnetwork::neteJoin() {
    if (network_thread.joinable()) {
        network_thread.join();
    }
}

void catnetwork::net_receive() {
    // 创建UDP socket
    if ((sockServerfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0) {
        std::cerr << "[NET] UDP socket创建失败" << std::endl;
        return;
    }

    // 配置服务器地址
    server_port =  Configuration::GetInstance().config_kmport;
    memset(&addrSrv, 0, sizeof(addrSrv));
    addrSrv.sin_family = AF_INET;
    addrSrv.sin_addr.s_addr = INADDR_ANY;
    addrSrv.sin_port = htons(server_port);

    server_uuid = Configuration::GetInstance().uuid;

    // 绑定socket
    if (bind(sockServerfd, (const struct sockaddr *)&addrSrv, sizeof(addrSrv)) < 0) {
        std::cerr << "[NET] 绑定失败" << std::endl;
        close(sockServerfd);
        return;
    }

    // 设置接收超时
    struct timeval timeout;
    timeout.tv_sec = 1;  // 超时时间1秒
    timeout.tv_usec = 0;

    if (setsockopt(sockServerfd, SOL_SOCKET, SO_RCVTIMEO, &timeout, sizeof(timeout)) < 0) {
        std::cerr << "[NET] 设置超时失败" << std::endl;
        close(sockServerfd);
        return;
    }

    while (!is_stop && !is_catnet) {
        // 接收客户端消息并且处理





    }
    close(sockServerfd);
}

