#ifndef SUN_MOUSE_H
#define SUN_MOUSE_H

#include <cstdint>
#include "uart.h"

class Mouse{
private:
    struct MouseData {
        uint8_t fdr[4];
        uint8_t code;
        uint8_t value1;
        uint8_t value2;
    } __attribute__((packed, aligned(1)));

    MouseData mouseData = {
            {0xAC, 0xCA, 0x04, 0x01},
            0x00,
            0x00,
            0x00
    };

    void sendData() {
        Uart::GetInstance().write(reinterpret_cast<uint8_t *>(&mouseData), sizeof(MouseData));
    }

public:
    void passThrough(uint8_t code, uint8_t value1) {
        this->mouseData.code = code;
        this->mouseData.value1 = value1;
        sendData();
    }

    void passThrough(uint8_t code, uint8_t value1, uint8_t value2) {
        this->mouseData.code = code;
        this->mouseData.value1 = value1;
        this->mouseData.value2 = value2;
        sendData();
    }

    void reset() {
        this->mouseData.code = 0xFF;
        sendData();
    }

};

#endif //SUN_MOUSE_H
