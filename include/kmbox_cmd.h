#ifndef DEMO_KMBOX_CMD_H
#define DEMO_KMBOX_CMD_H

#include <unordered_map>
#include <set>

#define BUFFER_SIZE 1024

//兼容kmbox net的命令

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

#define KM_NONE                               0x00
#define KM_ERRORROLLOVER                      0x01
#define KM_POSTFAIL                           0x02
#define KM_ERRORUNDEFINED                     0x03
#define KM_A                                  0x04
#define KM_B                                  0x05
#define KM_C                                  0x06
#define KM_D                                  0x07
#define KM_E                                  0x08
#define KM_F                                  0x09
#define KM_G                                  0x0A
#define KM_H                                  0x0B
#define KM_I                                  0x0C
#define KM_J                                  0x0D
#define KM_K                                  0x0E
#define KM_L                                  0x0F
#define KM_M                                  0x10
#define KM_N                                  0x11
#define KM_O                                  0x12
#define KM_P                                  0x13
#define KM_Q                                  0x14
#define KM_R                                  0x15
#define KM_S                                  0x16
#define KM_T                                  0x17
#define KM_U                                  0x18
#define KM_V                                  0x19
#define KM_W                                  0x1A
#define KM_X                                  0x1B
#define KM_Y                                  0x1C
#define KM_Z                                  0x1D
#define KM_1_EXCLAMATION_MARK                 0x1E
#define KM_2_AT                               0x1F
#define KM_3_NUMBER_SIGN                      0x20
#define KM_4_DOLLAR                           0x21
#define KM_5_PERCENT                          0x22
#define KM_6_CARET                            0x23
#define KM_7_AMPERSAND                        0x24
#define KM_8_ASTERISK                         0x25
#define KM_9_OPARENTHESIS                     0x26
#define KM_0_CPARENTHESIS                     0x27
#define KM_ENTER                              0x28
#define KM_ESCAPE                             0x29
#define KM_BACKSPACE                          0x2A
#define KM_TAB                                0x2B
#define KM_SPACEBAR                           0x2C
#define KM_MINUS_UNDERSCORE                   0x2D
#define KM_EQUAL_PLUS                         0x2E
#define KM_OBRACKET_AND_OBRACE                0x2F
#define KM_CBRACKET_AND_CBRACE                0x30
#define KM_BACKSLASH_VERTICAL_BAR             0x31
#define KM_NONUS_NUMBER_SIGN_TILDE            0x32
#define KM_SEMICOLON_COLON                    0x33
#define KM_SINGLE_AND_DOUBLE_QUOTE            0x34
#define KM_GRAVE ACCENT AND TILDE             0x35
#define KM_COMMA_AND_LESS                     0x36
#define KM_DOT_GREATER                        0x37
#define KM_SLASH_QUESTION                     0x38
#define KM_CAPS LOCK                          0x39
#define KM_F1                                 0x3A
#define KM_F2                                 0x3B
#define KM_F3                                 0x3C
#define KM_F4                                 0x3D
#define KM_F5                                 0x3E
#define KM_F6                                 0x3F
#define KM_F7                                 0x40
#define KM_F8                                 0x41
#define KM_F9                                 0x42
#define KM_F10                                0x43
#define KM_F11                                0x44
#define KM_F12                                0x45
#define KM_PRINTSCREEN                        0x46
#define KM_SCROLL LOCK                        0x47
#define KM_PAUSE                              0x48
#define KM_INSERT                             0x49
#define KM_HOME                               0x4A
#define KM_PAGEUP                             0x4B
#define KM_DELETE                             0x4C
#define KM_END1                               0x4D
#define KM_PAGEDOWN                           0x4E
#define KM_RIGHTARROW                         0x4F
#define KM_LEFTARROW                          0x50
#define KM_DOWNARROW                          0x51
#define KM_UPARROW                            0x52
#define KM_KEYPAD_NUM_LOCK_AND_CLEAR          0x53
#define KM_KEYPAD_SLASH                       0x54
#define KM_KEYPAD_ASTERIKS                    0x55
#define KM_KEYPAD_MINUS                       0x56
#define KM_KEYPAD_PLUS                        0x57
#define KM_KEYPAD_ENTER                       0x58
#define KM_KEYPAD_1_END                       0x59
#define KM_KEYPAD_2_DOWN_ARROW                0x5A
#define KM_KEYPAD_3_PAGEDN                    0x5B
#define KM_KEYPAD_4_LEFT_ARROW                0x5C
#define KM_KEYPAD_5                           0x5D
#define KM_KEYPAD_6_RIGHT_ARROW               0x5E
#define KM_KEYPAD_7_HOME                      0x5F
#define KM_KEYPAD_8_UP_ARROW                  0x60
#define KM_KEYPAD_9_PAGEUP                    0x61
#define KM_KEYPAD_0_INSERT                    0x62
#define KM_KEYPAD_DECIMAL_SEPARATOR_DELETE    0x63
#define KM_NONUS_BACK_SLASH_VERTICAL_BAR      0x64
#define KM_APPLICATION                        0x65
#define KM_POWER                              0x66
#define KM_KEYPAD_EQUAL                       0x67
#define KM_F13                                0x68
#define KM_F14                                0x69
#define KM_F15                                0x6A
#define KM_F16                                0x6B
#define KM_F17                                0x6C
#define KM_F18                                0x6D
#define KM_F19                                0x6E
#define KM_F20                                0x6F
#define KM_F21                                0x70
#define KM_F22                                0x71
#define KM_F23                                0x72
#define KM_F24                                0x73
#define KM_EXECUTE                            0x74
#define KM_HELP                               0x75
#define KM_MENU                               0x76
#define KM_SELECT                             0x77
#define KM_STOP                               0x78
#define KM_AGAIN                              0x79
#define KM_UNDO                               0x7A
#define KM_CUT                                0x7B
#define KM_COPY                               0x7C
#define KM_PASTE                              0x7D
#define KM_FIND                               0x7E
#define KM_MUTE                               0x7F
#define KM_VOLUME_UP                          0x80
#define KM_VOLUME_DOWN                        0x81
#define KM_LOCKING_CAPS_LOCK                  0x82
#define KM_LOCKING_NUM_LOCK                   0x83
#define KM_LOCKING_SCROLL_LOCK                0x84
#define KM_KEYPAD_COMMA                       0x85
#define KM_KEYPAD_EQUAL_SIGN                  0x86
#define KM_INTERNATIONAL1                     0x87
#define KM_INTERNATIONAL2                     0x88
#define KM_INTERNATIONAL3                     0x89
#define KM_INTERNATIONAL4                     0x8A
#define KM_INTERNATIONAL5                     0x8B
#define KM_INTERNATIONAL6                     0x8C
#define KM_INTERNATIONAL7                     0x8D
#define KM_INTERNATIONAL8                     0x8E
#define KM_INTERNATIONAL9                     0x8F
#define KM_LANG1                              0x90
#define KM_LANG2                              0x91
#define KM_LANG3                              0x92
#define KM_LANG4                              0x93
#define KM_LANG5                              0x94
#define KM_LANG6                              0x95
#define KM_LANG7                              0x96
#define KM_LANG8                              0x97
#define KM_LANG9                              0x98
#define KM_ALTERNATE_ERASE                    0x99
#define KM_SYSREQ                             0x9A
#define KM_CANCEL                             0x9B
#define KM_CLEAR                              0x9C
#define KM_PRIOR                              0x9D
#define KM_RETURN                             0x9E
#define KM_SEPARATOR                          0x9F
#define KM_OUT                                0xA0
#define KM_OPER                               0xA1
#define KM_CLEAR_AGAIN                        0xA2
#define KM_CRSEL                              0xA3
#define KM_EXSEL                              0xA4
#define KM_KEYPAD_00                          0xB0
#define KM_KEYPAD_000                         0xB1
#define KM_THOUSANDS_SEPARATOR                0xB2
#define KM_DECIMAL_SEPARATOR                  0xB3
#define KM_CURRENCY_UNIT                      0xB4
#define KM_CURRENCY_SUB_UNIT                  0xB5
#define KM_KEYPAD_OPARENTHESIS                0xB6
#define KM_KEYPAD_CPARENTHESIS                0xB7
#define KM_KEYPAD_OBRACE                      0xB8
#define KM_KEYPAD_CBRACE                      0xB9
#define KM_KEYPAD_TAB                         0xBA
#define KM_KEYPAD_BACKSPACE                   0xBB
#define KM_KEYPAD_A                           0xBC
#define KM_KEYPAD_B                           0xBD
#define KM_KEYPAD_C                           0xBE
#define KM_KEYPAD_D                           0xBF
#define KM_KEYPAD_E                           0xC0
#define KM_KEYPAD_F                           0xC1
#define KM_KEYPAD_XOR                         0xC2
#define KM_KEYPAD_CARET                       0xC3
#define KM_KEYPAD_PERCENT                     0xC4
#define KM_KEYPAD_LESS                        0xC5
#define KM_KEYPAD_GREATER                     0xC6
#define KM_KEYPAD_AMPERSAND                   0xC7
#define KM_KEYPAD_LOGICAL_AND                 0xC8
#define KM_KEYPAD_VERTICAL_BAR                0xC9
#define KM_KEYPAD_LOGIACL_OR                  0xCA
#define KM_KEYPAD_COLON                       0xCB
#define KM_KEYPAD_NUMBER_SIGN                 0xCC
#define KM_KEYPAD_SPACE                       0xCD
#define KM_KEYPAD_AT                          0xCE
#define KM_KEYPAD_EXCLAMATION_MARK            0xCF
#define KM_KEYPAD_MEMORY_STORE                0xD0
#define KM_KEYPAD_MEMORY_RECALL               0xD1
#define KM_KEYPAD_MEMORY_CLEAR                0xD2
#define KM_KEYPAD_MEMORY_ADD                  0xD3
#define KM_KEYPAD_MEMORY_SUBTRACT             0xD4
#define KM_KEYPAD_MEMORY_MULTIPLY             0xD5
#define KM_KEYPAD_MEMORY_DIVIDE               0xD6
#define KM_KEYPAD_PLUSMINUS                   0xD7
#define KM_KEYPAD_CLEAR                       0xD8
#define KM_KEYPAD_CLEAR_ENTRY                 0xD9
#define KM_KEYPAD_BINARY                      0xDA
#define KM_KEYPAD_OCTAL                       0xDB
#define KM_KEYPAD_DECIMAL                     0xDC
#define KM_KEYPAD_HEXADECIMAL                 0xDD
#define KM_LEFTCONTROL                        0xE0
#define KM_LEFTSHIFT                          0xE1
#define KM_LEFTALT                            0xE2
#define KM_LEFT_GUI                           0xE3
#define KM_RIGHTCONTROL                       0xE4
#define KM_RIGHTSHIFT                         0xE5
#define KM_RIGHTALT                           0xE6
#define KM_RIGHT_GUI                          0xE7

static const std::unordered_map<int, int> km_keyboard_map = {
        {KEY_RESERVED,         KM_NONE},
        {KEY_ESC,              KM_ESCAPE},
        {KEY_1,                KM_1_EXCLAMATION_MARK},
        {KEY_2,                KM_2_AT},
        {KEY_3,                KM_3_NUMBER_SIGN},
        {KEY_4,                KM_4_DOLLAR},
        {KEY_5,                KM_5_PERCENT},
        {KEY_6,                KM_6_CARET},
        {KEY_7,                KM_7_AMPERSAND},
        {KEY_8,                KM_8_ASTERISK},
        {KEY_9,                KM_9_OPARENTHESIS},
        {KEY_0,                KM_0_CPARENTHESIS},
        {KEY_MINUS,            KM_MINUS_UNDERSCORE},
        {KEY_EQUAL,            KM_EQUAL_PLUS},
        {KEY_BACKSPACE,        KM_BACKSPACE},
        {KEY_TAB,              KM_TAB},
        {KEY_Q,                KM_Q},
        {KEY_W,                KM_W},
        {KEY_E,                KM_E},
        {KEY_R,                KM_R},
        {KEY_T,                KM_T},
        {KEY_Y,                KM_Y},
        {KEY_U,                KM_U},
        {KEY_I,                KM_I},
        {KEY_O,                KM_O},
        {KEY_P,                KM_P},
        {KEY_LEFTBRACE,        KM_OBRACKET_AND_OBRACE},
        {KEY_RIGHTBRACE,       KM_CBRACKET_AND_CBRACE},
        {KEY_ENTER,            KM_ENTER},
        {KEY_LEFTCTRL,         KM_LEFTCONTROL},
        {KEY_A,                KM_A},
        {KEY_S,                KM_S},
        {KEY_D,                KM_D},
        {KEY_F,                KM_F},
        {KEY_G,                KM_G},
        {KEY_H,                KM_H},
        {KEY_J,                KM_J},
        {KEY_K,                KM_K},
        {KEY_L,                KM_L},
        {KEY_SEMICOLON,        KM_SEMICOLON_COLON},
        {KEY_APOSTROPHE,       KM_SINGLE_AND_DOUBLE_QUOTE},
        //{KEY_GRAVE,            KM_GRAVE_ACCENT_AND_TILDE},
        {KEY_LEFTSHIFT,        KM_LEFTSHIFT},
        {KEY_BACKSLASH,        KM_BACKSLASH_VERTICAL_BAR},
        {KEY_Z,                KM_Z},
        {KEY_X,                KM_X},
        {KEY_C,                KM_C},
        {KEY_V,                KM_V},
        {KEY_B,                KM_B},
        {KEY_N,                KM_N},
        {KEY_M,                KM_M},
        {KEY_COMMA,            KM_COMMA_AND_LESS},
        {KEY_DOT,              KM_DOT_GREATER},
        {KEY_SLASH,            KM_SLASH_QUESTION},
        {KEY_RIGHTSHIFT,       KM_RIGHTSHIFT},
        //KEY_KPASTERISK,       KM_KEYPAD_ASTERISK},
        {KEY_LEFTALT,          KM_LEFTALT},
        {KEY_SPACE,            KM_SPACEBAR},
        //{KEY_CAPSLOCK,         KM_CAPS_LOCK},
        {KEY_F1,               KM_F1},
        {KEY_F2,               KM_F2},
        {KEY_F3,               KM_F3},
        {KEY_F4,               KM_F4},
        {KEY_F5,               KM_F5},
        {KEY_F6,               KM_F6},
        {KEY_F7,               KM_F7},
        {KEY_F8,               KM_F8},
        {KEY_F9,               KM_F9},
        {KEY_F10,              KM_F10},
        {KEY_NUMLOCK,          KM_KEYPAD_NUM_LOCK_AND_CLEAR},
       // {KEY_SCROLLLOCK,       KM_SCROLL_LOCK},
        {KEY_KP7,              KM_KEYPAD_7_HOME},
        {KEY_KP8,              KM_KEYPAD_8_UP_ARROW},
        {KEY_KP9,              KM_KEYPAD_9_PAGEUP},
        {KEY_KPMINUS,          KM_KEYPAD_MINUS},
        {KEY_KP4,              KM_KEYPAD_4_LEFT_ARROW},
        {KEY_KP5,              KM_KEYPAD_5},
        {KEY_KP6,              KM_KEYPAD_6_RIGHT_ARROW},
        {KEY_KPPLUS,           KM_KEYPAD_PLUS},
        {KEY_KP1,              KM_KEYPAD_1_END},
        {KEY_KP2,              KM_KEYPAD_2_DOWN_ARROW},
        {KEY_KP3,              KM_KEYPAD_3_PAGEDN},
        {KEY_KP0,              KM_KEYPAD_0_INSERT},
        {KEY_KPDOT,            KM_KEYPAD_DECIMAL_SEPARATOR_DELETE},
        {KEY_ZENKAKUHANKAKU,   KM_NONE},
        {KEY_102ND,            KM_NONE},
        {KEY_F11,              KM_F11},
        {KEY_F12,              KM_F12},
        {KEY_KPENTER,          KM_KEYPAD_ENTER},
        {KEY_RIGHTCTRL,        KM_RIGHTCONTROL},
        {KEY_KPSLASH,          KM_KEYPAD_SLASH},
        {KEY_SYSRQ,            KM_SYSREQ},
        {KEY_RIGHTALT,         KM_RIGHTALT},
        {KEY_HOME,             KM_HOME},
        {KEY_UP,               KM_UPARROW},
        {KEY_PAGEUP,           KM_PAGEUP},
        {KEY_LEFT,             KM_LEFTARROW},
        {KEY_RIGHT,            KM_RIGHTARROW},
        {KEY_END,              KM_END1},
        {KEY_DOWN,             KM_DOWNARROW},
        {KEY_PAGEDOWN,         KM_PAGEDOWN},
        {KEY_INSERT,           KM_INSERT},
        {KEY_DELETE,           KM_DELETE},
        {KEY_PAUSE,            KM_PAUSE},
        {KEY_LEFTMETA,         KM_LEFT_GUI},
        {KEY_RIGHTMETA,        KM_RIGHT_GUI},
        {KEY_COMPOSE,          KM_NONE},
        {KEY_PLAYCD,           KM_NONE},
        {KEY_PAUSECD,          KM_NONE},
        {KEY_PROG3,            KM_NONE},
        {KEY_PROG4,            KM_NONE},
        //{KEY_ALL_APPLICATIONS, KM_NONE},
        {KEY_DASHBOARD,        KM_NONE},
        {KEY_SUSPEND,          KM_NONE},
        {KEY_CLOSE,            KM_NONE},
        {KEY_PLAY,             KM_NONE},
        {KEY_FASTFORWARD,      KM_NONE},
        {KEY_BASSBOOST,        KM_NONE},
        {KEY_PRINT,            KM_NONE},
        {KEY_HP,               KM_NONE},
        {KEY_CAMERA,           KM_NONE},
        {KEY_SOUND,            KM_NONE},
        {KEY_QUESTION,         KM_NONE},
        {KEY_EMAIL,            KM_NONE},
        {KEY_CHAT,             KM_NONE},
        {KEY_SEARCH,           KM_NONE},
        {KEY_CONNECT,          KM_NONE},
        {KEY_FINANCE,          KM_NONE},
        {KEY_SPORT,            KM_NONE},
        {KEY_SHOP,             KM_NONE},
        {KEY_ALTERASE,         KM_ALTERNATE_ERASE},
        {KEY_CANCEL,           KM_CANCEL},
        {KEY_BRIGHTNESSDOWN,   KM_NONE},
        {KEY_BRIGHTNESSUP,     KM_NONE},
        {KEY_MEDIA,            KM_NONE},
        {KEY_SWITCHVIDEOMODE,  KM_NONE},
        {KEY_KBDILLUMTOGGLE,   KM_NONE},
        {KEY_KBDILLUMDOWN,     KM_NONE},
        {KEY_KBDILLUMUP,       KM_NONE},
        {KEY_SEND,             KM_NONE},
        {KEY_REPLY,            KM_NONE},
        {KEY_FORWARDMAIL,      KM_NONE},
        {KEY_SAVE,             KM_NONE},
        {KEY_DOCUMENTS,        KM_NONE},
        {KEY_BATTERY,          KM_NONE},
        {KEY_BLUETOOTH,        KM_NONE},
        {KEY_WLAN,             KM_NONE},
        {KEY_UWB,              KM_NONE},
        {KEY_UNKNOWN,          KM_NONE},
        {KEY_VIDEO_NEXT,       KM_NONE},
        {KEY_VIDEO_PREV,       KM_NONE},
        {KEY_BRIGHTNESS_CYCLE, KM_NONE},
        {KEY_BRIGHTNESS_AUTO,  KM_NONE},
        {KEY_BRIGHTNESS_ZERO,  KM_NONE},
        {KEY_DISPLAY_OFF,      KM_NONE},
        {KEY_WWAN,             KM_NONE},
        {KEY_WIMAX,            KM_NONE},
        {KEY_RFKILL,           KM_NONE},
        {KEY_MICMUTE,          KM_NONE}
};

static const std::unordered_map<int, int> reverse_km_keyboard_map = {
        {KM_NONE,                     KEY_RESERVED},
        {KM_ESCAPE,                   KEY_ESC},
        {KM_1_EXCLAMATION_MARK,       KEY_1},
        {KM_2_AT,                     KEY_2},
        {KM_3_NUMBER_SIGN,            KEY_3},
        {KM_4_DOLLAR,                 KEY_4},
        {KM_5_PERCENT,                KEY_5},
        {KM_6_CARET,                  KEY_6},
        {KM_7_AMPERSAND,              KEY_7},
        {KM_8_ASTERISK,               KEY_8},
        {KM_9_OPARENTHESIS,           KEY_9},
        {KM_0_CPARENTHESIS,           KEY_0},
        {KM_MINUS_UNDERSCORE,         KEY_MINUS},
        {KM_EQUAL_PLUS,               KEY_EQUAL},
        {KM_BACKSPACE,                KEY_BACKSPACE},
        {KM_TAB,                      KEY_TAB},
        {KM_Q,                        KEY_Q},
        {KM_W,                        KEY_W},
        {KM_E,                        KEY_E},
        {KM_R,                        KEY_R},
        {KM_T,                        KEY_T},
        {KM_Y,                        KEY_Y},
        {KM_U,                        KEY_U},
        {KM_I,                        KEY_I},
        {KM_O,                        KEY_O},
        {KM_P,                        KEY_P},
        {KM_OBRACKET_AND_OBRACE,      KEY_LEFTBRACE},
        {KM_CBRACKET_AND_CBRACE,      KEY_RIGHTBRACE},
        {KM_ENTER,                    KEY_ENTER},
        {KM_LEFTCONTROL,              KEY_LEFTCTRL},
        {KM_A,                        KEY_A},
        {KM_S,                        KEY_S},
        {KM_D,                        KEY_D},
        {KM_F,                        KEY_F},
        {KM_G,                        KEY_G},
        {KM_H,                        KEY_H},
        {KM_J,                        KEY_J},
        {KM_K,                        KEY_K},
        {KM_L,                        KEY_L},
        {KM_SEMICOLON_COLON,          KEY_SEMICOLON},
        {KM_SINGLE_AND_DOUBLE_QUOTE,  KEY_APOSTROPHE},
        {KM_LEFTSHIFT,                KEY_LEFTSHIFT},
        {KM_BACKSLASH_VERTICAL_BAR,   KEY_BACKSLASH},
        {KM_Z,                        KEY_Z},
        {KM_X,                        KEY_X},
        {KM_C,                        KEY_C},
        {KM_V,                        KEY_V},
        {KM_B,                        KEY_B},
        {KM_N,                        KEY_N},
        {KM_M,                        KEY_M},
        {KM_COMMA_AND_LESS,           KEY_COMMA},
        {KM_DOT_GREATER,              KEY_DOT},
        {KM_SLASH_QUESTION,           KEY_SLASH},
        {KM_RIGHTSHIFT,               KEY_RIGHTSHIFT},
        {KM_LEFTALT,                  KEY_LEFTALT},
        {KM_SPACEBAR,                 KEY_SPACE},
        {KM_F1,                       KEY_F1},
        {KM_F2,                       KEY_F2},
        {KM_F3,                       KEY_F3},
        {KM_F4,                       KEY_F4},
        {KM_F5,                       KEY_F5},
        {KM_F6,                       KEY_F6},
        {KM_F7,                       KEY_F7},
        {KM_F8,                       KEY_F8},
        {KM_F9,                       KEY_F9},
        {KM_F10,                      KEY_F10},
        {KM_KEYPAD_NUM_LOCK_AND_CLEAR,KEY_NUMLOCK},
        {KM_KEYPAD_7_HOME,            KEY_KP7},
        {KM_KEYPAD_8_UP_ARROW,        KEY_KP8},
        {KM_KEYPAD_9_PAGEUP,          KEY_KP9},
        {KM_KEYPAD_MINUS,             KEY_KPMINUS},
        {KM_KEYPAD_4_LEFT_ARROW,      KEY_KP4},
        {KM_KEYPAD_5,                 KEY_KP5},
        {KM_KEYPAD_6_RIGHT_ARROW,     KEY_KP6},
        {KM_KEYPAD_PLUS,              KEY_KPPLUS},
        {KM_KEYPAD_1_END,             KEY_KP1},
        {KM_KEYPAD_2_DOWN_ARROW,      KEY_KP2},
        {KM_KEYPAD_3_PAGEDN,          KEY_KP3},
        {KM_KEYPAD_0_INSERT,          KEY_KP0},
        {KM_KEYPAD_DECIMAL_SEPARATOR_DELETE, KEY_KPDOT},
        {KM_F11,                      KEY_F11},
        {KM_F12,                      KEY_F12},
        {KM_KEYPAD_ENTER,             KEY_KPENTER},
        {KM_RIGHTCONTROL,             KEY_RIGHTCTRL},
        {KM_KEYPAD_SLASH,             KEY_KPSLASH},
        {KM_SYSREQ,                   KEY_SYSRQ},
        {KM_RIGHTALT,                 KEY_RIGHTALT},
        {KM_HOME,                     KEY_HOME},
        {KM_UPARROW,                  KEY_UP},
        {KM_PAGEUP,                   KEY_PAGEUP},
        {KM_LEFTARROW,                KEY_LEFT},
        {KM_RIGHTARROW,               KEY_RIGHT},
        {KM_END1,                     KEY_END},
        {KM_DOWNARROW,                KEY_DOWN},
        {KM_PAGEDOWN,                 KEY_PAGEDOWN},
        {KM_INSERT,                   KEY_INSERT},
        {KM_DELETE,                   KEY_DELETE},
        {KM_PAUSE,                    KEY_PAUSE},
        {KM_LEFT_GUI,                 KEY_LEFTMETA},
        {KM_RIGHT_GUI,                KEY_RIGHTMETA},
        {KM_ALTERNATE_ERASE,          KEY_ALTERASE},
        {KM_CANCEL,                   KEY_CANCEL}
};


// 定义点结构
struct Point {
    int x;
    int y;
};

const int control_key[8] = {KEY_LEFTCTRL,KEY_LEFTSHIFT,KEY_LEFTALT,KEY_LEFTMETA,
                    KEY_RIGHTCTRL,KEY_RIGHTSHIFT,KEY_RIGHTALT,KEY_RIGHTMETA};

#endif //DEMO_KMBOX_CMD_H
