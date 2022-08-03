#pragma once

#include "../interface/game/GameLoop.h"

class Game : public GameLoop {
private:

public:
    inline explicit Game(Window *window) : GameLoop(window) {
        Init();
    }

    inline ~Game() {
    }

    void Update() override;

    void Render() override;

    void Init() override;

    void Reset() override;

    void Go() override;

    void Enable() override;

    void Disable() override;

    void SendEvent(const Event &event) override;
};