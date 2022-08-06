#pragma once

#include "../interface/game/GameLoop.h"
#include "../core/Simulation.h"

namespace game {

    class Game : public interface::game::GameLoop {
    private:
        core::Simulation simulation;
    public:
        inline explicit Game(interface::window::Window *window)
                : GameLoop(window), simulation(nullptr) {
            Init();
            simulation.SetRenderer(GetRenderer());
        }

        ~Game() override;

        void SetRenderer(interface::gfx::Renderer *renderer) override;

        void Update() override;

        void Render() override;

        void Init() override;

        void Reset() override;

        void Go() override;

        void Enable() override;

        void Disable() override;

        void SendEvent(interface::io::Event *event) override;
    };
}
