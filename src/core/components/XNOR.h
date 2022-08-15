#pragma once

#include "Component.h"
#include "Wire.h"

namespace core::components {
    class XNOR : public components::Component {
    private:
        Wire *input1 = nullptr;
        Wire *input2 = nullptr;
        Wire *output = nullptr;
    public:
        inline explicit XNOR(interface::gfx::Renderer *renderer, const lib::math::Vec2 &pos)
                : core::components::Component(renderer, pos, lib::math::Vec2(25, 25)) {}

        ~XNOR();

        void Update() override;

        void Render() override;
    };
}