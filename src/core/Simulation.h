#pragma once

#include <memory>
#include <vector>
#include "components/Component.h"
#include "components/AND.h"
#include "components/OR.h"
#include "components/Wire.h"
#include "Resource.h"
#include "util/State.h"

namespace core {

    class Simulation {
    private:
        interface::gfx::Renderer *renderer = nullptr;
        std::vector<core::components::Component *> components;
        int count = 0;
        components::Component *current = nullptr;
        resources::Resource *resource = nullptr;
        util::State state;
        int clock = 0;

    public:
        Simulation(interface::gfx::Renderer *renderer, resources::Resource *resource);

        inline int GetComponentCount() { return count; }

        inline void SetRenderer(interface::gfx::Renderer *renderer) { this->renderer = renderer; }

        ~Simulation();

        inline void SetResource(resources::Resource *resource) {
            this->resource = resource;
        }

        void InitWire(const lib::math::Vec2 &v);

        void RelocateWire(const lib::math::Vec2 &pos);

        inline void AddCurrent() {
            if (this->current) {
                this->components.push_back(this->current);
                this->current = nullptr;
            }
        }

        inline void SetXY(int x, int y) {
            this->state.SetXY(x, y);
        }

    public:
        void Update();

        void Render();

        void DrawGrid();

        void TestCircuit();
    };
}
