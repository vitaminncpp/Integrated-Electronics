#pragma once

#include "../interface/game/GameLoop.h"
#include "../core/Simulation.h"
#include "../simulation/core/SDL_Resource.h"
#include "State.h"

namespace game {

    class Game : public interface::game::GameLoop {
    private:
        core::Simulation *simulation;
        State state;
        core::resources::Resource *resource;
    public:
        explicit Game(interface::window::Window *window, interface::gfx::Renderer *renderer);

        Game(const Game &game);

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
