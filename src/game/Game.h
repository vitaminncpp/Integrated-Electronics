#pragma once

#include "../interface/game/GameLoop.h"


namespace game {

    class Game : public interface::game::GameLoop {
    private:
        lib::math::Vec2 p1;
        lib::math::Vec2 p2;
    public:
        inline explicit Game(interface::window::Window *window)
                : GameLoop(window), p1(1, 2), p2(100, 30) {
            Init();

        }

        ~Game() override;

        void Update() override;

        void Render() override;

        void Init() override;

        void Reset() override;

        void Go() override;

        void Enable() override;

        void Disable() override;

        void SendEvent(const interface::io::Event &event) override;
    };
}
