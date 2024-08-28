#include <termios.h>
#include <fcntl.h>
#include <unistd.h>
#include "uart.h"

Uart::Uart() = default;

Uart::~Uart() {
    if (m_uart > 0) {
        close(m_uart);
        std::cout << "[Uart] 串口已关闭。"<< std::endl;
    }
}

void Uart::init() {
    m_uart = open("/dev/ttyS1", O_RDWR | O_NOCTTY);
    if (m_uart < 0) {
        std::cerr << "[Uart] 无法打开串口 " << std::endl;
        return;
    }

    termios tio{};
    if (tcgetattr(m_uart, &tio) < 0) {
        std::cerr << "[Uart] 获取属性失败 " << std::endl;
        close(m_uart);
        return;
    }

    cfsetispeed(&tio, B1500000);
    cfsetospeed(&tio, B1500000);

    tio.c_cflag &= ~(CSIZE | CSTOPB | PARENB | INPCK);
    tio.c_cflag |= (CS8 | CLOCAL | CREAD);
    tio.c_lflag &= ~(ICANON | ECHO | ECHOE | ISIG);
    tio.c_oflag &= ~(OPOST | ONLCR | OCRNL);
    tio.c_iflag &= ~(ICRNL | INLCR | IXON | IXOFF | IXANY);
    tio.c_cc[VTIME] = 0;
    tio.c_cc[VMIN] = 0;

    if (tcsetattr(m_uart, TCSANOW, &tio) < 0) {
        std::cerr << "[Uart] 设置属性失败: " << std::endl;
        close(m_uart);
        return;
    }

    std::cout << "[Uart] 串口初始化成功。" << std::endl;
}

void Uart::write(uint8_t *buf, uint16_t len) const {
    ::write(m_uart, buf, len);
}

ssize_t Uart::read(void *buf, ssize_t buffer_size) const {
    ssize_t len = ::read(m_uart, buf, buffer_size);
    return len;
}
