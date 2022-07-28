cmake_minimum_required(VERSION 3.16)
project(Simulated_Electronics)

set(CMAKE_CXX_STANDARD 17)
find_package(SDL2 REQUIRED)

add_executable(Simulation src/main/main.cpp src/gui/GameWindow.cpp src/gui/GameWindow.h src/util/util.h src/game/Game.cpp src/game/Game.h src/sim/Simulation.cpp src/sim/Simulation.h src/interface/gfx/Drawable.h src/lib/math/Vec2.cpp src/lib/math/Vec2.h src/interface/gfx/Image.h src/interface/game/GameLoop.h src/interface/window/Window.h src/interface/io/Input.h src/interface/game/GameLoop.cpp src/interface/window/Window.cpp src/interface/io/Input.cpp src/interface/io/InputBridge.cpp src/interface/io/InputBridge.h)

target_link_libraries(Simulation PRIVATE SDL2::SDL2 SDL2::SDL2main SDL2::SDL2-static)
