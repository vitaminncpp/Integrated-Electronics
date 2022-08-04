#pragma once

#include "../interface/game/GameLoop.h"


namespace game {

    class Game : public interface::game::GameLoop {
    private:

    public:
        inline explicit Game(interface::window::Window *window) : GameLoop(window) {
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

        void SendEvent(const interface::io::Event &event) override;
    };
}
