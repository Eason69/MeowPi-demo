#ifndef SUN_KEYBOARD_H
#define SUN_KEYBOARD_H

#include <cstdint>
#include <unordered_map>
#include <linux/input-event-codes.h>

class Keyboard {
private:


public:
    void passThrough(uint16_t code, uint8_t value) {
        //你的发送逻辑

    }

    void reset() {
        //你的发送逻辑

    }

};

#endif //SUN_KEYBOARD_H
