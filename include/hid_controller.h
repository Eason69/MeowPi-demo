#ifndef SUN_HID_CONTROLLER_H
#define SUN_HID_CONTROLLER_H

#include <vector>
#include <thread>
#include <poll.h>
#include <unordered_map>
#include <atomic>
#include <algorithm>
#include <shared_mutex>
#include "mouse.h"
#include "keyboard.h"
#include "catNetwork.h"

class HidController {
public:
    static HidController &GetInstance() {
        static HidController instance;
        return instance;
    }

    void listening();

    void threadJoin();

    HidController(const HidController &) = delete;

    HidController &operator=(const HidController &) = delete;

    void set_is_kb(bool state){is_kb = state;}

private:
    HidController();

    ~HidController();

    void hotPlugListening();

    void eventListening();

    void scanDevice();

    void addDevice(const char *dev_node);

    void removeDevice(const char *dev_node);

    void closeDevice();

    void keyboardEventHandle(struct input_event &ev);

    void mouseEventHandle(struct input_event &ev);

private:
    enum DeviceType {KEYBOARD, MOUSE, UNKNOWN};
    struct DeviceInfo {
        std::string dev_node;
        DeviceType type;
    };
    std::vector<struct pollfd> m_fds;
    std::unordered_map<int, DeviceInfo> m_device_map;
    std::thread m_hot_plug_thread;
    std::thread m_event_thread;

    Mouse m_mouse;
    Keyboard m_keyboard;

    bool is_kb = true;

    std::shared_mutex fds_mutex;
private:
    static DeviceType DetermineDeviceType(int);

};

#endif //SUN_HID_CONTROLLER_H
