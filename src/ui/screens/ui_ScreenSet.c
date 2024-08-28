// This file was generated by SquareLine Studio
// SquareLine Studio version: SquareLine Studio 1.4.0
// LVGL version: 8.3.11
// Project name: SquareLine_Project

#include "../ui.h"

void ui_ScreenSet_screen_init(void)
{
    ui_ScreenSet = lv_obj_create(NULL);
    lv_obj_clear_flag(ui_ScreenSet, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_flex_flow(ui_ScreenSet, LV_FLEX_FLOW_COLUMN);
    lv_obj_set_flex_align(ui_ScreenSet, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER);
    ui_object_set_themeable_style_property(ui_ScreenSet, LV_PART_MAIN | LV_STATE_DEFAULT, LV_STYLE_BG_COLOR,
                                           _ui_theme_color_BackgroundGrey);
    ui_object_set_themeable_style_property(ui_ScreenSet, LV_PART_MAIN | LV_STATE_DEFAULT, LV_STYLE_BG_OPA,
                                           _ui_theme_alpha_BackgroundGrey);
    lv_obj_set_style_pad_left(ui_ScreenSet, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui_ScreenSet, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui_ScreenSet, 40, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui_ScreenSet, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_row(ui_ScreenSet, 20, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_column(ui_ScreenSet, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Label8 = lv_label_create(ui_ScreenSet);
    lv_obj_set_width(ui_Label8, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Label8, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_Label8, -160);
    lv_obj_set_y(ui_Label8, -360);
    lv_obj_set_align(ui_Label8, LV_ALIGN_CENTER);
    lv_label_set_text(ui_Label8, "设置");
    lv_obj_set_style_text_font(ui_Label8, &ui_font_FontChina48, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Panel9 = lv_obj_create(ui_ScreenSet);
    lv_obj_set_width(ui_Panel9, 400);
    lv_obj_set_height(ui_Panel9, 80);
    lv_obj_set_x(ui_Panel9, 6);
    lv_obj_set_y(ui_Panel9, -264);
    lv_obj_set_align(ui_Panel9, LV_ALIGN_CENTER);
    lv_obj_set_flex_flow(ui_Panel9, LV_FLEX_FLOW_ROW);
    lv_obj_set_flex_align(ui_Panel9, LV_FLEX_ALIGN_SPACE_BETWEEN, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER);
    lv_obj_clear_flag(ui_Panel9, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_Panel9, 20, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Label10 = lv_label_create(ui_Panel9);
    lv_obj_set_width(ui_Label10, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Label10, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_Label10, -148);
    lv_obj_set_y(ui_Label10, 0);
    lv_obj_set_align(ui_Label10, LV_ALIGN_CENTER);
    lv_label_set_text(ui_Label10, "壁纸");
    lv_obj_set_style_text_font(ui_Label10, &ui_font_FontChina24, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Image11 = lv_img_create(ui_Panel9);
    lv_img_set_src(ui_Image11, &ui_img_arrow_png);
    lv_obj_set_width(ui_Image11, LV_SIZE_CONTENT);   /// 48
    lv_obj_set_height(ui_Image11, LV_SIZE_CONTENT);    /// 48
    lv_obj_set_align(ui_Image11, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_Image11, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_Image11, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_Panel11 = lv_obj_create(ui_ScreenSet);
    lv_obj_set_width(ui_Panel11, 400);
    lv_obj_set_height(ui_Panel11, 80);
    lv_obj_set_x(ui_Panel11, 6);
    lv_obj_set_y(ui_Panel11, -264);
    lv_obj_set_align(ui_Panel11, LV_ALIGN_CENTER);
    lv_obj_set_flex_flow(ui_Panel11, LV_FLEX_FLOW_ROW);
    lv_obj_set_flex_align(ui_Panel11, LV_FLEX_ALIGN_SPACE_BETWEEN, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER);
    lv_obj_clear_flag(ui_Panel11, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_Panel11, 20, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Label12 = lv_label_create(ui_Panel11);
    lv_obj_set_width(ui_Label12, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Label12, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_Label12, -148);
    lv_obj_set_y(ui_Label12, 0);
    lv_obj_set_align(ui_Label12, LV_ALIGN_CENTER);
    lv_label_set_text(ui_Label12, "IP");
    lv_obj_set_style_text_font(ui_Label12, &ui_font_FontChina24, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Image13 = lv_img_create(ui_Panel11);
    lv_img_set_src(ui_Image13, &ui_img_arrow_png);
    lv_obj_set_width(ui_Image13, LV_SIZE_CONTENT);   /// 48
    lv_obj_set_height(ui_Image13, LV_SIZE_CONTENT);    /// 48
    lv_obj_set_align(ui_Image13, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_Image13, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_Image13, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_Panel13 = lv_obj_create(ui_ScreenSet);
    lv_obj_set_width(ui_Panel13, 400);
    lv_obj_set_height(ui_Panel13, 80);
    lv_obj_set_x(ui_Panel13, 6);
    lv_obj_set_y(ui_Panel13, -264);
    lv_obj_set_align(ui_Panel13, LV_ALIGN_CENTER);
    lv_obj_set_flex_flow(ui_Panel13, LV_FLEX_FLOW_ROW);
    lv_obj_set_flex_align(ui_Panel13, LV_FLEX_ALIGN_SPACE_BETWEEN, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER);
    lv_obj_clear_flag(ui_Panel13, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_Panel13, 20, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Label14 = lv_label_create(ui_Panel13);
    lv_obj_set_width(ui_Label14, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Label14, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_Label14, -148);
    lv_obj_set_y(ui_Label14, 0);
    lv_obj_set_align(ui_Label14, LV_ALIGN_CENTER);
    lv_label_set_text(ui_Label14, "手势");
    lv_obj_set_style_text_font(ui_Label14, &ui_font_FontChina24, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Image15 = lv_img_create(ui_Panel13);
    lv_img_set_src(ui_Image15, &ui_img_arrow_png);
    lv_obj_set_width(ui_Image15, LV_SIZE_CONTENT);   /// 48
    lv_obj_set_height(ui_Image15, LV_SIZE_CONTENT);    /// 48
    lv_obj_set_align(ui_Image15, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_Image15, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_Image15, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_Panel12 = lv_obj_create(ui_ScreenSet);
    lv_obj_set_width(ui_Panel12, 400);
    lv_obj_set_height(ui_Panel12, 80);
    lv_obj_set_x(ui_Panel12, 6);
    lv_obj_set_y(ui_Panel12, -264);
    lv_obj_set_align(ui_Panel12, LV_ALIGN_CENTER);
    lv_obj_set_flex_flow(ui_Panel12, LV_FLEX_FLOW_ROW);
    lv_obj_set_flex_align(ui_Panel12, LV_FLEX_ALIGN_SPACE_BETWEEN, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER);
    lv_obj_clear_flag(ui_Panel12, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_Panel12, 20, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Label13 = lv_label_create(ui_Panel12);
    lv_obj_set_width(ui_Label13, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Label13, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_Label13, -148);
    lv_obj_set_y(ui_Label13, 0);
    lv_obj_set_align(ui_Label13, LV_ALIGN_CENTER);
    lv_label_set_text(ui_Label13, "关于");
    lv_obj_set_style_text_font(ui_Label13, &ui_font_FontChina24, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Image14 = lv_img_create(ui_Panel12);
    lv_img_set_src(ui_Image14, &ui_img_arrow_png);
    lv_obj_set_width(ui_Image14, LV_SIZE_CONTENT);   /// 48
    lv_obj_set_height(ui_Image14, LV_SIZE_CONTENT);    /// 48
    lv_obj_set_align(ui_Image14, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_Image14, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_Image14, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    lv_obj_add_event_cb(ui_Panel9, ui_event_Panel9, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_Panel11, ui_event_Panel11, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_Panel13, ui_event_Panel13, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_Panel12, ui_event_Panel12, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_ScreenSet, ui_event_ScreenSet, LV_EVENT_ALL, NULL);

}
