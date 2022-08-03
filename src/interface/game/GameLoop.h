#pragma once

#include "../window/Window.h"
#include "../io/InputBridge.h"

class GameLoop : public InputBridge {
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

    virtual ~GameLoop();

public:
    virtual void Init();

    virtual void Reset();

    virtual void Update();

    virtual void Render();

    virtual void Go();

    virtual void HandleInput();

    virtual void Enable();

    virtual void Disable();

    void SendEvent(const Event &event) override = 0;
};