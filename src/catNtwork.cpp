#include "catNetwork.h"

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
        // 接收客户端消息
        len = recvfrom(sockServerfd, (char *)&rx, BUFFER_SIZE, MSG_WAITALL, (struct sockaddr *)&addrClient, &addrClientLen);
        if (len < 0) {
            if (errno == EWOULDBLOCK || errno == EAGAIN) {
                // 超时，没有数据可读
                continue;
            } else {
                std::cerr << "[NET] 接收失败: " << strerror(errno) << std::endl;
                break;
            }
        }
        //std::cout << "[NET] Received " << len << " bytes from client: " << inet_ntoa(addrClient.sin_addr) << std::endl;
        net_handle();
    }
    close(sockServerfd);
}

void catnetwork::net_handle(){
    if(rx.head.mac == server_uuid){
        switch(rx.head.cmd) {
            case cmd_connect:
                addrServer.sin_family = AF_INET;
                addrServer.sin_addr = addrClient.sin_addr;
                std::cout << "[KMBOX] 连接成功" << std::endl;
                break;

            case cmd_monitor:
                if ((uint16_t) rx.head.rand) {
                    addrServer.sin_port = htons((uint16_t) rx.head.rand);
                    is_listen = true;
                    std::cout << "[KMBOX] 开始监听输出 端口:" << std::dec << ntohs(addrServer.sin_port) << std::endl;
                } else {
                    is_listen = false;
                    std::cout << "[KMBOX] 关闭监听输出" << std::endl;
                }
                break;

            case cmd_mouse_move:
                m_mouse.passThrough((uint8_t) REL_Y, (uint8_t) (rx.cmd_mouse.y >> 8), (uint8_t) (rx.cmd_mouse.y));
                m_mouse.passThrough((uint8_t) REL_X, (uint8_t) (rx.cmd_mouse.x >> 8), (uint8_t) (rx.cmd_mouse.x));
                break;

            case cmd_bazerMove:
                mouse_move_beizer(rx.cmd_mouse.x, rx.cmd_mouse.y, rx.head.rand, rx.cmd_mouse.point[0],
                                  rx.cmd_mouse.point[1], rx.cmd_mouse.point[2], rx.cmd_mouse.point[3]);
                break;

            case cmd_mask_mouse:
                if (rx.head.rand & 0xff00) {
                    blocked_keyboard.insert(findKeyByValue(rx.head.rand >> 8));
                }
                if (rx.head.rand & 0xff) {
                    for (int i = 0; i < 5; i++) {
                        if (rx.head.rand & (1 << i))
                            blocked_mouse.insert(BTN_LEFT + i);
                        else
                            blocked_mouse.erase(BTN_LEFT + i);
                    }
                    if (rx.head.rand & 0x20) //x
                        blocked_mouse.insert(REL_X);
                    else
                        blocked_mouse.erase(REL_X);
                    if (rx.head.rand & 0x40) //y
                        blocked_mouse.insert(REL_Y);
                    else
                        blocked_mouse.erase(REL_Y);
                    if (rx.head.rand & 0x80) //滚轮
                        blocked_mouse.insert(REL_WHEEL);
                    else
                        blocked_mouse.erase(REL_WHEEL);
                }
                break;

            case cmd_unmask_all:
                if (rx.head.rand == 0) {
                    blocked_mouse.clear();
                    blocked_keyboard.clear();
                } else {
                    blocked_keyboard.erase(findKeyByValue(rx.head.rand >> 8));
                }
                break;

            case cmd_mouse_left:
                if (rx.cmd_mouse.button & 0x01)
                    m_mouse.passThrough((uint8_t) BTN_LEFT, 1);
                else
                    m_mouse.passThrough((uint8_t) BTN_LEFT, 0);
                break;

            case cmd_mouse_right:
                if (rx.cmd_mouse.button & 0x02)
                    m_mouse.passThrough((uint8_t) BTN_RIGHT, 1);
                else
                    m_mouse.passThrough((uint8_t) BTN_RIGHT, 0);
                break;

            case cmd_mouse_middle:
                m_mouse.passThrough((uint8_t) REL_WHEEL, rx.cmd_mouse.wheel);
                break;

            case cmd_mouse_wheel:
                for(int i=0; i<5; i++){
                    if(rx.cmd_mouse.button & (1<<i))
                        m_mouse.passThrough((uint8_t) BTN_LEFT+i, 1);
                    else
                        m_mouse.passThrough((uint8_t) BTN_LEFT+i, 0);
                }
                m_mouse.passThrough((uint8_t) REL_Y, (uint8_t) (rx.cmd_mouse.y >> 8), (uint8_t) (rx.cmd_mouse.y));
                m_mouse.passThrough((uint8_t) REL_X, (uint8_t) (rx.cmd_mouse.x >> 8), (uint8_t) (rx.cmd_mouse.x));
                m_mouse.passThrough((uint8_t) REL_WHEEL, rx.cmd_mouse.wheel);
                break;

            case cmd_keyboard_all:
                handleKeyChanges(rx.cmd_keyboard);
                break;

            case cmd_mouse_automove:
                //只是简单的分段移动，待完善
                mouse_automove(rx.cmd_mouse.x, rx.cmd_mouse.y, rx.head.rand);
                break;

            default:
                std::cerr << "[KMBOX] 非命令" << std::endl;
                break;
        }
        // 发送响应回客户端
        int err = sendto(sockServerfd, (char*)&rx, len, MSG_CONFIRM, (const struct sockaddr *) &addrClient, sizeof(addrClient));
        if (err < 0) {
            std::cerr << "[NET] 发送失败" << std::endl;
        }

    }else
        std::cerr << "[NET] UUID错误" << std::endl;

}

void catnetwork::mouse_automove(int x, int y, int ms){
    // 计算每一步的x和y移动量
    double stepX = static_cast<double>(x) / ms;
    double stepY = static_cast<double>(y) / ms;

    double accumX = 0.0, accumY = 0.0;

    for (int i = 0; i < ms; ++i) {
        // 累计每次移动的距离
        accumX += stepX;
        accumY += stepY;

        // 取整获取这一步需要移动的整数距离
        int moveX = static_cast<int>(round(accumX));
        int moveY = static_cast<int>(round(accumY));

        // 减去已经移动的距离，防止下次迭代再次累加
        accumX -= moveX;
        accumY -= moveY;

        if(moveX != 0 || moveY != 0) {
            m_mouse.passThrough((uint8_t)REL_X, (uint8_t)(moveX >> 8), (uint8_t)(moveX));
            m_mouse.passThrough((uint8_t)REL_Y, (uint8_t)(moveY >> 8), (uint8_t)(moveY));
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(1));
    }
}

// 生成二阶贝塞尔曲线的点
std::vector<Point> generateBezierCurve(Point p0, Point p1, Point p2, int steps) {
    std::vector<Point> curve;
    curve.reserve(steps + 1);  // 预先分配内存

    int x0 = p0.x, y0 = p0.y;
    int x1 = p1.x, y1 = p1.y;
    int x2 = p2.x, y2 = p2.y;

    for (int i = 0; i <= steps; ++i) {
        float t = static_cast<float>(i) / steps;
        float u = 1 - t;
        float tt = t * t;
        float uu = u * u;
        // 直接计算出点
        int x = uu * x0 + 2 * u * t * x1 + tt * x2;
        int y = uu * y0 + 2 * u * t * y1 + tt * y2;
        curve.push_back({x, y});
    }
    return curve;
}

void catnetwork::mouse_move_beizer(int x, int y, int ms, int x1, int y1, int x2, int y2){
    Point start = {x1, y1};
    Point control = {x2, y2};
    Point end = {x, y};

    int steps = ms; // 每一步1毫秒，所以步数等于总毫秒数

    // 生成贝塞尔曲线的路径
    auto path = generateBezierCurve(start, control, end, steps);

    // 初始化相对位置
    int prev_x = start.x;
    int prev_y = start.y;

    // 模拟鼠标沿路径移动
    for (const auto& point : path) {
        int rel_x = point.x - prev_x;
        int rel_y = point.y - prev_y;

        m_mouse.passThrough((uint8_t)REL_X,(uint8_t)(rel_x >> 8), (uint8_t)(rel_x));
        m_mouse.passThrough((uint8_t)REL_Y,(uint8_t)(rel_y >> 8), (uint8_t)(rel_y));

        prev_x = point.x;
        prev_y = point.y;
        std::this_thread::sleep_for(std::chrono::microseconds(910));
    }
}

void catnetwork::mouse_listen(struct input_event &ev){
    if(is_listen){
        if (ev.type == EV_KEY) {
            if (ev.code >= BTN_LEFT && ev.code <= BTN_TASK) {
                if (ev.value == 1) { // button press
                    mouse_report.buttons |= (1 << (ev.code - BTN_LEFT));
                } else if (ev.value == 0) { // button release
                    mouse_report.buttons &= ~(1 << (ev.code - BTN_LEFT));
                }
            }
        } else if (ev.type == EV_REL) {
            if (ev.code == REL_X) {
                mouse_report.x = (int16_t)ev.value;
            } else if (ev.code == REL_Y) {
                mouse_report.y = (int16_t)ev.value;
            } else if (ev.code == REL_WHEEL) {
                mouse_report.wheel = (int16_t)ev.value;
            }
        }
        net_hid_send();
    }
}

void catnetwork::keyboard_listen(struct input_event &ev){
    if (!is_listen) {
        return;
    }
    auto it = cat_keyboard_map.find(ev.code);
    if (it == cat_keyboard_map.end()) {
        return;
    }
    uint8_t key = it->second;
    // 处理控制键
    if (key >= CAT_LEFTCONTROL && key <= CAT_RIGHT_GUI) {
        if (ev.value == 1) { // button press
            keyboard_report.buttons |= (1 << (key - CAT_LEFTCONTROL));
        } else if (ev.value == 0) { // button release
            keyboard_report.buttons &= ~(1 << (key - CAT_LEFTCONTROL));
        }
        net_hid_send();
        return;
    }
    // 处理普通按键
    if (ev.value == 1) { // 按键按下
        bool key_found = false;
        // 检查队列中是否存在按键
        for (int i = 0; i < 10; ++i) {
            if (keyboard_report.data[i] == key) {
                key_found = true;
                break;
            }
        }
        // 如果队列中不存在按键，添加到队列
        if (!key_found) {
            for (int i = 0; i < 10; ++i) {
                if (keyboard_report.data[i] == 0) {
                    keyboard_report.data[i] = key;
                    key_found = true;
                    break;
                }
            }
        }
        // 如果队列已满，移除最早的按键
        if (!key_found) {
            memmove(&keyboard_report.data[0], &keyboard_report.data[1], sizeof(keyboard_report.data) - 1);
            keyboard_report.data[9] = key;
        }
    } else if (ev.value == 0) { // 按键释放
        // 移除按键
        for (int i = 0; i < 10; ++i) {
            if (keyboard_report.data[i] == key) {
                // 将剩余的按键前移
                memmove(&keyboard_report.data[i], &keyboard_report.data[i + 1], sizeof(keyboard_report.data) - (i + 1));
                // 清空最后一个位置
                keyboard_report.data[9] = 0;
                break;
            }
        }
    }
    net_hid_send();
}

void catnetwork::net_hid_send(){
    uint8_t buffer[sizeof(standard_mouse_report_t) + sizeof(standard_keyboard_report_t)];
    memcpy(buffer, &mouse_report, sizeof(standard_mouse_report_t));
    memcpy(buffer + sizeof(standard_mouse_report_t), &keyboard_report, sizeof(standard_keyboard_report_t));
    int err = sendto(sockServerfd, (char*)&buffer, sizeof(buffer), MSG_CONFIRM, (const struct sockaddr *) &addrServer, sizeof(addrServer));
    if (err < 0) {
        std::cerr << "[NET] 发送失败" << std::endl;
    }
    mouse_report.x = 0;
    mouse_report.y = 0;
    mouse_report.wheel = 0;
}

void catnetwork::handleKeyChanges(soft_keyboard_t current_report){
    // 处理控制键（8个按钮）
    uint8_t changed_buttons = previous_report.ctrl ^ current_report.ctrl;
    if(changed_buttons) {
        for (int i = 0; i < 8; ++i) {
            if (changed_buttons & (1 << i)) {
                // 按钮状态发生变化
                bool is_pressed = (current_report.ctrl & (1 << i)) != 0;
                m_keyboard.passThrough(control_key[i], is_pressed);
            }
        }
    }

    // 处理常规按键（10个按键）
    bool key_found;
    for (int i = 0; i < 10; ++i) {
        key_found = false;
        int current_key = findKeyByValue(current_report.button[i]);

        // 检查是否是按下事件
        if (current_report.button[i] != 0 && previous_report.button[i] == 0) {
            m_keyboard.passThrough(current_key, 1);  // 发送按键按下事件
        }
        // 检查是否是释放事件
        if (current_report.button[i] == 0 && previous_report.button[i] != 0) {
            m_keyboard.passThrough(findKeyByValue(previous_report.button[i]), 0);  // 发送按键释放事件
        }

        // 更新之前的报告为当前报告
        if (current_report.button[i] == previous_report.button[i]) {
            key_found = true;
        }
    }

    // 更新之前的报告为当前报告
    std::memcpy(&previous_report, &current_report, sizeof(standard_keyboard_report_t));
}

int catnetwork::findKeyByValue(int value) {
    auto it = reverse_cat_keyboard_map.find(value);
    return (it != reverse_cat_keyboard_map.end()) ? it->second : value;
}

std::string catnetwork::exec(const char* cmd) {
    std::array<char, 128> buffer;
    std::string result;
    std::unique_ptr<FILE, decltype(&pclose)> pipe(popen(cmd, "r"), pclose);
    if (!pipe) {
        throw std::runtime_error("popen() failed!");
    }
    while (fgets(buffer.data(), buffer.size(), pipe.get()) != nullptr) {
        result += buffer.data();
    }
    return result;
}

bool catnetwork::iskeyboardBlocked(int key){
    return blocked_keyboard.find(key) == blocked_keyboard.end();
}

bool catnetwork::ismouseBlocked(int key){
    return blocked_mouse.find(key) == blocked_mouse.end();
}

void catnetwork::my_decrypt(unsigned char* input, unsigned char* key)
{
    unsigned char n = 32;
    unsigned long* a1 = (unsigned long*)input;
    unsigned long* a2 = (unsigned long*)key;
    unsigned long a3 = a1[n - 1], a4 = a1[0], sum = 0xE3779B90;
    unsigned char a5, a6, a7;
    a7 = 6; // 加密时的轮数
    while (a7-- > 0)
    {
        a5 = sum >> 2 & 3;
        for (a6 = n - 1; a6 > 0; a6--)
        {
            a4 = a1[a6 - 1];
            a3 = a1[a6] -= (a3 >> 5 ^ a4 << 2) + (a4 >> 3 ^ a3 << 4) ^ (sum ^ a4) + (a2[a6 & 3 ^ a5] ^ a3);
        }
        a4 = a1[n - 1];
        a3 = a1[0] -= (a3 >> 5 ^ a4 << 2) + (a4 >> 3 ^ a3 << 4) ^ (sum ^ a4) + (a2[a6 & 3 ^ a5] ^ a3);
        sum -= 2654435769; // 每轮减去加密时增加的常量
    }
}
