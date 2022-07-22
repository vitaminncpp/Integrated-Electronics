cmake_minimum_required(VERSION 3.16)
project(Simulated_Electronics)

set(CMAKE_CXX_STANDARD 17)
find_package(SDL2 REQUIRED)

add_executable(Simulation src/main.cpp src/gui/Window.cpp src/gui/Window.h)

target_link_libraries(Simulation PRIVATE SDL2::SDL2 SDL2::SDL2main SDL2::SDL2-static)
