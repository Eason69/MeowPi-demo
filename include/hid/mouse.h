#ifndef SUN_MOUSE_H
#define SUN_MOUSE_H

#include <cstdint>

class Mouse{
private:


public:
    void passThrough(uint8_t code, uint8_t value1) {
        //你的发送逻辑
    }

    void passThrough(uint8_t code, uint8_t value1, uint8_t value2) {
        //你的发送逻辑
    }

    void reset() {
        //你的发送逻辑
    }

};

#endif //SUN_MOUSE_H
