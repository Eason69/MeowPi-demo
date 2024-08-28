#include <fstream>
#include "lvgl_display.h"

extern std::atomic<bool> is_stop;

Lvgl::Lvgl() = default;

Lvgl::~Lvgl() = default;

void Lvgl::lvglStart() {
    display_thread_ = std::thread([this] { display(); });
}

void Lvgl::lvglJoin() {
    if (display_thread_.joinable()) {
        display_thread_.join();
    }
}

void Lvgl::display() {
    lv_init();
    uint32_t rotated = LV_DISP_ROT_NONE;
    sunxifb_init(rotated);
    static uint32_t width, height;
    sunxifb_get_sizes(&width, &height);
    static lv_color_t *buf1,*buf2;
    buf1 = (lv_color_t*) malloc(width * height * sizeof (lv_color_t));
    buf2 = (lv_color_t*) malloc(width * height * sizeof (lv_color_t));

    static lv_disp_draw_buf_t disp_buf;
    lv_disp_draw_buf_init(&disp_buf, buf1, buf2, width * height);
    static lv_disp_drv_t disp_drv;
    lv_disp_drv_init(&disp_drv);
    disp_drv.draw_buf   = &disp_buf;
    disp_drv.flush_cb   = sunxifb_flush;
    disp_drv.hor_res    = width;
    disp_drv.ver_res    = height;
    disp_drv.rotated    = rotated;
    lv_disp_drv_register(&disp_drv);
    evdev_init();
    static lv_indev_drv_t indev_drv_1;
    lv_indev_drv_init(&indev_drv_1); /*Basic initialization*/
    indev_drv_1.type = LV_INDEV_TYPE_POINTER;
    indev_drv_1.read_cb = evdev_read;
    lv_indev_t *mouse_indev = lv_indev_drv_register(&indev_drv_1);

    //lv_demo_music(); //音乐demo
    ui_init();
    parameter_set();

    while(!is_stop) {
        lv_timer_handler();
        std::this_thread::sleep_for(std::chrono::milliseconds(5));
    }
}

void Lvgl::parameter_set(){
    //壁纸
    switch (Configuration::GetInstance().config_wallpaper) {
        case 1 :
            lv_img_set_src(ui_Image20, &ui_img_wallpaper1_png);
            break;
        case 2 :
            lv_img_set_src(ui_Image20, &ui_img_wallpaper2_png);
            break;
        case 3 :
            lv_img_set_src(ui_Image20, &ui_img_wallpaper3_png);
            break;
        case 4 :
            lv_img_set_src(ui_Image20, &ui_img_wallpaper4_png);
            break;
        case 5 :
            lv_img_set_src(ui_Image20, &ui_img_wallpaper5_png);
            break;
        case 6 :
            lv_img_set_src(ui_Image20, &ui_img_wallpaper6_png);
            break;
        default :
            break;
    }
    //ip
    int segment1, segment2, segment3, segment4;
    sscanf(Configuration::GetInstance().config_ip, "%d.%d.%d.%d", &segment1, &segment2, &segment3, &segment4);
    lv_roller_set_selected(ui_Roller1, segment3, LV_ANIM_OFF);
    lv_roller_set_selected(ui_Roller3, segment4, LV_ANIM_OFF);
    //按钮
    lv_obj_set_style_bg_color(ui_Button1, lv_color_hex(0x87CEFA), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_Button3, lv_color_hex(0x87CEFA), LV_PART_MAIN | LV_STATE_DEFAULT);
    //亮度
    lv_slider_set_value(ui_Slider1, Configuration::GetInstance().config_bg, LV_ANIM_OFF);

    //KMBOX IP
    lv_label_set_text(ui_Label5, Configuration::GetInstance().config_ip);
    //KMBOX PORT
    std::string str_port = std::to_string(Configuration::GetInstance().config_kmport);
    const char* cstr_port = str_port.c_str();
    lv_textarea_set_text(ui_TextArea2, cstr_port);
    //KMBOX UUID
    uint32_t uuid = Configuration::GetInstance().uuid;
    std::stringstream ss_uuid;
    ss_uuid << std::hex << std::setw(8) << std::setfill('0') << uuid;
    std::string str_uuid = ss_uuid.str();
    const char* cstr_uuid = str_uuid.c_str();
    lv_label_set_text(ui_Label33, cstr_uuid);
    std::cout << "UUID as uint32_t: " << std::hex << std::setw(8) << std::setfill('0') << cstr_uuid << std::endl;
}

