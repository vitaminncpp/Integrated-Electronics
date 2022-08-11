#pragma once

#include "Component.h"
#include "Wire.h"

namespace core::components {
    class XNOR : public components::Component {
    private:
        Wire *input1;
        Wire *input2;
        Wire *output;
    public:
        inline explicit XNOR(interface::gfx::Renderer *renderer, const lib::math::Vec2 &pos,
                             const lib::math::Vec2 &size)
                : core::components::Component(renderer, pos, size) {}

        ~XNOR();

        void Update() override;

        void Render() override;
    };
}