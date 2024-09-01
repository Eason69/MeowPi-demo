#include <unistd.h>
#include <fcntl.h>
#include <dirent.h>
#include <fstream>
#include <sys/inotify.h>
#include <poll.h>
#include <cstring>
#include <iostream>
#include <atomic>
#include "hid_controller.h"

extern std::atomic<bool> is_stop;

HidController::HidController() {
    Uart::GetInstance().init();
}

HidController::~HidController() {
    threadJoin();
    std::cout << "[HID] HID已销毁。"<< std::endl;
}

void HidController::listening() {
    m_hot_plug_thread = std::thread([this] { hotPlugListening(); });
    m_event_thread = std::thread([this] { eventListening(); });
}

void HidController::threadJoin() {
    if (m_hot_plug_thread.joinable()) {
        m_hot_plug_thread.join();
    }
    if (m_event_thread.joinable()) {
        m_event_thread.join();
    }
}

HidController::DeviceType HidController::DetermineDeviceType(int fd) {
    unsigned char key_bitmask[(KEY_MAX + 1) / 8] = {0};
    if (ioctl(fd, EVIOCGBIT(EV_KEY, sizeof(key_bitmask)), key_bitmask) > 0) {
        if (key_bitmask[KEY_A / 8] & (1 << (KEY_A % 8))) {
            return DeviceType::KEYBOARD;
        }
    }
    unsigned char rel_bitmask[(REL_MAX + 1) / 8] = {0};
    if (ioctl(fd, EVIOCGBIT(EV_REL, sizeof(rel_bitmask)), rel_bitmask) > 0) {
        if (rel_bitmask[REL_X / 8] & (1 << (REL_X % 8))) {
            return DeviceType::MOUSE;
        }
    }
    return DeviceType::UNKNOWN;
}

void HidController::scanDevice() {
    const std::string input_dir = "/dev/input";

    DIR *dir = opendir(input_dir.c_str());
    if (dir == nullptr) {
        std::cerr << "[HID] 无法打开输入设备目录。" << std::endl;
        return;
    }
    struct dirent *entry;
    while ((entry = readdir(dir)) != nullptr) {
        if (strncmp(entry->d_name, "event", 5) != 0) {
            continue;
        }
        if (strcmp(entry->d_name, "event0") == 0) {
            continue; // 排除 event0 和 event1
        }
        std::string device_path = input_dir + "/" + entry->d_name;
        addDevice(device_path.c_str());
//        std::cout << "[HID]添加" << device_path.c_str() << std::endl;
    }
    closedir(dir);
}

void HidController::addDevice(const char *dev_node) {
    int fd = open(dev_node, O_RDONLY | O_NONBLOCK);
    if (fd < 0) {
        std::cerr << "[HID] 无法打开设备: " << dev_node << std::endl;
        return;
    }
    // 检查设备类型，并确保只添加有效的设备
    DeviceType deviceType = DetermineDeviceType(fd);
    if (deviceType != DeviceType::UNKNOWN) {
        if (m_device_map.find(fd) == m_device_map.end()) {
            DeviceInfo deviceInfo = {dev_node, deviceType};
            std::cout << "[HID] 添加fb设备:" << fd << std::endl;
            m_device_map.insert(std::make_pair(fd, deviceInfo));
            std::unique_lock<std::shared_mutex> lock(fds_mutex);
            m_fds.push_back({fd, POLLIN, 0});
        } else {
            std::cerr << "[HID] 设备已经存在: " << dev_node << std::endl;
            close(fd);
        }
    } else {
        close(fd);
    }
}

void HidController::removeDevice(const char *dev_node) {
    auto dev_iter = std::find_if(m_device_map.begin(), m_device_map.end(),
                                 [&](const auto &item) { return item.second.dev_node == dev_node; });
    if (dev_iter != m_device_map.end()) {
        int fd = dev_iter->first;
        auto fds_iter = std::find_if(m_fds.begin(), m_fds.end(),
                                     [fd](const pollfd &pfd) { return pfd.fd == fd; });
        if (fds_iter != m_fds.end()) {
            std::unique_lock<std::shared_mutex> lock(fds_mutex);
            m_fds.erase(fds_iter);
        }
        std::cout << "[HID] 删除fb设备:" << fd << std::endl;
        m_device_map.erase(fd);
        close(fd);
    }
}

void HidController::closeDevice() {
    for (auto &map: m_device_map) {
        removeDevice(map.second.dev_node.c_str());
    }
}

void HidController::hotPlugListening() {
    std::cout << "[HID] HID热插拔监听开启。" << std::endl;
    scanDevice();

    // 创建 inotify 实例
    int inotify_fd = inotify_init1(IN_NONBLOCK);
    if (inotify_fd < 0) {
        std::cerr << "[HID] 无法创建 inotify 实例" << std::endl;
        return;
    }

    // 监听 /dev/input 目录
    int watch_fd = inotify_add_watch(inotify_fd, "/dev/input", IN_CREATE | IN_DELETE);
    if (watch_fd < 0) {
        std::cerr << "[HID] 无法添加 inotify 监听" << std::endl;
        close(inotify_fd);
        return;
    }

    // 设置 poll 结构
    struct pollfd fds[] = { {inotify_fd, POLLIN, 0} };

    // 监听插拔
    while (!is_stop) {
        int result = poll(fds, 1, 100);
        if (result < 0) {
            std::cerr << "[HID] poll 调用失败" << std::endl;
            break;
        } else if (result > 0) {
            char buffer[1024];
            int length = read(inotify_fd, buffer, sizeof(buffer));
            if (length < 0) {
                std::cerr << "[HID] 读取 inotify 事件失败" << std::endl;
                break;
            }

            for (int i = 0; i < length; ) {
                struct inotify_event* event = (struct inotify_event*) &buffer[i];
                if (event->len > 0) {
                    if (strncmp(event->name, "event", 5) == 0) {
                        if (strcmp(event->name, "event0") == 0) {
                            i += sizeof(struct inotify_event) + event->len;
                            continue; // 跳过 event0
                        }

                        std::string dev_node = std::string("/dev/input/") + event->name;

                        if (event->mask & IN_CREATE) {
                            //std::cout << "[HID]添加" << dev_node.c_str() << std::endl;
                            addDevice(dev_node.c_str());
                        } else if (event->mask & IN_DELETE) {
                            //std::cout << "[HID]删除" << dev_node.c_str() << std::endl;
                            removeDevice(dev_node.c_str());
                        }
                    }
                }
                i += sizeof(struct inotify_event) + event->len;
            }
        }
    }

    inotify_rm_watch(inotify_fd, watch_fd);
    close(inotify_fd);
}

void HidController::eventListening() {
    std::cout << "[HID] HID事件监听开启。" << std::endl;
    while (!is_stop) {
        std::shared_lock<std::shared_mutex> lock(fds_mutex);
        int result = poll(m_fds.data(), m_fds.size(), 1);

        struct input_event ev{};
        if (result > 0) {
            for (const auto &fds: m_fds) {
                if (fds.revents & POLLIN) {
                    ssize_t bytes_read = read(fds.fd, &ev, sizeof(struct input_event));
                    if (bytes_read == sizeof(struct input_event)) {
                        auto it = m_device_map.find(fds.fd);
                        if (it != m_device_map.end()) {
                            DeviceInfo &device = it->second;
                            if (device.type == DeviceType::KEYBOARD) {
                                keyboardEventHandle(ev);
                            } else if (device.type == DeviceType::MOUSE) {
                                mouseEventHandle(ev);
                            }
                        }
                    }
                }
            }
        }
    }
    closeDevice();
}

void HidController::keyboardEventHandle(struct input_event &ev) {
    if (ev.type == EV_KEY) {
        if (is_kb && catnetwork::GetInstance().iskeyboardBlocked(ev.code)) {
            m_keyboard.passThrough(ev.code, static_cast<uint8_t>(ev.value));
        }
        catnetwork::GetInstance().keyboard_listen(ev);
    }
}

void HidController::mouseEventHandle(struct input_event &ev) {
    if(is_kb && catnetwork::GetInstance().ismouseBlocked(ev.code)) {
        if (ev.type == EV_REL) {
            if (ev.code == REL_WHEEL) { //滚轮
                m_mouse.passThrough(static_cast<uint8_t>(ev.code), static_cast<uint8_t>(ev.value));
            } else {
                auto move = static_cast<int16_t>(ev.value);
                m_mouse.passThrough(static_cast<uint8_t>(ev.code),
                                   static_cast<uint8_t>(move >> 8), static_cast<uint8_t>(move));
            }
        } else if (ev.type == EV_KEY) {
            m_mouse.passThrough(static_cast<uint8_t>(ev.code), static_cast<uint8_t>(ev.value));
        }
    }
    catnetwork::GetInstance().mouse_listen(ev);
}