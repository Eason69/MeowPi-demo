// This file was generated by SquareLine Studio
// SquareLine Studio version: SquareLine Studio 1.4.0
// LVGL version: 8.3.11
// Project name: SquareLine_Project

#include "ui.h"
#include "ui_helpers.h"
#include "wrapper.h"

///////////////////// VARIABLES ////////////////////
void LOGO_Animation(lv_obj_t * TargetObject, int delay);
void dropdown_Animation(lv_obj_t * TargetObject, int delay);
void deopupward_Animation(lv_obj_t * TargetObject, int delay);
void dropbutton_Animation(lv_obj_t * TargetObject, int delay);
void gesture_Animation(lv_obj_t * TargetObject, int delay);


// SCREEN: ui_ScreenLOGO
void ui_ScreenLOGO_screen_init(void);
void ui_event_ScreenLOGO(lv_event_t * e);
lv_obj_t * ui_ScreenLOGO;
lv_obj_t * ui_Image3;


// SCREEN: ui_ScreenHome
void ui_ScreenHome_screen_init(void);
void ui_event_ScreenHome(lv_event_t * e);
lv_obj_t * ui_ScreenHome;
lv_obj_t * ui_Image20;
lv_obj_t * ui_Panel3;
void ui_event_Panel1(lv_event_t * e);
lv_obj_t * ui_Panel1;
lv_obj_t * ui_Image1;
lv_obj_t * ui_Label1;
lv_obj_t * ui_Panel5;
lv_obj_t * ui_Image4;
lv_obj_t * ui_Label4;
void ui_event_Panel7(lv_event_t * e);
lv_obj_t * ui_Panel7;
lv_obj_t * ui_Image5;
lv_obj_t * ui_Label36;
lv_obj_t * ui_Panel4;
lv_obj_t * ui_Bar1;
void ui_event_Button1(lv_event_t * e);
lv_obj_t * ui_Button1;
lv_obj_t * ui_Image8;
lv_obj_t * ui_Label3;
void ui_event_Button3(lv_event_t * e);
lv_obj_t * ui_Button3;
lv_obj_t * ui_Image10;
lv_obj_t * ui_Label9;
lv_obj_t * ui_Image9;
lv_obj_t * ui_Slider1;


// SCREEN: ui_ScreenSet
void ui_ScreenSet_screen_init(void);
void ui_event_ScreenSet(lv_event_t * e);
lv_obj_t * ui_ScreenSet;
lv_obj_t * ui_Label8;
void ui_event_Panel9(lv_event_t * e);
lv_obj_t * ui_Panel9;
lv_obj_t * ui_Label10;
lv_obj_t * ui_Image11;
void ui_event_Panel11(lv_event_t * e);
lv_obj_t * ui_Panel11;
lv_obj_t * ui_Label12;
lv_obj_t * ui_Image13;
void ui_event_Panel13(lv_event_t * e);
lv_obj_t * ui_Panel13;
lv_obj_t * ui_Label14;
lv_obj_t * ui_Image15;
void ui_event_Panel12(lv_event_t * e);
lv_obj_t * ui_Panel12;
lv_obj_t * ui_Label13;
lv_obj_t * ui_Image14;


// SCREEN: ui_ScreenSetWallpaper
void ui_ScreenSetWallpaper_screen_init(void);
void ui_event_ScreenSetWallpaper(lv_event_t * e);
lv_obj_t * ui_ScreenSetWallpaper;
lv_obj_t * ui_Label11;
void ui_event_Image2(lv_event_t * e);
lv_obj_t * ui_Image2;
void ui_event_Image7(lv_event_t * e);
lv_obj_t * ui_Image7;
void ui_event_Image12(lv_event_t * e);
lv_obj_t * ui_Image12;
void ui_event_Image17(lv_event_t * e);
lv_obj_t * ui_Image17;
void ui_event_Image18(lv_event_t * e);
lv_obj_t * ui_Image18;
void ui_event_Image19(lv_event_t * e);
lv_obj_t * ui_Image19;


// SCREEN: ui_ScreenSetIP
void ui_ScreenSetIP_screen_init(void);
void ui_event_ScreenSetIP(lv_event_t * e);
lv_obj_t * ui_ScreenSetIP;
lv_obj_t * ui_Label15;
lv_obj_t * ui_Label16;
lv_obj_t * ui_Roller1;
lv_obj_t * ui_Label18;
lv_obj_t * ui_Roller3;
void ui_event_Button2(lv_event_t * e);
lv_obj_t * ui_Button2;
lv_obj_t * ui_Label17;


// SCREEN: ui_ScreenSetGesture
void ui_ScreenSetGesture_screen_init(void);
void ui_event_ScreenSetGesture(lv_event_t * e);
lv_obj_t * ui_ScreenSetGesture;
lv_obj_t * ui_Label19;
lv_obj_t * ui_Image16;
lv_obj_t * ui_Label20;


// SCREEN: ui_ScreenSetabout
void ui_ScreenSetabout_screen_init(void);
void ui_event_ScreenSetabout(lv_event_t * e);
lv_obj_t * ui_ScreenSetabout;
lv_obj_t * ui_Label22;
lv_obj_t * ui_Image24;
lv_obj_t * ui_Panel14;
lv_obj_t * ui_Label21;
lv_obj_t * ui_Label24;
lv_obj_t * ui_Label25;
lv_obj_t * ui_Label26;
lv_obj_t * ui_Label27;
lv_obj_t * ui_Label28;
lv_obj_t * ui_Label29;
lv_obj_t * ui_Label30;
lv_obj_t * ui_Label31;
lv_obj_t * ui_Label32;


// SCREEN: ui_ScreenKMBOX
void ui_ScreenKMBOX_screen_init(void);
void ui_event_ScreenKMBOX(lv_event_t * e);
lv_obj_t * ui_ScreenKMBOX;
lv_obj_t * ui_Label2;
lv_obj_t * ui_Panel6;
lv_obj_t * ui_Label39;
lv_obj_t * ui_Label5;
lv_obj_t * ui_Label6;
void ui_event_TextArea2(lv_event_t * e);
lv_obj_t * ui_TextArea2;
lv_obj_t * ui_Label23;
lv_obj_t * ui_Label33;
lv_obj_t * ui_Label34;
lv_obj_t * ui_Roller2;
lv_obj_t * ui_Switch1;
void ui_event_Keyboard2(lv_event_t * e);
lv_obj_t * ui_Keyboard2;
lv_obj_t * ui____initial_actions0;
const lv_img_dsc_t * ui_imgset_small[6] = {&ui_img_small1_png, &ui_img_small2_png, &ui_img_small3_png, &ui_img_small4_png, &ui_img_small5_png, &ui_img_small6_png};
const lv_img_dsc_t * ui_imgset_wallpaper[6] = {&ui_img_wallpaper1_png, &ui_img_wallpaper2_png, &ui_img_wallpaper3_png, &ui_img_wallpaper4_png, &ui_img_wallpaper5_png, &ui_img_wallpaper6_png};

///////////////////// TEST LVGL SETTINGS ////////////////////
#if LV_COLOR_DEPTH != 32
    #error "LV_COLOR_DEPTH should be 32bit to match SquareLine Studio's settings"
#endif
#if LV_COLOR_16_SWAP !=0
    #error "LV_COLOR_16_SWAP should be 0 to match SquareLine Studio's settings"
#endif

///////////////////// ANIMATIONS ////////////////////
void LOGO_Animation(lv_obj_t * TargetObject, int delay)
{
    ui_anim_user_data_t * PropertyAnimation_0_user_data = lv_mem_alloc(sizeof(ui_anim_user_data_t));
    PropertyAnimation_0_user_data->target = TargetObject;
    PropertyAnimation_0_user_data->val = -1;
    lv_anim_t PropertyAnimation_0;
    lv_anim_init(&PropertyAnimation_0);
    lv_anim_set_time(&PropertyAnimation_0, 800);
    lv_anim_set_user_data(&PropertyAnimation_0, PropertyAnimation_0_user_data);
    lv_anim_set_custom_exec_cb(&PropertyAnimation_0, _ui_anim_callback_set_image_zoom);
    lv_anim_set_values(&PropertyAnimation_0, 0, 320);
    lv_anim_set_path_cb(&PropertyAnimation_0, lv_anim_path_ease_in);
    lv_anim_set_delay(&PropertyAnimation_0, delay + 0);
    lv_anim_set_deleted_cb(&PropertyAnimation_0, _ui_anim_callback_free_user_data);
    lv_anim_set_playback_time(&PropertyAnimation_0, 0);
    lv_anim_set_playback_delay(&PropertyAnimation_0, 0);
    lv_anim_set_repeat_count(&PropertyAnimation_0, 0);
    lv_anim_set_repeat_delay(&PropertyAnimation_0, 0);
    lv_anim_set_early_apply(&PropertyAnimation_0, false);
    lv_anim_set_get_value_cb(&PropertyAnimation_0, &_ui_anim_callback_get_image_zoom);
    lv_anim_start(&PropertyAnimation_0);
    ui_anim_user_data_t * PropertyAnimation_1_user_data = lv_mem_alloc(sizeof(ui_anim_user_data_t));
    PropertyAnimation_1_user_data->target = TargetObject;
    PropertyAnimation_1_user_data->val = -1;
    lv_anim_t PropertyAnimation_1;
    lv_anim_init(&PropertyAnimation_1);
    lv_anim_set_time(&PropertyAnimation_1, 800);
    lv_anim_set_user_data(&PropertyAnimation_1, PropertyAnimation_1_user_data);
    lv_anim_set_custom_exec_cb(&PropertyAnimation_1, _ui_anim_callback_set_opacity);
    lv_anim_set_values(&PropertyAnimation_1, 255, 100);
    lv_anim_set_path_cb(&PropertyAnimation_1, lv_anim_path_linear);
    lv_anim_set_delay(&PropertyAnimation_1, delay + 0);
    lv_anim_set_deleted_cb(&PropertyAnimation_1, _ui_anim_callback_free_user_data);
    lv_anim_set_playback_time(&PropertyAnimation_1, 0);
    lv_anim_set_playback_delay(&PropertyAnimation_1, 0);
    lv_anim_set_repeat_count(&PropertyAnimation_1, 0);
    lv_anim_set_repeat_delay(&PropertyAnimation_1, 0);
    lv_anim_set_early_apply(&PropertyAnimation_1, false);
    lv_anim_set_get_value_cb(&PropertyAnimation_1, &_ui_anim_callback_get_opacity);
    lv_anim_start(&PropertyAnimation_1);

}
void dropdown_Animation(lv_obj_t * TargetObject, int delay)
{
    ui_anim_user_data_t * PropertyAnimation_0_user_data = lv_mem_alloc(sizeof(ui_anim_user_data_t));
    PropertyAnimation_0_user_data->target = TargetObject;
    PropertyAnimation_0_user_data->val = -1;
    lv_anim_t PropertyAnimation_0;
    lv_anim_init(&PropertyAnimation_0);
    lv_anim_set_time(&PropertyAnimation_0, 800);
    lv_anim_set_user_data(&PropertyAnimation_0, PropertyAnimation_0_user_data);
    lv_anim_set_custom_exec_cb(&PropertyAnimation_0, _ui_anim_callback_set_y);
    lv_anim_set_values(&PropertyAnimation_0, -770, 0);
    lv_anim_set_path_cb(&PropertyAnimation_0, lv_anim_path_linear);
    lv_anim_set_delay(&PropertyAnimation_0, delay + 0);
    lv_anim_set_deleted_cb(&PropertyAnimation_0, _ui_anim_callback_free_user_data);
    lv_anim_set_playback_time(&PropertyAnimation_0, 0);
    lv_anim_set_playback_delay(&PropertyAnimation_0, 0);
    lv_anim_set_repeat_count(&PropertyAnimation_0, 0);
    lv_anim_set_repeat_delay(&PropertyAnimation_0, 0);
    lv_anim_set_early_apply(&PropertyAnimation_0, false);
    lv_anim_start(&PropertyAnimation_0);

}
void deopupward_Animation(lv_obj_t * TargetObject, int delay)
{
    ui_anim_user_data_t * PropertyAnimation_0_user_data = lv_mem_alloc(sizeof(ui_anim_user_data_t));
    PropertyAnimation_0_user_data->target = TargetObject;
    PropertyAnimation_0_user_data->val = -1;
    lv_anim_t PropertyAnimation_0;
    lv_anim_init(&PropertyAnimation_0);
    lv_anim_set_time(&PropertyAnimation_0, 800);
    lv_anim_set_user_data(&PropertyAnimation_0, PropertyAnimation_0_user_data);
    lv_anim_set_custom_exec_cb(&PropertyAnimation_0, _ui_anim_callback_set_y);
    lv_anim_set_values(&PropertyAnimation_0, 0, -770);
    lv_anim_set_path_cb(&PropertyAnimation_0, lv_anim_path_linear);
    lv_anim_set_delay(&PropertyAnimation_0, delay + 0);
    lv_anim_set_deleted_cb(&PropertyAnimation_0, _ui_anim_callback_free_user_data);
    lv_anim_set_playback_time(&PropertyAnimation_0, 0);
    lv_anim_set_playback_delay(&PropertyAnimation_0, 0);
    lv_anim_set_repeat_count(&PropertyAnimation_0, 0);
    lv_anim_set_repeat_delay(&PropertyAnimation_0, 0);
    lv_anim_set_early_apply(&PropertyAnimation_0, false);
    lv_anim_start(&PropertyAnimation_0);

}
void dropbutton_Animation(lv_obj_t * TargetObject, int delay)
{
    ui_anim_user_data_t * PropertyAnimation_0_user_data = lv_mem_alloc(sizeof(ui_anim_user_data_t));
    PropertyAnimation_0_user_data->target = TargetObject;
    PropertyAnimation_0_user_data->val = -1;
    lv_anim_t PropertyAnimation_0;
    lv_anim_init(&PropertyAnimation_0);
    lv_anim_set_time(&PropertyAnimation_0, 800);
    lv_anim_set_user_data(&PropertyAnimation_0, PropertyAnimation_0_user_data);
    lv_anim_set_custom_exec_cb(&PropertyAnimation_0, _ui_anim_callback_set_image_angle);
    lv_anim_set_values(&PropertyAnimation_0, 0, 3600);
    lv_anim_set_path_cb(&PropertyAnimation_0, lv_anim_path_linear);
    lv_anim_set_delay(&PropertyAnimation_0, delay + 0);
    lv_anim_set_deleted_cb(&PropertyAnimation_0, _ui_anim_callback_free_user_data);
    lv_anim_set_playback_time(&PropertyAnimation_0, 0);
    lv_anim_set_playback_delay(&PropertyAnimation_0, 0);
    lv_anim_set_repeat_count(&PropertyAnimation_0, 0);
    lv_anim_set_repeat_delay(&PropertyAnimation_0, 0);
    lv_anim_set_early_apply(&PropertyAnimation_0, true);
    lv_anim_start(&PropertyAnimation_0);

}
void gesture_Animation(lv_obj_t * TargetObject, int delay)
{
    ui_anim_user_data_t * PropertyAnimation_0_user_data = lv_mem_alloc(sizeof(ui_anim_user_data_t));
    PropertyAnimation_0_user_data->target = TargetObject;
    PropertyAnimation_0_user_data->val = -1;
    lv_anim_t PropertyAnimation_0;
    lv_anim_init(&PropertyAnimation_0);
    lv_anim_set_time(&PropertyAnimation_0, 1000);
    lv_anim_set_user_data(&PropertyAnimation_0, PropertyAnimation_0_user_data);
    lv_anim_set_custom_exec_cb(&PropertyAnimation_0, _ui_anim_callback_set_x);
    lv_anim_set_values(&PropertyAnimation_0, -200, 0);
    lv_anim_set_path_cb(&PropertyAnimation_0, lv_anim_path_linear);
    lv_anim_set_delay(&PropertyAnimation_0, delay + 0);
    lv_anim_set_deleted_cb(&PropertyAnimation_0, _ui_anim_callback_free_user_data);
    lv_anim_set_playback_time(&PropertyAnimation_0, 0);
    lv_anim_set_playback_delay(&PropertyAnimation_0, 0);
    lv_anim_set_repeat_count(&PropertyAnimation_0, LV_ANIM_REPEAT_INFINITE);
    lv_anim_set_repeat_delay(&PropertyAnimation_0, 3000);
    lv_anim_set_early_apply(&PropertyAnimation_0, false);
    lv_anim_start(&PropertyAnimation_0);
    ui_anim_user_data_t * PropertyAnimation_1_user_data = lv_mem_alloc(sizeof(ui_anim_user_data_t));
    PropertyAnimation_1_user_data->target = TargetObject;
    PropertyAnimation_1_user_data->val = -1;
    lv_anim_t PropertyAnimation_1;
    lv_anim_init(&PropertyAnimation_1);
    lv_anim_set_time(&PropertyAnimation_1, 1000);
    lv_anim_set_user_data(&PropertyAnimation_1, PropertyAnimation_1_user_data);
    lv_anim_set_custom_exec_cb(&PropertyAnimation_1, _ui_anim_callback_set_x);
    lv_anim_set_values(&PropertyAnimation_1, 200, 0);
    lv_anim_set_path_cb(&PropertyAnimation_1, lv_anim_path_linear);
    lv_anim_set_delay(&PropertyAnimation_1, delay + 1500);
    lv_anim_set_deleted_cb(&PropertyAnimation_1, _ui_anim_callback_free_user_data);
    lv_anim_set_playback_time(&PropertyAnimation_1, 0);
    lv_anim_set_playback_delay(&PropertyAnimation_1, 0);
    lv_anim_set_repeat_count(&PropertyAnimation_1, LV_ANIM_REPEAT_INFINITE);
    lv_anim_set_repeat_delay(&PropertyAnimation_1, 3000);
    lv_anim_set_early_apply(&PropertyAnimation_1, false);
    lv_anim_start(&PropertyAnimation_1);

}

///////////////////// FUNCTIONS ////////////////////
bool is_Button3 = true;
bool is_Button1 = true;
void ui_event_Slider1(lv_event_t * e)
{
    lv_obj_t * slider = lv_event_get_target(e);
    int brightness = lv_slider_get_value(slider);
    wrapper_SetBrightness(brightness);
    wrapper_SetConfigValue("General.backlight",brightness);
}

void ui_event_Switch1(lv_event_t * e)
{
    lv_event_code_t code = lv_event_get_code(e);
    lv_obj_t * obj = lv_event_get_target(e);
    if(code == LV_EVENT_VALUE_CHANGED) {
        is_Button3 = lv_obj_has_state(obj, LV_STATE_CHECKED);
        if(is_Button3)
            lv_obj_set_style_bg_color(ui_Button3, lv_color_hex(0x87CEFA), LV_PART_MAIN | LV_STATE_DEFAULT);
        else
            lv_obj_set_style_bg_color(ui_Button3, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
        wrapper_KmnetManage(is_Button3);
    }
}

void ui_event_ScreenLOGO(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_SCREEN_LOADED) {
        _ui_screen_change(&ui_ScreenHome, LV_SCR_LOAD_ANIM_FADE_ON, 200, 800, &ui_ScreenHome_screen_init);
    }
    if(event_code == LV_EVENT_SCREEN_LOADED) {
        LOGO_Animation(ui_Image3, 100);
    }
}
void ui_event_ScreenHome(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_GESTURE &&  lv_indev_get_gesture_dir(lv_indev_get_act()) == LV_DIR_BOTTOM) {
        lv_indev_wait_release(lv_indev_get_act());
        dropdown_Animation(ui_Panel4, 0);
    }
    if(event_code == LV_EVENT_GESTURE &&  lv_indev_get_gesture_dir(lv_indev_get_act()) == LV_DIR_TOP) {
        lv_indev_wait_release(lv_indev_get_act());
        deopupward_Animation(ui_Panel4, 0);
    }
}
void ui_event_Panel1(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        _ui_screen_change(&ui_ScreenSet, LV_SCR_LOAD_ANIM_FADE_ON, 300, 0, &ui_ScreenSet_screen_init);
    }
}
void ui_event_Panel7(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        _ui_screen_change(&ui_ScreenKMBOX, LV_SCR_LOAD_ANIM_FADE_ON, 300, 0, &ui_ScreenKMBOX_screen_init);
    }
}

void ui_event_Button1(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        dropbutton_Animation(ui_Image8, 0);
        if(is_Button1) {
            is_Button1 = false;
            lv_obj_set_style_bg_color(ui_Button1, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
        }else{
            is_Button1 = true;
            lv_obj_set_style_bg_color(ui_Button1, lv_color_hex(0x87CEFA), LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        wrapper_KeyManage(is_Button1);
    }
}

void ui_event_Button3(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        dropbutton_Animation(ui_Image10, 0);
        if(is_Button3) {
            is_Button3 = false;
            lv_obj_set_style_bg_color(ui_Button3, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_clear_state(ui_Switch1, LV_STATE_CHECKED);
        }else{
            is_Button3 = true;
            lv_obj_set_style_bg_color(ui_Button3, lv_color_hex(0x87CEFA), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_add_state(ui_Switch1, LV_STATE_CHECKED);
        }
        wrapper_KmnetManage(is_Button3);
    }
}
void ui_event_ScreenSet(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_GESTURE &&  lv_indev_get_gesture_dir(lv_indev_get_act()) == LV_DIR_LEFT) {
        lv_indev_wait_release(lv_indev_get_act());
        _ui_screen_change(&ui_ScreenHome, LV_SCR_LOAD_ANIM_FADE_ON, 300, 0, &ui_ScreenHome_screen_init);
    }
    if(event_code == LV_EVENT_GESTURE &&  lv_indev_get_gesture_dir(lv_indev_get_act()) == LV_DIR_RIGHT) {
        lv_indev_wait_release(lv_indev_get_act());
        _ui_screen_change(&ui_ScreenHome, LV_SCR_LOAD_ANIM_FADE_ON, 300, 0, &ui_ScreenHome_screen_init);
    }
}
void ui_event_Panel9(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        _ui_screen_change(&ui_ScreenSetWallpaper, LV_SCR_LOAD_ANIM_MOVE_LEFT, 300, 0, &ui_ScreenSetWallpaper_screen_init);
    }
}
void ui_event_Panel11(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        _ui_screen_change(&ui_ScreenSetIP, LV_SCR_LOAD_ANIM_MOVE_LEFT, 300, 0, &ui_ScreenSetIP_screen_init);
    }
}
void ui_event_Panel13(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        _ui_screen_change(&ui_ScreenSetGesture, LV_SCR_LOAD_ANIM_MOVE_LEFT, 300, 0, &ui_ScreenSetGesture_screen_init);
    }
}
void ui_event_Panel12(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        _ui_screen_change(&ui_ScreenSetabout, LV_SCR_LOAD_ANIM_MOVE_LEFT, 300, 0, &ui_ScreenSetabout_screen_init);
    }
}
void ui_event_ScreenSetWallpaper(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_GESTURE &&  lv_indev_get_gesture_dir(lv_indev_get_act()) == LV_DIR_LEFT) {
        lv_indev_wait_release(lv_indev_get_act());
        _ui_screen_change(&ui_ScreenSet, LV_SCR_LOAD_ANIM_MOVE_RIGHT, 300, 0, &ui_ScreenSet_screen_init);
    }
    if(event_code == LV_EVENT_GESTURE &&  lv_indev_get_gesture_dir(lv_indev_get_act()) == LV_DIR_RIGHT) {
        lv_indev_wait_release(lv_indev_get_act());
        _ui_screen_change(&ui_ScreenSet, LV_SCR_LOAD_ANIM_MOVE_RIGHT, 300, 0, &ui_ScreenSet_screen_init);
    }
}
void ui_event_Image2(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        wrapper_SetConfigValue("General.wallpaper",1);
        _ui_image_set_property(ui_Image20, _UI_IMAGE_PROPERTY_IMAGE, & ui_img_wallpaper1_png);
        _ui_screen_change(&ui_ScreenHome, LV_SCR_LOAD_ANIM_FADE_ON, 300, 0, &ui_ScreenHome_screen_init);
    }
}
void ui_event_Image7(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        wrapper_SetConfigValue("General.wallpaper",2);
        _ui_image_set_property(ui_Image20, _UI_IMAGE_PROPERTY_IMAGE, & ui_img_wallpaper2_png);
        _ui_screen_change(&ui_ScreenHome, LV_SCR_LOAD_ANIM_FADE_ON, 300, 0, &ui_ScreenHome_screen_init);
    }
}
void ui_event_Image12(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        wrapper_SetConfigValue("General.wallpaper",3);
        _ui_image_set_property(ui_Image20, _UI_IMAGE_PROPERTY_IMAGE, & ui_img_wallpaper3_png);
        _ui_screen_change(&ui_ScreenHome, LV_SCR_LOAD_ANIM_FADE_ON, 300, 0, &ui_ScreenHome_screen_init);
    }
}
void ui_event_Image17(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        wrapper_SetConfigValue("General.wallpaper",4);
        _ui_image_set_property(ui_Image20, _UI_IMAGE_PROPERTY_IMAGE, & ui_img_wallpaper4_png);
        _ui_screen_change(&ui_ScreenHome, LV_SCR_LOAD_ANIM_FADE_ON, 300, 0, &ui_ScreenHome_screen_init);
    }
}
void ui_event_Image18(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        wrapper_SetConfigValue("General.wallpaper",5);
        _ui_image_set_property(ui_Image20, _UI_IMAGE_PROPERTY_IMAGE, & ui_img_wallpaper5_png);
        _ui_screen_change(&ui_ScreenHome, LV_SCR_LOAD_ANIM_FADE_ON, 300, 0, &ui_ScreenHome_screen_init);
    }
}
void ui_event_Image19(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        wrapper_SetConfigValue("General.wallpaper",6);
        _ui_image_set_property(ui_Image20, _UI_IMAGE_PROPERTY_IMAGE, & ui_img_wallpaper6_png);
        _ui_screen_change(&ui_ScreenHome, LV_SCR_LOAD_ANIM_FADE_ON, 300, 0, &ui_ScreenHome_screen_init);
    }
}
void ui_event_ScreenSetIP(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_GESTURE &&  lv_indev_get_gesture_dir(lv_indev_get_act()) == LV_DIR_LEFT) {
        lv_indev_wait_release(lv_indev_get_act());
        _ui_screen_change(&ui_ScreenSet, LV_SCR_LOAD_ANIM_MOVE_RIGHT, 300, 0, &ui_ScreenSet_screen_init);
    }
    if(event_code == LV_EVENT_GESTURE &&  lv_indev_get_gesture_dir(lv_indev_get_act()) == LV_DIR_RIGHT) {
        lv_indev_wait_release(lv_indev_get_act());
        _ui_screen_change(&ui_ScreenSet, LV_SCR_LOAD_ANIM_MOVE_RIGHT, 300, 0, &ui_ScreenSet_screen_init);
    }
}
void ui_event_Button2(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        _ui_screen_change(&ui_ScreenSet, LV_SCR_LOAD_ANIM_MOVE_RIGHT, 300, 0, &ui_ScreenSet_screen_init);
        wrapper_SetConfigIP(lv_roller_get_selected(ui_Roller1),lv_roller_get_selected(ui_Roller3));
    }
}
void ui_event_ScreenSetGesture(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_SCREEN_LOADED) {
        gesture_Animation(ui_Image16, 0);
    }
    if(event_code == LV_EVENT_GESTURE &&  lv_indev_get_gesture_dir(lv_indev_get_act()) == LV_DIR_LEFT) {
        lv_indev_wait_release(lv_indev_get_act());
        _ui_screen_change(&ui_ScreenSet, LV_SCR_LOAD_ANIM_MOVE_RIGHT, 300, 0, &ui_ScreenSet_screen_init);
    }
    if(event_code == LV_EVENT_GESTURE &&  lv_indev_get_gesture_dir(lv_indev_get_act()) == LV_DIR_RIGHT) {
        lv_indev_wait_release(lv_indev_get_act());
        _ui_screen_change(&ui_ScreenSet, LV_SCR_LOAD_ANIM_MOVE_RIGHT, 300, 0, &ui_ScreenSet_screen_init);
    }
}
void ui_event_ScreenSetabout(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_GESTURE &&  lv_indev_get_gesture_dir(lv_indev_get_act()) == LV_DIR_LEFT) {
        lv_indev_wait_release(lv_indev_get_act());
        _ui_screen_change(&ui_ScreenSet, LV_SCR_LOAD_ANIM_MOVE_RIGHT, 300, 0, &ui_ScreenSet_screen_init);
    }
    if(event_code == LV_EVENT_GESTURE &&  lv_indev_get_gesture_dir(lv_indev_get_act()) == LV_DIR_RIGHT) {
        lv_indev_wait_release(lv_indev_get_act());
        _ui_screen_change(&ui_ScreenSet, LV_SCR_LOAD_ANIM_MOVE_RIGHT, 300, 0, &ui_ScreenSet_screen_init);
    }
}
void ui_event_ScreenKMBOX(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_GESTURE &&  lv_indev_get_gesture_dir(lv_indev_get_act()) == LV_DIR_LEFT) {
        lv_indev_wait_release(lv_indev_get_act());
        _ui_screen_change(&ui_ScreenHome, LV_SCR_LOAD_ANIM_FADE_ON, 300, 0, &ui_ScreenHome_screen_init);
    }
    if(event_code == LV_EVENT_GESTURE &&  lv_indev_get_gesture_dir(lv_indev_get_act()) == LV_DIR_RIGHT) {
        lv_indev_wait_release(lv_indev_get_act());
        _ui_screen_change(&ui_ScreenHome, LV_SCR_LOAD_ANIM_FADE_ON, 300, 0, &ui_ScreenHome_screen_init);
    }
}
void ui_event_TextArea2(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        _ui_flag_modify(ui_Keyboard2, LV_OBJ_FLAG_HIDDEN, _UI_MODIFY_FLAG_REMOVE);
        _ui_state_modify(ui_TextArea2, LV_STATE_FOCUSED, _UI_MODIFY_STATE_ADD);
    }
}
void ui_event_Keyboard2(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_READY) {
        _ui_flag_modify(ui_Keyboard2, LV_OBJ_FLAG_HIDDEN, _UI_MODIFY_FLAG_ADD);
        _ui_state_modify(ui_TextArea2, LV_STATE_FOCUSED, _UI_MODIFY_STATE_REMOVE);
        wrapper_SetKmPort(lv_textarea_get_text(ui_TextArea2));
    }
}

///////////////////// SCREENS ////////////////////

void ui_init(void)
{
    lv_disp_t * dispp = lv_disp_get_default();
    lv_theme_t * theme = lv_theme_default_init(dispp, lv_palette_main(LV_PALETTE_BLUE), lv_palette_main(LV_PALETTE_RED),
                                               false, LV_FONT_DEFAULT);
    lv_disp_set_theme(dispp, theme);
    ui_ScreenLOGO_screen_init();
    ui_ScreenHome_screen_init();
    ui_ScreenSet_screen_init();
    ui_ScreenSetWallpaper_screen_init();
    ui_ScreenSetIP_screen_init();
    ui_ScreenSetGesture_screen_init();
    ui_ScreenSetabout_screen_init();
    ui_ScreenKMBOX_screen_init();
    ui____initial_actions0 = lv_obj_create(NULL);
    lv_disp_load_scr(ui_ScreenLOGO);
}