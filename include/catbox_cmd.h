#ifndef DEMO_CATBOX_CMD_H
#define DEMO_CATBOX_CMD_H

#include <unordered_map>
#include <set>

#define BUFFER_SIZE 1024

//兼容CATbox net的命令

//命令码
#define 	cmd_connect			0xaf3c2828 //ok连接盒子
#define     cmd_mouse_move		0xaede7345 //ok鼠标移动
#define		cmd_mouse_left		0x9823AE8D //ok鼠标左键控制
#define		cmd_mouse_middle	0x97a3AE8D //ok鼠标中键控制
#define		cmd_mouse_right		0x238d8212 //ok鼠标右键控制
#define		cmd_mouse_wheel		0xffeead38 //ok鼠标滚轮控制
#define     cmd_mouse_automove	0xaede7346 //ok鼠标自动模拟人工移动控制
#define     cmd_keyboard_all    0x123c2c2f //ok键盘所有参数控制
#define		cmd_reboot			0xaa8855aa //ok盒子重启
#define     cmd_bazerMove       0xa238455a //ok鼠标贝塞尔移动
#define     cmd_monitor         0x27388020 //ok监控盒子上的物理键鼠数据
#define     cmd_debug           0x27382021 //ok开启调试信息
#define     cmd_mask_mouse      0x23234343 //ok 屏蔽物理键鼠
#define     cmd_unmask_all      0x23344343 //ok 解除屏蔽物理键鼠
#define     cmd_setconfig       0x1d3d3323 //ok 设置IP配置信息
#define     cmd_showpic         0x12334883 //显示图片

typedef struct
{
    unsigned int  mac;			//盒子的mac地址（必须）
    unsigned int  rand;			//随机值
    unsigned int  indexpts;		//时间戳
    unsigned int  cmd;			//指令码
}cmd_head_t;

typedef struct
{
    unsigned char buff[1024];	//
}cmd_data_t;
typedef struct
{
    unsigned short buff[512];	//
}cmd_u16_t;

//鼠标数据结构体
typedef struct
{
    int button;
    int x;
    int y;
    int wheel;
    int point[10];//用于贝塞尔曲线控制(预留5阶导)
}soft_mouse_t;

//键盘数据结构体
typedef struct
{
    char ctrl;
    char resvel;
    char button[10];
}soft_keyboard_t;

//联合体
typedef struct
{
    cmd_head_t head;
    union {
        cmd_data_t      u8buff;		  //buff
        cmd_u16_t       u16buff;	  //U16
        soft_mouse_t    cmd_mouse;    //鼠标发送指令
        soft_keyboard_t cmd_keyboard; //键盘发送指令
    };
}client_tx;

#pragma pack(1)
typedef struct {
    uint8_t report_id;
    uint8_t buttons;		// 8 buttons available
    int16_t x;				// -32767 to 32767
    int16_t y;				// -32767 to 32767
    int16_t wheel;			// -32767 to 32767
}standard_mouse_report_t;

typedef struct {
    uint8_t report_id;
    uint8_t buttons;      // 8 buttons控制键
    uint8_t data[10];     //常规按键
}standard_keyboard_report_t;
#pragma pack()

#define CAT_NONE                               0x00
#define CAT_ERRORROLLOVER                      0x01
#define CAT_POSTFAIL                           0x02
#define CAT_ERRORUNDEFINED                     0x03
#define CAT_A                                  0x04
#define CAT_B                                  0x05
#define CAT_C                                  0x06
#define CAT_D                                  0x07
#define CAT_E                                  0x08
#define CAT_F                                  0x09
#define CAT_G                                  0x0A
#define CAT_H                                  0x0B
#define CAT_I                                  0x0C
#define CAT_J                                  0x0D
#define CAT_K                                  0x0E
#define CAT_L                                  0x0F
#define CAT_M                                  0x10
#define CAT_N                                  0x11
#define CAT_O                                  0x12
#define CAT_P                                  0x13
#define CAT_Q                                  0x14
#define CAT_R                                  0x15
#define CAT_S                                  0x16
#define CAT_T                                  0x17
#define CAT_U                                  0x18
#define CAT_V                                  0x19
#define CAT_W                                  0x1A
#define CAT_X                                  0x1B
#define CAT_Y                                  0x1C
#define CAT_Z                                  0x1D
#define CAT_1_EXCLAMATION_MARK                 0x1E
#define CAT_2_AT                               0x1F
#define CAT_3_NUMBER_SIGN                      0x20
#define CAT_4_DOLLAR                           0x21
#define CAT_5_PERCENT                          0x22
#define CAT_6_CARET                            0x23
#define CAT_7_AMPERSAND                        0x24
#define CAT_8_ASTERISK                         0x25
#define CAT_9_OPARENTHESIS                     0x26
#define CAT_0_CPARENTHESIS                     0x27
#define CAT_ENTER                              0x28
#define CAT_ESCAPE                             0x29
#define CAT_BACKSPACE                          0x2A
#define CAT_TAB                                0x2B
#define CAT_SPACEBAR                           0x2C
#define CAT_MINUS_UNDERSCORE                   0x2D
#define CAT_EQUAL_PLUS                         0x2E
#define CAT_OBRACKET_AND_OBRACE                0x2F
#define CAT_CBRACKET_AND_CBRACE                0x30
#define CAT_BACKSLASH_VERTICAL_BAR             0x31
#define CAT_NONUS_NUMBER_SIGN_TILDE            0x32
#define CAT_SEMICOLON_COLON                    0x33
#define CAT_SINGLE_AND_DOUBLE_QUOTE            0x34
#define CAT_GRAVE ACCENT AND TILDE             0x35
#define CAT_COMMA_AND_LESS                     0x36
#define CAT_DOT_GREATER                        0x37
#define CAT_SLASH_QUESTION                     0x38
#define CAT_CAPS LOCK                          0x39
#define CAT_F1                                 0x3A
#define CAT_F2                                 0x3B
#define CAT_F3                                 0x3C
#define CAT_F4                                 0x3D
#define CAT_F5                                 0x3E
#define CAT_F6                                 0x3F
#define CAT_F7                                 0x40
#define CAT_F8                                 0x41
#define CAT_F9                                 0x42
#define CAT_F10                                0x43
#define CAT_F11                                0x44
#define CAT_F12                                0x45
#define CAT_PRINTSCREEN                        0x46
#define CAT_SCROLL LOCK                        0x47
#define CAT_PAUSE                              0x48
#define CAT_INSERT                             0x49
#define CAT_HOME                               0x4A
#define CAT_PAGEUP                             0x4B
#define CAT_DELETE                             0x4C
#define CAT_END1                               0x4D
#define CAT_PAGEDOWN                           0x4E
#define CAT_RIGHTARROW                         0x4F
#define CAT_LEFTARROW                          0x50
#define CAT_DOWNARROW                          0x51
#define CAT_UPARROW                            0x52
#define CAT_KEYPAD_NUM_LOCK_AND_CLEAR          0x53
#define CAT_KEYPAD_SLASH                       0x54
#define CAT_KEYPAD_ASTERIKS                    0x55
#define CAT_KEYPAD_MINUS                       0x56
#define CAT_KEYPAD_PLUS                        0x57
#define CAT_KEYPAD_ENTER                       0x58
#define CAT_KEYPAD_1_END                       0x59
#define CAT_KEYPAD_2_DOWN_ARROW                0x5A
#define CAT_KEYPAD_3_PAGEDN                    0x5B
#define CAT_KEYPAD_4_LEFT_ARROW                0x5C
#define CAT_KEYPAD_5                           0x5D
#define CAT_KEYPAD_6_RIGHT_ARROW               0x5E
#define CAT_KEYPAD_7_HOME                      0x5F
#define CAT_KEYPAD_8_UP_ARROW                  0x60
#define CAT_KEYPAD_9_PAGEUP                    0x61
#define CAT_KEYPAD_0_INSERT                    0x62
#define CAT_KEYPAD_DECIMAL_SEPARATOR_DELETE    0x63
#define CAT_NONUS_BACK_SLASH_VERTICAL_BAR      0x64
#define CAT_APPLICATION                        0x65
#define CAT_POWER                              0x66
#define CAT_KEYPAD_EQUAL                       0x67
#define CAT_F13                                0x68
#define CAT_F14                                0x69
#define CAT_F15                                0x6A
#define CAT_F16                                0x6B
#define CAT_F17                                0x6C
#define CAT_F18                                0x6D
#define CAT_F19                                0x6E
#define CAT_F20                                0x6F
#define CAT_F21                                0x70
#define CAT_F22                                0x71
#define CAT_F23                                0x72
#define CAT_F24                                0x73
#define CAT_EXECUTE                            0x74
#define CAT_HELP                               0x75
#define CAT_MENU                               0x76
#define CAT_SELECT                             0x77
#define CAT_STOP                               0x78
#define CAT_AGAIN                              0x79
#define CAT_UNDO                               0x7A
#define CAT_CUT                                0x7B
#define CAT_COPY                               0x7C
#define CAT_PASTE                              0x7D
#define CAT_FIND                               0x7E
#define CAT_MUTE                               0x7F
#define CAT_VOLUME_UP                          0x80
#define CAT_VOLUME_DOWN                        0x81
#define CAT_LOCKING_CAPS_LOCK                  0x82
#define CAT_LOCKING_NUM_LOCK                   0x83
#define CAT_LOCKING_SCROLL_LOCK                0x84
#define CAT_KEYPAD_COMMA                       0x85
#define CAT_KEYPAD_EQUAL_SIGN                  0x86
#define CAT_INTERNATIONAL1                     0x87
#define CAT_INTERNATIONAL2                     0x88
#define CAT_INTERNATIONAL3                     0x89
#define CAT_INTERNATIONAL4                     0x8A
#define CAT_INTERNATIONAL5                     0x8B
#define CAT_INTERNATIONAL6                     0x8C
#define CAT_INTERNATIONAL7                     0x8D
#define CAT_INTERNATIONAL8                     0x8E
#define CAT_INTERNATIONAL9                     0x8F
#define CAT_LANG1                              0x90
#define CAT_LANG2                              0x91
#define CAT_LANG3                              0x92
#define CAT_LANG4                              0x93
#define CAT_LANG5                              0x94
#define CAT_LANG6                              0x95
#define CAT_LANG7                              0x96
#define CAT_LANG8                              0x97
#define CAT_LANG9                              0x98
#define CAT_ALTERNATE_ERASE                    0x99
#define CAT_SYSREQ                             0x9A
#define CAT_CANCEL                             0x9B
#define CAT_CLEAR                              0x9C
#define CAT_PRIOR                              0x9D
#define CAT_RETURN                             0x9E
#define CAT_SEPARATOR                          0x9F
#define CAT_OUT                                0xA0
#define CAT_OPER                               0xA1
#define CAT_CLEAR_AGAIN                        0xA2
#define CAT_CRSEL                              0xA3
#define CAT_EXSEL                              0xA4
#define CAT_KEYPAD_00                          0xB0
#define CAT_KEYPAD_000                         0xB1
#define CAT_THOUSANDS_SEPARATOR                0xB2
#define CAT_DECIMAL_SEPARATOR                  0xB3
#define CAT_CURRENCY_UNIT                      0xB4
#define CAT_CURRENCY_SUB_UNIT                  0xB5
#define CAT_KEYPAD_OPARENTHESIS                0xB6
#define CAT_KEYPAD_CPARENTHESIS                0xB7
#define CAT_KEYPAD_OBRACE                      0xB8
#define CAT_KEYPAD_CBRACE                      0xB9
#define CAT_KEYPAD_TAB                         0xBA
#define CAT_KEYPAD_BACKSPACE                   0xBB
#define CAT_KEYPAD_A                           0xBC
#define CAT_KEYPAD_B                           0xBD
#define CAT_KEYPAD_C                           0xBE
#define CAT_KEYPAD_D                           0xBF
#define CAT_KEYPAD_E                           0xC0
#define CAT_KEYPAD_F                           0xC1
#define CAT_KEYPAD_XOR                         0xC2
#define CAT_KEYPAD_CARET                       0xC3
#define CAT_KEYPAD_PERCENT                     0xC4
#define CAT_KEYPAD_LESS                        0xC5
#define CAT_KEYPAD_GREATER                     0xC6
#define CAT_KEYPAD_AMPERSAND                   0xC7
#define CAT_KEYPAD_LOGICAL_AND                 0xC8
#define CAT_KEYPAD_VERTICAL_BAR                0xC9
#define CAT_KEYPAD_LOGIACL_OR                  0xCA
#define CAT_KEYPAD_COLON                       0xCB
#define CAT_KEYPAD_NUMBER_SIGN                 0xCC
#define CAT_KEYPAD_SPACE                       0xCD
#define CAT_KEYPAD_AT                          0xCE
#define CAT_KEYPAD_EXCLAMATION_MARK            0xCF
#define CAT_KEYPAD_MEMORY_STORE                0xD0
#define CAT_KEYPAD_MEMORY_RECALL               0xD1
#define CAT_KEYPAD_MEMORY_CLEAR                0xD2
#define CAT_KEYPAD_MEMORY_ADD                  0xD3
#define CAT_KEYPAD_MEMORY_SUBTRACT             0xD4
#define CAT_KEYPAD_MEMORY_MULTIPLY             0xD5
#define CAT_KEYPAD_MEMORY_DIVIDE               0xD6
#define CAT_KEYPAD_PLUSMINUS                   0xD7
#define CAT_KEYPAD_CLEAR                       0xD8
#define CAT_KEYPAD_CLEAR_ENTRY                 0xD9
#define CAT_KEYPAD_BINARY                      0xDA
#define CAT_KEYPAD_OCTAL                       0xDB
#define CAT_KEYPAD_DECIMAL                     0xDC
#define CAT_KEYPAD_HEXADECIMAL                 0xDD
#define CAT_LEFTCONTROL                        0xE0
#define CAT_LEFTSHIFT                          0xE1
#define CAT_LEFTALT                            0xE2
#define CAT_LEFT_GUI                           0xE3
#define CAT_RIGHTCONTROL                       0xE4
#define CAT_RIGHTSHIFT                         0xE5
#define CAT_RIGHTALT                           0xE6
#define CAT_RIGHT_GUI                          0xE7

static const std::unordered_map<int, int> cat_keyboard_map = {
        {KEY_RESERVED,         CAT_NONE},
        {KEY_ESC,              CAT_ESCAPE},
        {KEY_1,                CAT_1_EXCLAMATION_MARK},
        {KEY_2,                CAT_2_AT},
        {KEY_3,                CAT_3_NUMBER_SIGN},
        {KEY_4,                CAT_4_DOLLAR},
        {KEY_5,                CAT_5_PERCENT},
        {KEY_6,                CAT_6_CARET},
        {KEY_7,                CAT_7_AMPERSAND},
        {KEY_8,                CAT_8_ASTERISK},
        {KEY_9,                CAT_9_OPARENTHESIS},
        {KEY_0,                CAT_0_CPARENTHESIS},
        {KEY_MINUS,            CAT_MINUS_UNDERSCORE},
        {KEY_EQUAL,            CAT_EQUAL_PLUS},
        {KEY_BACKSPACE,        CAT_BACKSPACE},
        {KEY_TAB,              CAT_TAB},
        {KEY_Q,                CAT_Q},
        {KEY_W,                CAT_W},
        {KEY_E,                CAT_E},
        {KEY_R,                CAT_R},
        {KEY_T,                CAT_T},
        {KEY_Y,                CAT_Y},
        {KEY_U,                CAT_U},
        {KEY_I,                CAT_I},
        {KEY_O,                CAT_O},
        {KEY_P,                CAT_P},
        {KEY_LEFTBRACE,        CAT_OBRACKET_AND_OBRACE},
        {KEY_RIGHTBRACE,       CAT_CBRACKET_AND_CBRACE},
        {KEY_ENTER,            CAT_ENTER},
        {KEY_LEFTCTRL,         CAT_LEFTCONTROL},
        {KEY_A,                CAT_A},
        {KEY_S,                CAT_S},
        {KEY_D,                CAT_D},
        {KEY_F,                CAT_F},
        {KEY_G,                CAT_G},
        {KEY_H,                CAT_H},
        {KEY_J,                CAT_J},
        {KEY_K,                CAT_K},
        {KEY_L,                CAT_L},
        {KEY_SEMICOLON,        CAT_SEMICOLON_COLON},
        {KEY_APOSTROPHE,       CAT_SINGLE_AND_DOUBLE_QUOTE},
        //{KEY_GRAVE,            CAT_GRAVE_ACCENT_AND_TILDE},
        {KEY_LEFTSHIFT,        CAT_LEFTSHIFT},
        {KEY_BACKSLASH,        CAT_BACKSLASH_VERTICAL_BAR},
        {KEY_Z,                CAT_Z},
        {KEY_X,                CAT_X},
        {KEY_C,                CAT_C},
        {KEY_V,                CAT_V},
        {KEY_B,                CAT_B},
        {KEY_N,                CAT_N},
        {KEY_M,                CAT_M},
        {KEY_COMMA,            CAT_COMMA_AND_LESS},
        {KEY_DOT,              CAT_DOT_GREATER},
        {KEY_SLASH,            CAT_SLASH_QUESTION},
        {KEY_RIGHTSHIFT,       CAT_RIGHTSHIFT},
        //KEY_KPASTERISK,       CAT_KEYPAD_ASTERISK},
        {KEY_LEFTALT,          CAT_LEFTALT},
        {KEY_SPACE,            CAT_SPACEBAR},
        //{KEY_CAPSLOCK,         CAT_CAPS_LOCK},
        {KEY_F1,               CAT_F1},
        {KEY_F2,               CAT_F2},
        {KEY_F3,               CAT_F3},
        {KEY_F4,               CAT_F4},
        {KEY_F5,               CAT_F5},
        {KEY_F6,               CAT_F6},
        {KEY_F7,               CAT_F7},
        {KEY_F8,               CAT_F8},
        {KEY_F9,               CAT_F9},
        {KEY_F10,              CAT_F10},
        {KEY_NUMLOCK,          CAT_KEYPAD_NUM_LOCK_AND_CLEAR},
       // {KEY_SCROLLLOCK,       CAT_SCROLL_LOCK},
        {KEY_KP7,              CAT_KEYPAD_7_HOME},
        {KEY_KP8,              CAT_KEYPAD_8_UP_ARROW},
        {KEY_KP9,              CAT_KEYPAD_9_PAGEUP},
        {KEY_KPMINUS,          CAT_KEYPAD_MINUS},
        {KEY_KP4,              CAT_KEYPAD_4_LEFT_ARROW},
        {KEY_KP5,              CAT_KEYPAD_5},
        {KEY_KP6,              CAT_KEYPAD_6_RIGHT_ARROW},
        {KEY_KPPLUS,           CAT_KEYPAD_PLUS},
        {KEY_KP1,              CAT_KEYPAD_1_END},
        {KEY_KP2,              CAT_KEYPAD_2_DOWN_ARROW},
        {KEY_KP3,              CAT_KEYPAD_3_PAGEDN},
        {KEY_KP0,              CAT_KEYPAD_0_INSERT},
        {KEY_KPDOT,            CAT_KEYPAD_DECIMAL_SEPARATOR_DELETE},
        {KEY_ZENKAKUHANKAKU,   CAT_NONE},
        {KEY_102ND,            CAT_NONE},
        {KEY_F11,              CAT_F11},
        {KEY_F12,              CAT_F12},
        {KEY_KPENTER,          CAT_KEYPAD_ENTER},
        {KEY_RIGHTCTRL,        CAT_RIGHTCONTROL},
        {KEY_KPSLASH,          CAT_KEYPAD_SLASH},
        {KEY_SYSRQ,            CAT_SYSREQ},
        {KEY_RIGHTALT,         CAT_RIGHTALT},
        {KEY_HOME,             CAT_HOME},
        {KEY_UP,               CAT_UPARROW},
        {KEY_PAGEUP,           CAT_PAGEUP},
        {KEY_LEFT,             CAT_LEFTARROW},
        {KEY_RIGHT,            CAT_RIGHTARROW},
        {KEY_END,              CAT_END1},
        {KEY_DOWN,             CAT_DOWNARROW},
        {KEY_PAGEDOWN,         CAT_PAGEDOWN},
        {KEY_INSERT,           CAT_INSERT},
        {KEY_DELETE,           CAT_DELETE},
        {KEY_PAUSE,            CAT_PAUSE},
        {KEY_LEFTMETA,         CAT_LEFT_GUI},
        {KEY_RIGHTMETA,        CAT_RIGHT_GUI},
        {KEY_COMPOSE,          CAT_NONE},
        {KEY_PLAYCD,           CAT_NONE},
        {KEY_PAUSECD,          CAT_NONE},
        {KEY_PROG3,            CAT_NONE},
        {KEY_PROG4,            CAT_NONE},
        //{KEY_ALL_APPLICATIONS, CAT_NONE},
        {KEY_DASHBOARD,        CAT_NONE},
        {KEY_SUSPEND,          CAT_NONE},
        {KEY_CLOSE,            CAT_NONE},
        {KEY_PLAY,             CAT_NONE},
        {KEY_FASTFORWARD,      CAT_NONE},
        {KEY_BASSBOOST,        CAT_NONE},
        {KEY_PRINT,            CAT_NONE},
        {KEY_HP,               CAT_NONE},
        {KEY_CAMERA,           CAT_NONE},
        {KEY_SOUND,            CAT_NONE},
        {KEY_QUESTION,         CAT_NONE},
        {KEY_EMAIL,            CAT_NONE},
        {KEY_CHAT,             CAT_NONE},
        {KEY_SEARCH,           CAT_NONE},
        {KEY_CONNECT,          CAT_NONE},
        {KEY_FINANCE,          CAT_NONE},
        {KEY_SPORT,            CAT_NONE},
        {KEY_SHOP,             CAT_NONE},
        {KEY_ALTERASE,         CAT_ALTERNATE_ERASE},
        {KEY_CANCEL,           CAT_CANCEL},
        {KEY_BRIGHTNESSDOWN,   CAT_NONE},
        {KEY_BRIGHTNESSUP,     CAT_NONE},
        {KEY_MEDIA,            CAT_NONE},
        {KEY_SWITCHVIDEOMODE,  CAT_NONE},
        {KEY_KBDILLUMTOGGLE,   CAT_NONE},
        {KEY_KBDILLUMDOWN,     CAT_NONE},
        {KEY_KBDILLUMUP,       CAT_NONE},
        {KEY_SEND,             CAT_NONE},
        {KEY_REPLY,            CAT_NONE},
        {KEY_FORWARDMAIL,      CAT_NONE},
        {KEY_SAVE,             CAT_NONE},
        {KEY_DOCUMENTS,        CAT_NONE},
        {KEY_BATTERY,          CAT_NONE},
        {KEY_BLUETOOTH,        CAT_NONE},
        {KEY_WLAN,             CAT_NONE},
        {KEY_UWB,              CAT_NONE},
        {KEY_UNKNOWN,          CAT_NONE},
        {KEY_VIDEO_NEXT,       CAT_NONE},
        {KEY_VIDEO_PREV,       CAT_NONE},
        {KEY_BRIGHTNESS_CYCLE, CAT_NONE},
        {KEY_BRIGHTNESS_AUTO,  CAT_NONE},
        {KEY_BRIGHTNESS_ZERO,  CAT_NONE},
        {KEY_DISPLAY_OFF,      CAT_NONE},
        {KEY_WWAN,             CAT_NONE},
        {KEY_WIMAX,            CAT_NONE},
        {KEY_RFKILL,           CAT_NONE},
        {KEY_MICMUTE,          CAT_NONE}
};

static const std::unordered_map<int, int> reverse_cat_keyboard_map = {
        {CAT_NONE,                     KEY_RESERVED},
        {CAT_ESCAPE,                   KEY_ESC},
        {CAT_1_EXCLAMATION_MARK,       KEY_1},
        {CAT_2_AT,                     KEY_2},
        {CAT_3_NUMBER_SIGN,            KEY_3},
        {CAT_4_DOLLAR,                 KEY_4},
        {CAT_5_PERCENT,                KEY_5},
        {CAT_6_CARET,                  KEY_6},
        {CAT_7_AMPERSAND,              KEY_7},
        {CAT_8_ASTERISK,               KEY_8},
        {CAT_9_OPARENTHESIS,           KEY_9},
        {CAT_0_CPARENTHESIS,           KEY_0},
        {CAT_MINUS_UNDERSCORE,         KEY_MINUS},
        {CAT_EQUAL_PLUS,               KEY_EQUAL},
        {CAT_BACKSPACE,                KEY_BACKSPACE},
        {CAT_TAB,                      KEY_TAB},
        {CAT_Q,                        KEY_Q},
        {CAT_W,                        KEY_W},
        {CAT_E,                        KEY_E},
        {CAT_R,                        KEY_R},
        {CAT_T,                        KEY_T},
        {CAT_Y,                        KEY_Y},
        {CAT_U,                        KEY_U},
        {CAT_I,                        KEY_I},
        {CAT_O,                        KEY_O},
        {CAT_P,                        KEY_P},
        {CAT_OBRACKET_AND_OBRACE,      KEY_LEFTBRACE},
        {CAT_CBRACKET_AND_CBRACE,      KEY_RIGHTBRACE},
        {CAT_ENTER,                    KEY_ENTER},
        {CAT_LEFTCONTROL,              KEY_LEFTCTRL},
        {CAT_A,                        KEY_A},
        {CAT_S,                        KEY_S},
        {CAT_D,                        KEY_D},
        {CAT_F,                        KEY_F},
        {CAT_G,                        KEY_G},
        {CAT_H,                        KEY_H},
        {CAT_J,                        KEY_J},
        {CAT_K,                        KEY_K},
        {CAT_L,                        KEY_L},
        {CAT_SEMICOLON_COLON,          KEY_SEMICOLON},
        {CAT_SINGLE_AND_DOUBLE_QUOTE,  KEY_APOSTROPHE},
        {CAT_LEFTSHIFT,                KEY_LEFTSHIFT},
        {CAT_BACKSLASH_VERTICAL_BAR,   KEY_BACKSLASH},
        {CAT_Z,                        KEY_Z},
        {CAT_X,                        KEY_X},
        {CAT_C,                        KEY_C},
        {CAT_V,                        KEY_V},
        {CAT_B,                        KEY_B},
        {CAT_N,                        KEY_N},
        {CAT_M,                        KEY_M},
        {CAT_COMMA_AND_LESS,           KEY_COMMA},
        {CAT_DOT_GREATER,              KEY_DOT},
        {CAT_SLASH_QUESTION,           KEY_SLASH},
        {CAT_RIGHTSHIFT,               KEY_RIGHTSHIFT},
        {CAT_LEFTALT,                  KEY_LEFTALT},
        {CAT_SPACEBAR,                 KEY_SPACE},
        {CAT_F1,                       KEY_F1},
        {CAT_F2,                       KEY_F2},
        {CAT_F3,                       KEY_F3},
        {CAT_F4,                       KEY_F4},
        {CAT_F5,                       KEY_F5},
        {CAT_F6,                       KEY_F6},
        {CAT_F7,                       KEY_F7},
        {CAT_F8,                       KEY_F8},
        {CAT_F9,                       KEY_F9},
        {CAT_F10,                      KEY_F10},
        {CAT_KEYPAD_NUM_LOCK_AND_CLEAR,KEY_NUMLOCK},
        {CAT_KEYPAD_7_HOME,            KEY_KP7},
        {CAT_KEYPAD_8_UP_ARROW,        KEY_KP8},
        {CAT_KEYPAD_9_PAGEUP,          KEY_KP9},
        {CAT_KEYPAD_MINUS,             KEY_KPMINUS},
        {CAT_KEYPAD_4_LEFT_ARROW,      KEY_KP4},
        {CAT_KEYPAD_5,                 KEY_KP5},
        {CAT_KEYPAD_6_RIGHT_ARROW,     KEY_KP6},
        {CAT_KEYPAD_PLUS,              KEY_KPPLUS},
        {CAT_KEYPAD_1_END,             KEY_KP1},
        {CAT_KEYPAD_2_DOWN_ARROW,      KEY_KP2},
        {CAT_KEYPAD_3_PAGEDN,          KEY_KP3},
        {CAT_KEYPAD_0_INSERT,          KEY_KP0},
        {CAT_KEYPAD_DECIMAL_SEPARATOR_DELETE, KEY_KPDOT},
        {CAT_F11,                      KEY_F11},
        {CAT_F12,                      KEY_F12},
        {CAT_KEYPAD_ENTER,             KEY_KPENTER},
        {CAT_RIGHTCONTROL,             KEY_RIGHTCTRL},
        {CAT_KEYPAD_SLASH,             KEY_KPSLASH},
        {CAT_SYSREQ,                   KEY_SYSRQ},
        {CAT_RIGHTALT,                 KEY_RIGHTALT},
        {CAT_HOME,                     KEY_HOME},
        {CAT_UPARROW,                  KEY_UP},
        {CAT_PAGEUP,                   KEY_PAGEUP},
        {CAT_LEFTARROW,                KEY_LEFT},
        {CAT_RIGHTARROW,               KEY_RIGHT},
        {CAT_END1,                     KEY_END},
        {CAT_DOWNARROW,                KEY_DOWN},
        {CAT_PAGEDOWN,                 KEY_PAGEDOWN},
        {CAT_INSERT,                   KEY_INSERT},
        {CAT_DELETE,                   KEY_DELETE},
        {CAT_PAUSE,                    KEY_PAUSE},
        {CAT_LEFT_GUI,                 KEY_LEFTMETA},
        {CAT_RIGHT_GUI,                KEY_RIGHTMETA},
        {CAT_ALTERNATE_ERASE,          KEY_ALTERASE},
        {CAT_CANCEL,                   KEY_CANCEL}
};


// 定义点结构
struct Point {
    int x;
    int y;
};

const int control_key[8] = {KEY_LEFTCTRL,KEY_LEFTSHIFT,KEY_LEFTALT,KEY_LEFTMETA,
                    KEY_RIGHTCTRL,KEY_RIGHTSHIFT,KEY_RIGHTALT,KEY_RIGHTMETA};

#endif //DEMO_CATBOX_CMD_H
