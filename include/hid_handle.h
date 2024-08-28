#ifndef SUN_HID_HANDLE_H
#define SUN_HID_HANDLE_H

#include <thread>
#include <atomic>
#include "mouse.h"
#include "keyboard.h"

class hidhandle {
public:
    static hidhandle &GetInstance() {
        static hidhandle instance;
        return instance;
    }

    void hidhandleStart();

    void hidhandleJoin();

private:
    hidhandle();

    ~hidhandle();

    void calculate();

private:
    std::thread m_calculate_thread;
    Mouse m_mouse;
    Keyboard m_keyboard;
};


#endif //SUN_HID_HANDLE_H
