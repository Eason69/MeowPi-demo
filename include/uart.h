#ifndef SUN_UART_H
#define SUN_UART_H

#include <cstdint>
#include <cstdio>
#include <iostream>

class Uart {
public:
    static Uart &GetInstance() {
        static Uart instance;
        return instance;
    }

    void init();

    void write(uint8_t *buf, uint16_t len) const;

    ssize_t read(void *buf, ssize_t buffer_size) const;

    Uart(const Uart &) = delete;

    Uart &operator=(const Uart &) = delete;

private:

    Uart();

    ~Uart();

    int m_uart = -1;
};

#endif //SUN_UART_H