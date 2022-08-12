#pragma once

#include <memory>
#include <vector>
#include "components/Component.h"
#include "components/AND.h"
#include "components/OR.h"
#include "components/Wire.h"

namespace core {

    class Simulation {
    private:
        interface::gfx::Renderer *renderer;
        std::vector<core::components::Component *> components;
        int count = 0;
        components::Component *current = nullptr;

        int clock = 0;

    public:
        Simulation(interface::gfx::Renderer *renderer);

        inline int GetComponentCount() { return count; }

        inline void SetRenderer(interface::gfx::Renderer *renderer) { this->renderer = renderer; }

        ~Simulation();

    public:
        void Update();

        void Render();

        void DrawGrid();

        void TestCircuit();
    };
}
