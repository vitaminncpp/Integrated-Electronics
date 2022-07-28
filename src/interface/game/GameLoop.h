#pragma once

#include "../window/Window.h"

class GameLoop {
private:
    bool isRunning = false;
    Window *window;
public:
    inline explicit GameLoop(Window *window) {
        this->window = window;
    }

    inline Window *GetWindow() const {
        return this->window;
    }

    inline bool IsRunning() const {
        return this->isRunning;
    }

    virtual ~GameLoop() = 0;

public:
    virtual void Init();

    virtual void Reset();

    virtual void Update();

    virtual void Render();

    virtual void Go();
};