cmake_minimum_required(VERSION 3.16)
project(Simulated_Electronics)

set(CMAKE_CXX_STANDARD 17)
find_package(SDL2 REQUIRED)

add_executable(Simulation
        src/main/main.cpp
        src/gui/window/GameWindow.cpp
        src/game/Game.cpp
        src/sim/Simulation.cpp
        src/lib/math/Vec2.cpp
        src/interface/game/GameLoop.cpp
        src/interface/window/Window.cpp
        src/interface/io/Input.cpp
        src/interface/io/Event.cpp
        src/interface/io/Event.h
        src/interface/gfx/Drawable.h
        src/interface/gfx/Image.h
        src/gui/gfx/SDL_Drawable.cpp
        src/gui/gfx/SDL_Drawable.h
        src/gui/gfx/SDL_Image.cpp
        src/gui/gfx/SDL_Image.h src/interface/gfx/Renderer.cpp src/interface/gfx/Renderer.h src/interface/gfx/Drawable.cpp src/interface/gfx/Image.cpp)


target_link_libraries(Simulation PRIVATE SDL2::SDL2 SDL2::SDL2main SDL2::SDL2-static)
