cmake_minimum_required(VERSION 3.10)
project(OOP_Project)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp Player.cpp Player.h Game_Manager.cpp Game_Manager.h Bullet.cpp Bullet.h UI.cpp UI.h)
add_executable(OOP_Project ${SOURCE_FILES})


set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake_modules" ${CMAKE_MODULE_PATH}})
find_package(SFML 2 REQUIRED system window graphics network audio)

find_package(TGUI 0.7 REQUIRED)

target_link_libraries(OOP_Project ${TGUI_LIBRARY} ${SFML_LIBRARIES})