#ifndef SUN_KEYBOARD_H
#define SUN_KEYBOARD_H

#include <cstdint>
#include <unordered_map>
#include <linux/input-event-codes.h>
#include "uart.h"

#define HID_NONE         200    // 空 (None)
#define HID_LEFTCTRL     0      // LEFT CTRL
#define HID_LEFTSHIFT    1      // LEFT SHIFT
#define HID_LEFTALT      2      // LEFT ALT
#define HID_LEFTMETA     3      // LEFT WIN
#define HID_RIGHTCTRL    4      // RIGHT CTRL
#define HID_RIGHTSHIFT   5      // RIGHT SHIFT
#define HID_RIGHTALT     6      // RIGHT ALT
#define HID_RIGHTMETA    7      // RIGHT WIN
#define HID_A            16     // a
#define HID_B            17     // b
#define HID_C            18     // c
#define HID_D            19     // d
#define HID_E            20     // e
#define HID_F            21     // f
#define HID_G            22     // g
#define HID_H            23     // h
#define HID_I            24     // i
#define HID_J            25     // j
#define HID_K            26     // k
#define HID_L            27     // l
#define HID_M            28     // m
#define HID_N            29     // n
#define HID_O            30     // o
#define HID_P            31     // p
#define HID_Q            32     // q
#define HID_R            33     // r
#define HID_S            34     // s
#define HID_T            35     // t
#define HID_U            36     // u
#define HID_V            37     // v
#define HID_W            38     // w
#define HID_X            39     // x
#define HID_Y            40     // y
#define HID_Z            41     // z
#define HID_1            42     // 1
#define HID_2            43     // 2
#define HID_3            44     // 3
#define HID_4            45     // 4
#define HID_5            46     // 5
#define HID_6            47     // 6
#define HID_7            48     // 7
#define HID_8            49     // 8
#define HID_9            50     // 9
#define HID_0            51     // 0
#define HID_ENTER        52     // ENTER
#define HID_ESC          53     // esc
#define HID_BACKSPACE    54     // 退格 (Backspace)
#define HID_TAB          55     // tab
#define HID_SPACE        56     // SPACE
#define HID_MINUS        57     // -
#define HID_EQUAL        58     // =
#define HID_LEFTBRACE    59     // {
#define HID_RIGHTBRACE   60     // }
#define HID_BACKSLASH    61     // '\'
#define HID_SEMICOLON    63     // ;
#define HID_APOSTROPHE   64     // '
#define HID_GRAVE        65     // ~
#define HID_COMMA        66     // ,
#define HID_DOT          67     // .
#define HID_SLASH        68     // /
#define HID_CAPSLOCK     69     // CAPS LOCK
#define HID_F1           70     // F1
#define HID_F2           71     // F2
#define HID_F3           72     // F3
#define HID_F4           73     // F4
#define HID_F5           74     // F5
#define HID_F6           75     // F6
#define HID_F7           76     // F7
#define HID_F8           77     // F8
#define HID_F9           78     // F9
#define HID_F10          79     // F10
#define HID_F11          80     // F11
#define HID_F12          81     // F12
#define HID_SYSRQ        82     // PRINT SCREEN
#define HID_SCROLLLOCK   83     // SCROLL LOCK
#define HID_PAUSE        84     // PAUSE BREAK
#define HID_INSERT       85     // INSERT
#define HID_HOME         86     // HOME
#define HID_PAGEUP       87     // PAGEUP
#define HID_DELETE       88     // DELETE
#define HID_END          89     // END
#define HID_PAGEDOWN     90     // PAGEDOWN
#define HID_RIGHT        91     // RIGHT
#define HID_LEFT         92     // LEFT
#define HID_DOWN         93     // DOWN
#define HID_UP           94     // UP
#define HID_NUMLOCK      95     // KP NUM LOCK
#define HID_KPSLASH      96     // KP '/'
#define HID_KPASTERISK   97     // KP *
#define HID_KPMINUS      98     // KP -
#define HID_KPPLUS       99     // KP +
#define HID_KPENTER      100    // KP ENTER
#define HID_KP1          101    // KP 1
#define HID_KP2          102    // KP 2
#define HID_KP3          103    // KP 3
#define HID_KP4          104    // KP 4
#define HID_KP5          105    // KP 5
#define HID_KP6          106    // KP 6
#define HID_KP7          107    // KP 7
#define HID_KP8          108    // KP 8
#define HID_KP9          109    // KP 9
#define HID_KP0          110    // KP 0
#define HID_KPDOT        111    // KP .

static const std::unordered_map<int, int> keyboard_map = {
        {KEY_RESERVED,         HID_NONE},
        {KEY_ESC,              HID_ESC},
        {KEY_1,                HID_1},
        {KEY_2,                HID_2},
        {KEY_3,                HID_3},
        {KEY_4,                HID_4},
        {KEY_5,                HID_5},
        {KEY_6,                HID_6},
        {KEY_7,                HID_7},
        {KEY_8,                HID_8},
        {KEY_9,                HID_9},
        {KEY_0,                HID_0},
        {KEY_MINUS,            HID_MINUS},
        {KEY_EQUAL,            HID_EQUAL},
        {KEY_BACKSPACE,        HID_BACKSPACE},
        {KEY_TAB,              HID_TAB},
        {KEY_Q,                HID_Q},
        {KEY_W,                HID_W},
        {KEY_E,                HID_E},
        {KEY_R,                HID_R},
        {KEY_T,                HID_T},
        {KEY_Y,                HID_Y},
        {KEY_U,                HID_U},
        {KEY_I,                HID_I},
        {KEY_O,                HID_O},
        {KEY_P,                HID_P},
        {KEY_LEFTBRACE,        HID_LEFTBRACE},
        {KEY_RIGHTBRACE,       HID_RIGHTBRACE},
        {KEY_ENTER,            HID_ENTER},
        {KEY_LEFTCTRL,         HID_LEFTCTRL},
        {KEY_A,                HID_A},
        {KEY_S,                HID_S},
        {KEY_D,                HID_D},
        {KEY_F,                HID_F},
        {KEY_G,                HID_G},
        {KEY_H,                HID_H},
        {KEY_J,                HID_J},
        {KEY_K,                HID_K},
        {KEY_L,                HID_L},
        {KEY_SEMICOLON,        HID_SEMICOLON},
        {KEY_APOSTROPHE,       HID_APOSTROPHE},
        {KEY_GRAVE,            HID_GRAVE},
        {KEY_LEFTSHIFT,        HID_LEFTSHIFT},
        {KEY_BACKSLASH,        HID_BACKSLASH},
        {KEY_Z,                HID_Z},
        {KEY_X,                HID_X},
        {KEY_C,                HID_C},
        {KEY_V,                HID_V},
        {KEY_B,                HID_B},
        {KEY_N,                HID_N},
        {KEY_M,                HID_M},
        {KEY_COMMA,            HID_COMMA},
        {KEY_DOT,              HID_DOT},
        {KEY_SLASH,            HID_SLASH},
        {KEY_RIGHTSHIFT,       HID_RIGHTSHIFT},
        {KEY_KPASTERISK,       HID_KPASTERISK},
        {KEY_LEFTALT,          HID_LEFTALT},
        {KEY_SPACE,            HID_SPACE},
        {KEY_CAPSLOCK,         HID_CAPSLOCK},
        {KEY_F1,               HID_F1},
        {KEY_F2,               HID_F2},
        {KEY_F3,               HID_F3},
        {KEY_F4,               HID_F4},
        {KEY_F5,               HID_F5},
        {KEY_F6,               HID_F6},
        {KEY_F7,               HID_F7},
        {KEY_F8,               HID_F8},
        {KEY_F9,               HID_F9},
        {KEY_F10,              HID_F10},
        {KEY_NUMLOCK,          HID_NUMLOCK},
        {KEY_SCROLLLOCK,       HID_SCROLLLOCK},
        {KEY_KP7,              HID_KP7},
        {KEY_KP8,              HID_KP8},
        {KEY_KP9,              HID_KP9},
        {KEY_KPMINUS,          HID_KPMINUS},
        {KEY_KP4,              HID_KP4},
        {KEY_KP5,              HID_KP5},
        {KEY_KP6,              HID_KP6},
        {KEY_KPPLUS,           HID_KPPLUS},
        {KEY_KP1,              HID_KP1},
        {KEY_KP2,              HID_KP2},
        {KEY_KP3,              HID_KP3},
        {KEY_KP0,              HID_KP0},
        {KEY_KPDOT,            HID_KPDOT},
        {KEY_ZENKAKUHANKAKU,   HID_NONE},
        {KEY_102ND,            HID_NONE},
        {KEY_F11,              HID_F11},
        {KEY_F12,              HID_F12},
//        {KEY_RO,               HID_NONE},
//        {KEY_KATAKANA,         HID_NONE},
//        {KEY_HIRAGANA,         HID_NONE},
//        {KEY_HENKAN,           HID_NONE},
//        {KEY_KATAKANAHIRAGANA, HID_NONE},
//        {KEY_MUHENKAN,         HID_NONE},
//        {KEY_KPJPCOMMA,        HID_NONE},
        {KEY_KPENTER,          HID_KPENTER},
        {KEY_RIGHTCTRL,        HID_RIGHTCTRL},
        {KEY_KPSLASH,          HID_KPSLASH},
        {KEY_SYSRQ,            HID_SYSRQ},
        {KEY_RIGHTALT,         HID_RIGHTALT},
//        {KEY_LINEFEED,         HID_NONE},
        {KEY_HOME,             HID_HOME},
        {KEY_UP,               HID_UP},
        {KEY_PAGEUP,           HID_PAGEUP},
        {KEY_LEFT,             HID_LEFT},
        {KEY_RIGHT,            HID_RIGHT},
        {KEY_END,              HID_END},
        {KEY_DOWN,             HID_DOWN},
        {KEY_PAGEDOWN,         HID_PAGEDOWN},
        {KEY_INSERT,           HID_INSERT},
        {KEY_DELETE,           HID_DELETE},
//        {KEY_MACRO,            HID_NONE},
//        {KEY_MUTE,             HID_NONE},
//        {KEY_VOLUMEDOWN,       HID_NONE},
//        {KEY_VOLUMEUP,         HID_NONE},
//        {KEY_POWER,            HID_NONE},
//        {KEY_KPEQUAL,          HID_NONE},
//        {KEY_KPPLUSMINUS,      HID_NONE},
        {KEY_PAUSE,            HID_PAUSE},
//        {KEY_SCALE,            HID_NONE},
//        {KEY_KPCOMMA,          HID_NONE},
//        {KEY_HANGEUL,          HID_NONE},
//        {KEY_HANGUEL,          HID_NONE},
//        {KEY_HANJA,            HID_NONE},
//        {KEY_YEN,              HID_NONE},
        {KEY_LEFTMETA,         HID_LEFTMETA},
        {KEY_RIGHTMETA,        HID_RIGHTMETA},
        {KEY_COMPOSE,          HID_NONE},
//        {KEY_STOP,             HID_NONE},
//        {KEY_AGAIN,            HID_NONE},
//        {KEY_PROPS,            HID_NONE},
//        {KEY_UNDO,             HID_NONE},
//        {KEY_FRONT,            HID_NONE},
//        {KEY_COPY,             HID_NONE},
//        {KEY_OPEN,             HID_NONE},
//        {KEY_PASTE,            HID_NONE},
//        {KEY_FIND,             HID_NONE},
//        {KEY_CUT,              HID_NONE},
//        {KEY_HELP,             HID_NONE},
//        {KEY_MENU,             HID_NONE},
//        {KEY_CALC,             HID_NONE},
//        {KEY_SETUP,            HID_NONE},
//        {KEY_SLEEP,            HID_NONE},
//        {KEY_WAKEUP,           HID_NONE},
//        {KEY_FILE,             HID_NONE},
//        {KEY_SENDFILE,         HID_NONE},
//        {KEY_DELETEFILE,       HID_NONE},
//        {KEY_XFER,             HID_NONE},
//        {KEY_PROG1,            HID_NONE},
//        {KEY_PROG2,            HID_NONE},
//        {KEY_WWW,              HID_NONE},
//        {KEY_MSDOS,            HID_NONE},
//        {KEY_COFFEE,           HID_NONE},
//        {KEY_SCREENLOCK,       HID_NONE},
//        {KEY_ROTATE_DISPLAY,   HID_NONE},
//        {KEY_DIRECTION,        HID_NONE},
//        {KEY_CYCLEWINDOWS,     HID_NONE},
//        {KEY_MAIL,             HID_NONE},
//        {KEY_BOOKMARKS,        HID_NONE},
//        {KEY_COMPUTER,         HID_NONE},
//        {KEY_BACK,             HID_NONE},
//        {KEY_FORWARD,          HID_NONE},
//        {KEY_CLOSECD,          HID_NONE},
//        {KEY_EJECTCD,          HID_NONE},
//        {KEY_EJECTCLOSECD,     HID_NONE},
//        {KEY_NEXTSONG,         HID_NONE},
//        {KEY_PLAYPAUSE,        HID_NONE},
//        {KEY_PREVIOUSSONG,     HID_NONE},
//        {KEY_STOPCD,           HID_NONE},
//        {KEY_RECORD,           HID_NONE},
//        {KEY_REWIND,           HID_NONE},
//        {KEY_PHONE,            HID_NONE},
//        {KEY_ISO,              HID_NONE},
//        {KEY_CONFIG,           HID_NONE},
//        {KEY_HOMEPAGE,         HID_NONE},
//        {KEY_REFRESH,          HID_NONE},
//        {KEY_EXIT,             HID_NONE},
//        {KEY_MOVE,             HID_NONE},
//        {KEY_EDIT,             HID_NONE},
//        {KEY_SCROLLUP,         HID_NONE},
//        {KEY_SCROLLDOWN,       HID_NONE},
//        {KEY_KPLEFTPAREN,      HID_NONE},
//        {KEY_KPRIGHTPAREN,     HID_NONE},
//        {KEY_NEW,              HID_NONE},
//        {KEY_REDO,             HID_NONE},
//        {KEY_F13,              HID_NONE},
//        {KEY_F14,              HID_NONE},
//        {KEY_F15,              HID_NONE},
//        {KEY_F16,              HID_NONE},
//        {KEY_F17,              HID_NONE},
//        {KEY_F18,              HID_NONE},
//        {KEY_F19,              HID_NONE},
//        {KEY_F20,              HID_NONE},
//        {KEY_F21,              HID_NONE},
//        {KEY_F22,              HID_NONE},
//        {KEY_F23,              HID_NONE},
//        {KEY_F24,              HID_NONE},
//        {KEY_PLAYCD,           HID_NONE},
//        {KEY_PAUSECD,          HID_NONE},
//        {KEY_PROG3,            HID_NONE},
//        {KEY_PROG4,            HID_NONE},
//        {KEY_ALL_APPLICATIONS, HID_NONE},
//        {KEY_DASHBOARD,        HID_NONE},
//        {KEY_SUSPEND,          HID_NONE},
//        {KEY_CLOSE,            HID_NONE},
//        {KEY_PLAY,             HID_NONE},
//        {KEY_FASTFORWARD,      HID_NONE},
//        {KEY_BASSBOOST,        HID_NONE},
//        {KEY_PRINT,            HID_NONE},
//        {KEY_HP,               HID_NONE},
//        {KEY_CAMERA,           HID_NONE},
//        {KEY_SOUND,            HID_NONE},
//        {KEY_QUESTION,         HID_NONE},
//        {KEY_EMAIL,            HID_NONE},
//        {KEY_CHAT,             HID_NONE},
//        {KEY_SEARCH,           HID_NONE},
//        {KEY_CONNECT,          HID_NONE},
//        {KEY_FINANCE,          HID_NONE},
//        {KEY_SPORT,            HID_NONE},
//        {KEY_SHOP,             HID_NONE},
//        {KEY_ALTERASE,         HID_NONE},
//        {KEY_CANCEL,           HID_NONE},
//        {KEY_BRIGHTNESSDOWN,   HID_NONE},
//        {KEY_BRIGHTNESSUP,     HID_NONE},
//        {KEY_MEDIA,            HID_NONE},
//        {KEY_SWITCHVIDEOMODE,  HID_NONE},
//        {KEY_KBDILLUMTOGGLE,   HID_NONE},
//        {KEY_KBDILLUMDOWN,     HID_NONE},
//        {KEY_KBDILLUMUP,       HID_NONE},
//        {KEY_SEND,             HID_NONE},
//        {KEY_REPLY,            HID_NONE},
//        {KEY_FORWARDMAIL,      HID_NONE},
//        {KEY_SAVE,             HID_NONE},
//        {KEY_DOCUMENTS,        HID_NONE},
//        {KEY_BATTERY,          HID_NONE},
//        {KEY_BLUETOOTH,        HID_NONE},
//        {KEY_WLAN,             HID_NONE},
//        {KEY_UWB,              HID_NONE},
//        {KEY_UNKNOWN,          HID_NONE},
//        {KEY_VIDEO_NEXT,       HID_NONE},
//        {KEY_VIDEO_PREV,       HID_NONE},
//        {KEY_BRIGHTNESS_CYCLE, HID_NONE},
//        {KEY_BRIGHTNESS_AUTO,  HID_NONE},
//        {KEY_BRIGHTNESS_ZERO,  HID_NONE},
//        {KEY_DISPLAY_OFF,      HID_NONE},
//        {KEY_WWAN,             HID_NONE},
//        {KEY_WIMAX,            HID_NONE},
//        {KEY_RFKILL,           HID_NONE},
//        {KEY_MICMUTE,          HID_NONE}
};

class Keyboard {
private:
    struct KeyboardData {
        uint8_t fdr[4];
        uint8_t code;
        uint8_t value;
    } __attribute__((packed, aligned(1)));

    KeyboardData keyboardData = {
            {0xAC, 0xCA, 0x03, 0x00},
            0x00,
            0x00
    };

    void sendData() {
        Uart::GetInstance().write(reinterpret_cast<uint8_t *>(&keyboardData), sizeof(KeyboardData));
    }

public:
    void passThrough(uint16_t code, uint8_t value) {
        uint8_t k_code = HID_NONE;
        auto it = keyboard_map.find(code);
        if (it != keyboard_map.end()) {
            k_code = static_cast<uint8_t>(it->second);
        }

        this->keyboardData.code = k_code;
        this->keyboardData.value = value;
        sendData();
    }

    void reset() {
        this->keyboardData.code = 0xFF;
        sendData();
    }

};

#endif //SUN_KEYBOARD_H
