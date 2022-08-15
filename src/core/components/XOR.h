#pragma once

#include "Component.h"
#include "Wire.h"

namespace core::components {
    class XOR : public Component {
    private:
        Wire *input1 = nullptr;
        Wire *input2 = nullptr;
        Wire *output = nullptr;
    public:
        inline XOR(interface::gfx::Renderer *renderer, const lib::math::Vec2 &pos)
                : Component(renderer, pos, lib::math::Vec2(40, 40)) {}


        inline ~XOR() override {

        }

    public:
        void Update() override;

        void Render() override;
    };
}