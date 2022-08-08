cmake_minimum_required(VERSION 3.16)
project(Simulated_Electronics)

set(CMAKE_CXX_STANDARD 17)
find_package(SDL2 REQUIRED)

add_executable(Simulation
        src/main/main.cpp
        src/simulation/window/GameWindow.cpp
        src/game/Game.cpp
        src/core/Simulation.cpp
        src/lib/math/Vec2.cpp
        src/lib/math/Vec2.h
        src/lib/math/util.cpp
        src/lib/math/util.h
        src/interface/game/GameLoop.cpp
        src/interface/window/Window.cpp
        src/interface/io/Input.cpp
        src/interface/io/Event.h
        src/interface/gfx/Drawable.h
        src/interface/gfx/Image.h
        src/simulation/gfx/SDL_Image.cpp
        src/simulation/gfx/SDL_Image.h
        src/interface/gfx/Renderer.cpp
        src/interface/gfx/Renderer.h
        src/interface/gfx/Drawable.cpp
        src/interface/gfx/Image.cpp
        src/core/components/Component.cpp
        src/core/components/Component.h
        src/simulation/gfx/SDL_Context.cpp
        src/simulation/gfx/SDL_Context.h
        src/interface/gfx/Color.h src/interface/gfx/Shape.cpp src/interface/gfx/Shape.h src/core/components/Wire.cpp src/core/components/Wire.h src/core/components/AND.cpp src/core/components/AND.h src/core/components/OR.cpp src/core/components/OR.h src/core/components/NOT.cpp src/core/components/NOT.h src/core/components/XOR.cpp src/core/components/XOR.h src/core/components/XNOR.cpp src/core/components/XNOR.h src/game/State.h)


target_link_libraries(Simulation PRIVATE SDL2::SDL2 SDL2::SDL2main)
