cmake_minimum_required(VERSION 3.12.4)
project(demo)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -static -Wno-psabi")

set(CMAKE_FIND_ROOT_PATH ~/toolchain-sunxi-musl-gcc-830/toolchain)
set(CMAKE_FIND_ROOT_PATH_MODE_PACKAGE ONLY)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin)

include(${CMAKE_SOURCE_DIR}/3rdparty/3rdparty.cmake)

include_directories(include)
include_directories(include/hid)

add_subdirectory(src)
