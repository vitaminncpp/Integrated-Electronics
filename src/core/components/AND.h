#pragma once

#include <memory>
#include "Wire.h"

namespace core::components {
    class AND : public Component {
    private:
        Wire *input1 = nullptr;
        Wire *input2 = nullptr;
        Wire *output = nullptr;
    public:
        AND(interface::gfx::Renderer *renderer, const lib::math::Vec2 &pos, const lib::math::Vec2 &size)
                : Component(renderer, pos, size) {}

        inline ~AND() override {

        };

        void Update();

        void Render();

    };
}