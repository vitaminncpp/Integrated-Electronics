#pragma once

#include <memory>
#include <vector>
#include "components/Component.h"

namespace core {

    class Simulation {
    private:
        interface::gfx::Renderer *renderer;
        std::vector<std::shared_ptr<core::components::Component>> components;
        int count = 0;
        std::shared_ptr<components::Component> current;

        int clock = 0;

    public:
        Simulation(interface::gfx::Renderer *renderer);

        inline int GetComponentCount() { return count; }

        ~Simulation();

    public:
        void Update();

        void Render();

        void Clock();
    };
}
