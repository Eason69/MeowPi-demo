// This file was generated by SquareLine Studio
// SquareLine Studio version: SquareLine Studio 1.4.0
// LVGL version: 8.3.11
// Project name: SquareLine_Project

#include "ui.h"


const ui_theme_variable_t _ui_theme_color_white[1] = {0xFFFFFF};
const ui_theme_variable_t _ui_theme_alpha_white[1] = {255};

const ui_theme_variable_t _ui_theme_color_ash[1] = {0x7B7B7B};
const ui_theme_variable_t _ui_theme_alpha_ash[1] = {255};

const ui_theme_variable_t _ui_theme_color_buttbg[1] = {0x1B5585};
const ui_theme_variable_t _ui_theme_alpha_buttbg[1] = {255};

const ui_theme_variable_t _ui_theme_color_BackgroundGrey[1] = {0xD5D5D5};
const ui_theme_variable_t _ui_theme_alpha_BackgroundGrey[1] = {255};
uint8_t ui_theme_idx = UI_THEME_DEFAULT;


void ui_theme_set(uint8_t theme_idx)
{
    ui_theme_idx = theme_idx;
    _ui_theme_set_variable_styles(UI_VARIABLE_STYLES_MODE_FOLLOW);
}

