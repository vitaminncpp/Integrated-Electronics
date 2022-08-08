#pragma once

#include "../interface/game/GameLoop.h"
#include "../core/Simulation.h"
#include "State.h"

namespace game {

    class Game : public interface::game::GameLoop {
    private:
        core::Simulation simulation;
        State state;
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

        void SendEvent(const interface::io::Event &event) override;
    };
}
