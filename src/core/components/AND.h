#pragma once

#include <memory>
#include "Wire.h"

namespace core::components {
    class AND : public Component {
    private:
        std::shared_ptr<Wire> input1;
        std::shared_ptr<Wire> input2;
        std::shared_ptr<Wire> output;
    public:
        AND(interface::gfx::Renderer *renderer, const lib::math::Vec2 &pos, const lib::math::Vec2 &size)
                : Component(renderer, pos, size) {}

        ~AND();

        void Update();

        void Render();

    };
}