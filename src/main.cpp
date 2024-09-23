#include <atomic>
#include <csignal>

#include "lvgl_display.h"
#include "hid_handle.h"
#include "hid_controller.h"
#include "catNetwork.h"
#include "configuration.h"
#include "ipcHelper.h"
#include "version.h"


std::atomic<bool> is_stop;

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cerr << "Usage: " << argv[0] << " [--run|--version]" << std::endl;
        return 1;
    }
    std::string arg = argv[1];

    if (arg == "--run") {
        std::cout << "demo run!!!"<< std::endl;
        signal(SIGINT, [](int) { is_stop = true; });
        signal(SIGTERM, [](int) { is_stop = true; });

        Configuration::GetInstance().loadConfig();
        HidController::GetInstance().listening();
        IpcHelper::GetInstance().listening();
        //hidhandle::GetInstance().hidhandleStart();//用于宏，未开发
        catnetwork::GetInstance().netStart();
        Lvgl::GetInstance().lvglStart();
        Lvgl::GetInstance().lvglJoin();
        Configuration::GetInstance().Backlight_destruction();
        return 0;
    }
    if (arg == "--version") {
        std::cout << VERSION << std::endl;
        return 0;
    }
    std::cerr << "Unknown command: " << arg << std::endl;
    return 0;
}