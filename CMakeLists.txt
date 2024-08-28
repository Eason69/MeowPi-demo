cmake_minimum_required(VERSION 3.12.4)
project(demo)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin)

include(${CMAKE_SOURCE_DIR}/3rdparty/3rdparty.cmake)

include_directories(include)
include_directories(include/hid)

#set(CMAKE_C_COMPILER "/home/book/MeowPi_tool/toolchain-sunxi-musl/toolchain/bin/arm-openwrt-linuxmuslgnueabi-gcc")
link_directories(/home/book/MeowPi_tool/lib)
include_directories(/home/book/MeowPi_tool/include/)
include_directories(/home/book/MeowPi_tool/include/allwinner/)
include_directories(/home/book/MeowPi_tool/include/allwinner/include)

add_subdirectory(src)
