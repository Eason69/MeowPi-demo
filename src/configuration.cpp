#include "configuration.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <cstring>

static const char* filename = "/mnt/UDISK/data/config.cfg";

Configuration::Configuration() = default;

Configuration::~Configuration() = default;

void Configuration::loadConfig() {
    config_t cfg;
    config_init(&cfg);

    disp_fd = open("/dev/disp", O_RDWR, 0);
    if (disp_fd < 0) {
        std::cerr << "/dev/disp" << " 打开失败" << std::endl;
    }

    if (!config_read_file(&cfg, filename)) {
        std::cout << "创建配置文件" << std::endl;
        // 如果读取失败，则创建并保存默认配置
        save_default_config();
        if (!config_read_file(&cfg, filename)) {
            std::cerr << "读取配置文件时出错。" << std::endl;
            config_destroy(&cfg);
            return;
        }
    }

    bool config_modified = false;

    // 获取 General 组
    config_setting_t *general = config_lookup(&cfg, "General");
    if (!general) {
        general = config_setting_add(config_root_setting(&cfg), "General", CONFIG_TYPE_GROUP);
        config_modified = true;
    }

    // 读取 General.uuid (使用 MAC 地址生成的 uint32_t)
    if (config_lookup_int(&cfg, "General.uuid", &uuid)) {
        std::cout << "General.uuid = " << std::hex << uuid << std::endl;
    } else {
        uuid = (int)generate_uuid_from_mac();
        std::cout << "未找到 General.uuid，使用 MAC 地址生成 UUID: " << std::hex << uuid << std::endl;

        config_setting_t *uuid_setting = config_setting_add(general, "uuid", CONFIG_TYPE_INT);
        config_setting_set_int(uuid_setting, uuid);
        config_modified = true;
    }

    // 读取 General.wallpaper
    if (config_lookup_int(&cfg, "General.wallpaper", &config_wallpaper)) {
        std::cout << "General.wallpaper = " << config_wallpaper << std::endl;
    } else {
        std::cout << "未找到 General.wallpaper，创建默认值 " << DEFAULT_WALL << std::endl;
        config_setting_t *wallpaper_setting = config_setting_add(general, "wallpaper", CONFIG_TYPE_INT);
        config_setting_set_int(wallpaper_setting, DEFAULT_WALL);
        config_modified = true;
    }

    // 读取 General.ip
    if (config_lookup_string(&cfg, "General.ip", &config_ip)) {
        std::cout << "General.ip = " << config_ip << std::endl;
        set_ip_address(config_ip);
    } else {
        std::cout << "未找到 General.ip，创建默认值 " << DEFAULT_IP << std::endl;
        config_setting_t *ip_setting = config_setting_add(general, "ip", CONFIG_TYPE_STRING);
        config_setting_set_string(ip_setting, DEFAULT_IP);
        config_modified = true;
    }

    // 读取 General.backlight
    if (config_lookup_int(&cfg, "General.backlight", &config_bg)) {
        std::cout << "General.backlight = " << config_bg << std::endl;
        disp_set_brightness(config_bg);
    } else {
        std::cout << "未找到 General.backlight，创建默认值 " << DEFAULT_BACKLIGHT << std::endl;
        config_setting_t *bg_setting = config_setting_add(general, "backlight", CONFIG_TYPE_INT);
        config_setting_set_int(bg_setting, DEFAULT_BACKLIGHT);
        config_modified = true;
    }

    // 获取 Kmbox 组
    config_setting_t *kmbox = config_lookup(&cfg, "Kmbox");
    if (!kmbox) {
        kmbox = config_setting_add(config_root_setting(&cfg), "Kmbox", CONFIG_TYPE_GROUP);
        config_modified = true;
    }

    // 读取 Kmbox.port
    if (config_lookup_int(&cfg, "Kmbox.port", &config_kmport)) {
        std::cout << "Kmbox.port = " << config_kmport << std::endl;
    } else {
        std::cout << "未找到 Kmbox.port，创建默认值 " << DEFAULT_KMPORT << std::endl;
        config_setting_t *port_setting = config_setting_add(kmbox, "port", CONFIG_TYPE_INT);
        config_setting_set_int(port_setting, DEFAULT_KMPORT);
        config_modified = true;
    }

    if (config_modified) {
        // 如果有新的配置项被创建，则保存配置文件
        if (!config_write_file(&cfg, filename)) {
            std::cerr << "保存配置文件时出错。" << std::endl;
        }
    }

    config_destroy(&cfg);
}

// 保存默认配置到文件
void Configuration::save_default_config() {
    config_t cfg;
    config_init(&cfg);

    config_setting_t *root = config_root_setting(&cfg);

    // General settings
    config_setting_t *general = config_setting_add(root, "General", CONFIG_TYPE_GROUP);

    // 生成UUID并保存
    uuid = (int)generate_uuid_from_mac();
    config_setting_t *uuid_setting = config_setting_add(general, "uuid", CONFIG_TYPE_INT);
    config_setting_set_int(uuid_setting, uuid);

    config_setting_t *wallpaper_setting = config_setting_add(general, "wallpaper", CONFIG_TYPE_INT);
    config_setting_set_int(wallpaper_setting, DEFAULT_WALL);
    config_setting_t *ip_setting = config_setting_add(general, "ip", CONFIG_TYPE_STRING);
    config_setting_set_string(ip_setting, DEFAULT_IP);
    config_setting_t *bg_setting = config_setting_add(general, "backlight", CONFIG_TYPE_INT);
    config_setting_set_int(bg_setting, DEFAULT_BACKLIGHT);

    // Kmbox settings
    config_setting_t *kmbox = config_setting_add(root, "Kmbox", CONFIG_TYPE_GROUP);
    config_setting_t *port_setting = config_setting_add(kmbox, "port", CONFIG_TYPE_INT);
    config_setting_set_int(port_setting, DEFAULT_KMPORT);

    // Write the file
    if (!config_write_file(&cfg, filename)) {
        std::cerr << "写入默认配置文件时出错。" << std::endl;
    }

    config_destroy(&cfg);
}

void Configuration::setConfigValue(const std::string& path, int value) {
    config_t cfg;
    config_init(&cfg);

    // 读取配置文件
    if (!config_read_file(&cfg, filename)) {
        std::cerr << "无法读取配置文件。" << std::endl;
        config_destroy(&cfg);
        return;
    }

    // 查找设置项
    config_setting_t *setting = config_lookup(&cfg, path.c_str());
    if (setting) {
        // 更新设置项的值
        if (config_setting_set_int(setting, value)) {
            std::cout << "设置 " << path << " 为 " << value << std::endl;
        } else {
            std::cerr << "无法更新设置项 " << path << std::endl;
        }
    } else {
        std::cerr << "未找到配置项 " << path << "，无法修改。" << std::endl;
    }

    // 保存配置文件
    if (!config_write_file(&cfg, filename)) {
        std::cerr << "无法保存配置文件。" << std::endl;
    }

    config_destroy(&cfg);
}

void Configuration::setConfigString(const std::string& path, const std::string& value) {
    config_t cfg;
    config_init(&cfg);

    // 读取配置文件
    if (!config_read_file(&cfg, filename)) {
        std::cerr << "无法读取配置文件。" << std::endl;
        config_destroy(&cfg);
        return;
    }

    // 查找设置项
    config_setting_t *setting = config_lookup(&cfg, path.c_str());
    if (setting) {
        // 更新设置项的值
        if (config_setting_set_string(setting, value.c_str())) {
            std::cout << "设置 " << path << " 为 " << value << std::endl;
        } else {
            std::cerr << "无法更新设置项 " << path << std::endl;
        }
    } else {
        std::cerr << "未找到配置项 " << path << "，无法修改。" << std::endl;
    }

    // 保存配置文件
    if (!config_write_file(&cfg, filename)) {
        std::cerr << "无法保存配置文件。" << std::endl;
    }

    config_destroy(&cfg);
}

void Configuration::set_ip_address(const char* ip_address) {
    const char* interface = "usb0";
    const char* netmask = "255.255.255.0";
    char command[256];
    snprintf(command, sizeof(command), "ifconfig %s %s netmask %s up", interface, ip_address, netmask);
    int result = system(command);
    if (result != 0) {
        std::cerr << "设置IP地址失败: " << result << std::endl;
    }
}

void Configuration::disp_set_brightness(int brightness) {
    int ioctlParam[3]={0};
    if (brightness < 20 || brightness > 255) {
        std::cerr << "brightness不正确 "<< std::endl;
        return;
    }

//    /*打印旧的背光值*/
//    std::cout << "旧的背光亮度为: " << ioctl(disp_fd,DISP_LCD_GET_BRIGHTNESS,ioctlParam) << std::endl;

    ioctlParam[0] = 0;
    ioctlParam[1] = brightness; // 背光亮度值

    int ret = ioctl(disp_fd, DISP_LCD_SET_BRIGHTNESS, ioctlParam);
    if (ret < 0) {
        std::cerr << "背光写入失败 "<< std::endl;
    }
}

void Configuration::Backlight_destruction() {
    if (disp_fd >= 0) {
        close(disp_fd);
    }
}

uint32_t Configuration::generate_uuid_from_mac() {
    std::ifstream iface_file("/sys/class/net/usb0/address");
    std::string mac_address;
    uint32_t uuid = 0;

    if (iface_file.is_open()) {
        std::getline(iface_file, mac_address);
        iface_file.close();
    }

    // 如果没有读取到 MAC 地址，可以考虑返回一个默认值或抛出异常
    if (mac_address.empty()) {
        mac_address = "00:00:00:00:00:00";
    }

    std::istringstream ss(mac_address);
    std::string token;
    while (std::getline(ss, token, ':')) {
        uuid ^= static_cast<uint32_t>(std::stoul(token, nullptr, 16));
        uuid <<= 4;  // 左移以确保每个 MAC 地址的部分对最终的 UUID 有影响
    }

    return uuid;
}