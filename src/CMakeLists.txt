set(SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR})
file(GLOB SOURCE_FILES
        ${SOURCE_DIR}/*.cpp
        ${SOURCE_DIR}/ui/*.c
        ${SOURCE_DIR}/ui/**/*.c)

include_directories(${SOURCE_DIR}/ui)

add_executable(${PROJECT_NAME} ${SOURCE_FILES})

target_link_libraries(${PROJECT_NAME} PRIVATE lvgl::lvgl lv_drivers config ssl crypto)