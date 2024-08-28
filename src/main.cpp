#include <atomic>
#include <csignal>

#include "lvgl_display.h"
#include "hid_handle.h"
#include "hid_controller.h"
#include "KmNetwork.h"
#include "configuration.h"

std::atomic<bool> is_stop;

int main(void)
{
    std::cout << "demo run!!!"<< std::endl;
    signal(SIGINT, [](int signum) { is_stop = true; });

    Configuration::GetInstance().loadConfig();
    HidController::GetInstance().listening();
    //hidhandle::GetInstance().hidhandleStart();//用于宏，未开发
    kmnetwork::GetInstance().netStart();
    Lvgl::GetInstance().lvglStart();
    Lvgl::GetInstance().lvglJoin();
    Configuration::GetInstance().Backlight_destruction();
    return 0;
}