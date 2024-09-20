#ifndef SUN_LVGL_DISPLAY_H
#define SUN_LVGL_DISPLAY_H

#include <thread>
#include <linux/input.h>
#include "lvgl.h"
#include "sunxifb.h"
#include "evdev.h"
#include "configuration.h"
#include "catNetwork.h"
#include <unistd.h>
#include <cstdlib>
#include <cstdio>
#include <atomic>
#include <iostream>
extern "C" {
#include "ui.h"
}

class Lvgl {
public:
    static Lvgl &GetInstance() {
        static Lvgl instance;
        return instance;
    }

    void lvglStart();

    void lvglJoin();

    void display();

    void parameter_set();

private:
    Lvgl();

    ~Lvgl();

    std::thread display_thread_;

};

#endif //SUN_LVGL_DISPLAY_H
