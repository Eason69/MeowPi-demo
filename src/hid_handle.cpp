#include "hid_handle.h"

extern std::atomic<bool> is_stop;

hidhandle::hidhandle() {

}

hidhandle::~hidhandle() {
    hidhandleJoin();
}

void hidhandle::hidhandleStart() {
    m_calculate_thread = std::thread([this] { calculate(); });
}

void hidhandle::hidhandleJoin() {
    if (m_calculate_thread.joinable()) {
        m_calculate_thread.join();
    }
}

void hidhandle::calculate() {
    while (!is_stop) {

        std::this_thread::sleep_for(std::chrono::milliseconds (10));
    }
}

