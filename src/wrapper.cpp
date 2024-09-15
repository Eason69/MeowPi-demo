#include "wrapper.h"
#include "configuration.h"
#include "catNetwork.h"
#include "hid_controller.h"
extern "C" {
#include "ui.h"
}

extern "C" {
    void wrapper_SetBrightness(int brightness) {
        Configuration::GetInstance().disp_set_brightness(brightness);
    }

    void wrapper_SetConfigValue(const char* path, int value) {
        Configuration::GetInstance().setConfigValue(std::string(path), value);
    }

    void wrapper_SetConfigIP(int value1, int value2) {
        char ip[16];
        std::sprintf(ip, "192.168.%d.%d", value1, value2);
        Configuration::GetInstance().setConfigString("General.ip", ip);
        Configuration::GetInstance().set_ip_address(ip);
        Configuration::GetInstance().config_ip = ip;
        lv_label_set_text(ui_Label5, Configuration::GetInstance().config_ip);
    }

    void wrapper_SetKmPort(const char* port) {
        int port_int = std::stoi(port);
        Configuration::GetInstance().setConfigValue("Kmbox.port", port_int);
        Configuration::GetInstance().config_kmport = port_int;
    }

    void wrapper_KmnetManage(bool state) {
        if(state){
            catnetwork::GetInstance().set_is_catnet(false);
            catnetwork::GetInstance().netStart();
        }else{
            catnetwork::GetInstance().set_is_catnet(true);
            catnetwork::GetInstance().neteJoin();
        }
    }

    void wrapper_KeyManage(bool state) {
        HidController::GetInstance().set_is_kb(state);
    }

    void wrapper_hidupdata() {
        uint8_t hid_data[4] = {0xac,0xca,0x01,0x02};
        Uart::GetInstance().write(hid_data, sizeof(hid_data));
    }

}