// This file was generated by SquareLine Studio
// SquareLine Studio version: SquareLine Studio 1.4.0
// LVGL version: 8.3.11
// Project name: SquareLine_Project

#include "../ui.h"

void ui_ScreenSetUpdate_screen_init(void)
{
    ui_ScreenSetUpdate = lv_obj_create(NULL);
    lv_obj_clear_flag(ui_ScreenSetUpdate, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_flex_flow(ui_ScreenSetUpdate, LV_FLEX_FLOW_ROW_WRAP);
    lv_obj_set_flex_align(ui_ScreenSetUpdate, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER);
    ui_object_set_themeable_style_property(ui_ScreenSetUpdate, LV_PART_MAIN | LV_STATE_DEFAULT, LV_STYLE_BG_COLOR,
                                           _ui_theme_color_BackgroundGrey);
    ui_object_set_themeable_style_property(ui_ScreenSetUpdate, LV_PART_MAIN | LV_STATE_DEFAULT, LV_STYLE_BG_OPA,
                                           _ui_theme_alpha_BackgroundGrey);
    lv_obj_set_style_pad_left(ui_ScreenSetUpdate, 80, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui_ScreenSetUpdate, 80, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui_ScreenSetUpdate, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui_ScreenSetUpdate, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_row(ui_ScreenSetUpdate, 30, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_column(ui_ScreenSetUpdate, 40, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Label7 = lv_label_create(ui_ScreenSetUpdate);
    lv_obj_set_width(ui_Label7, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Label7, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_Label7, 0);
    lv_obj_set_y(ui_Label7, -340);
    lv_obj_set_align(ui_Label7, LV_ALIGN_CENTER);
    lv_label_set_text(ui_Label7, "更新");
    lv_obj_add_flag(ui_Label7, LV_OBJ_FLAG_IGNORE_LAYOUT);     /// Flags
    lv_obj_set_style_text_font(ui_Label7, &ui_font_FontChina48, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Label37 = lv_label_create(ui_ScreenSetUpdate);
    lv_obj_set_width(ui_Label37, 320);
    lv_obj_set_height(ui_Label37, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_Label37, -70);
    lv_obj_set_y(ui_Label37, -302);
    lv_obj_set_align(ui_Label37, LV_ALIGN_CENTER);
    lv_label_set_text(ui_Label37,
                      "请打开网页开关后，在浏览器输入喵喵派的IP地址进行固件上传。（开发中）");
    lv_obj_set_style_text_font(ui_Label37, &ui_font_FontChina24, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Label38 = lv_label_create(ui_ScreenSetUpdate);
    lv_obj_set_width(ui_Label38, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Label38, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_Label38, -60);
    lv_obj_set_y(ui_Label38, 0);
    lv_obj_set_align(ui_Label38, LV_ALIGN_CENTER);
    lv_label_set_text(ui_Label38, "网页开关");
    lv_obj_set_style_text_font(ui_Label38, &ui_font_FontChina24, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Switch3 = lv_switch_create(ui_ScreenSetUpdate);
    lv_obj_set_width(ui_Switch3, 100);
    lv_obj_set_height(ui_Switch3, 50);
    lv_obj_set_x(ui_Switch3, 1);
    lv_obj_set_y(ui_Switch3, 249);
    lv_obj_set_align(ui_Switch3, LV_ALIGN_CENTER);
    lv_obj_add_state(ui_Switch3, LV_STATE_CHECKED);       /// States


    ui_Label43 = lv_label_create(ui_ScreenSetUpdate);
    lv_obj_set_width(ui_Label43, 320);
    lv_obj_set_height(ui_Label43, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_Label43, -70);
    lv_obj_set_y(ui_Label43, -302);
    lv_obj_set_align(ui_Label43, LV_ALIGN_CENTER);
    lv_label_set_text(ui_Label43, "请点击确定后刷入键鼠输出固件。");
    lv_obj_set_style_text_font(ui_Label43, &ui_font_FontChina24, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Label40 = lv_label_create(ui_ScreenSetUpdate);
    lv_obj_set_width(ui_Label40, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Label40, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_Label40, 21);
    lv_obj_set_y(ui_Label40, 147);
    lv_obj_set_align(ui_Label40, LV_ALIGN_CENTER);
    lv_label_set_text(ui_Label40, "键鼠输出");
    lv_obj_set_style_text_color(ui_Label40, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_Label40, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_Label40, &ui_font_FontChina24, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Button6 = lv_btn_create(ui_ScreenSetUpdate);
    lv_obj_set_width(ui_Button6, 120);
    lv_obj_set_height(ui_Button6, 80);
    lv_obj_set_x(ui_Button6, -257);
    lv_obj_set_y(ui_Button6, 669);
    lv_obj_set_align(ui_Button6, LV_ALIGN_CENTER);
    lv_obj_set_flex_flow(ui_Button6, LV_FLEX_FLOW_ROW);
    lv_obj_set_flex_align(ui_Button6, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER);
    lv_obj_add_flag(ui_Button6, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_Button6, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_Button6, 30, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_Button6, lv_color_hex(0x71C8F8), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Button6, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Label42 = lv_label_create(ui_Button6);
    lv_obj_set_width(ui_Label42, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Label42, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_Label42, 21);
    lv_obj_set_y(ui_Label42, 147);
    lv_obj_set_align(ui_Label42, LV_ALIGN_CENTER);
    lv_label_set_text(ui_Label42, "确定");
    lv_obj_set_style_text_color(ui_Label42, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_Label42, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_Label42, &ui_font_FontChina24, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Label44 = lv_label_create(ui_ScreenSetUpdate);
    lv_obj_set_width(ui_Label44, 320);
    lv_obj_set_height(ui_Label44, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_Label44, -70);
    lv_obj_set_y(ui_Label44, -302);
    lv_obj_set_align(ui_Label44, LV_ALIGN_CENTER);
    lv_label_set_text(ui_Label44, "更多信息请查看说明书");
    lv_obj_set_style_text_font(ui_Label44, &ui_font_FontChina24, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_add_event_cb(ui_Button6, ui_event_Button6, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_ScreenSetUpdate, ui_event_ScreenSetUpdate, LV_EVENT_ALL, NULL);

}
