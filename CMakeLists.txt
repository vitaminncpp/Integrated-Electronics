cmake_minimum_required(VERSION 3.16)
project(Simulated_Electronics)

set(CMAKE_CXX_STANDARD 17)
find_package(SDL2 REQUIRED)

add_executable(Simulation 
                src/main/main.cpp
                src/gui/GameWindow.cpp
                src/game/Game.cpp 
                src/sim/Simulation.cpp
                src/lib/math/Vec2.cpp
                src/interface/game/GameLoop.cpp
                src/interface/window/Window.cpp
                src/interface/io/Input.cpp
                src/interface/io/InputBridge.cpp)

target_link_libraries(Simulation PRIVATE SDL2::SDL2 SDL2::SDL2main SDL2::SDL2-static)
