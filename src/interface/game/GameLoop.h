#pragma once

#include "../interface/window/Window.h"

class GameLoop {
private:
    Window *window;
public:
    inline GameLoop(Window *window) {
        this->window = window;
    }

    virtual ~GameLoop() = 0;

public:
    virtual void Init() = 0;

    virtual void Reset() = 0;

    virtual void Update() = 0;

    virtual void Render() = 0;

    virtual void Go();
};