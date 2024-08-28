#ifndef DEMO_CONFIGURATION_H
#define DEMO_CONFIGURATION_H

#include <libconfig.h>
#include <string>
#include <fcntl.h>
#include <unistd.h>
#include <sys/ioctl.h>

// 默认配置值
#define DEFAULT_IP "192.168.7.2" //网卡IP
#define DEFAULT_BACKLIGHT 204    //屏幕背光 0-255
#define DEFAULT_KMPORT 12345     //KMBOX的端口号
#define DEFAULT_WALL 1           //壁纸

//lcd背光
#define	DISP_LCD_SET_BRIGHTNESS  0x102
#define DISP_LCD_GET_BRIGHTNESS  0x103

class Configuration {

public:
    static Configuration &GetInstance() {
        static Configuration instance;
        return instance;
    }

    void loadConfig();

    void save_default_config();

    void set_ip_address(const char* ip_address);

    void setConfigValue(const std::string& path, int value);

    void setConfigString(const std::string& path, const std::string& value);

    void disp_set_brightness(int brightness);

    void Backlight_destruction();

    uint32_t generate_uuid_from_mac();

private:
    Configuration();

    ~Configuration();

private:
    int disp_fd;

public:
    int uuid = 0;
    const char *config_ip = DEFAULT_IP;
    int config_bg = DEFAULT_BACKLIGHT;
    int config_wallpaper = DEFAULT_WALL;
    int config_kmport = DEFAULT_KMPORT;

};


#endif //DEMO_CONFIGURATION_H
