cmake_minimum_required(VERSION 3.22)

project(snake)

set(CMAKE_CXX_STANDARD 17)

add_subdirectory(ext/SDL)

add_executable(snake src/main.cpp src/game.cpp src/game.h src/window.cpp src/window.h src/controller.cpp src/controller.h src/snake.cpp src/snake.h)

target_link_libraries(snake SDL2 SDL2main)