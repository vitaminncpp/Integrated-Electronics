#pragma once

#include "../interface/game/GameLoop.h"

class Game : public GameLoop {
private:

public:
    inline explicit Game(Window *window) : GameLoop(window) {

    }

    void Update() override;

    void Render() override;

    void Init() override;

    void Reset() override;

    void Go() override;
};