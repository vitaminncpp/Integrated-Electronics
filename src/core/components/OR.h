#pragma once

#include "Component.h"
#include "Wire.h"

namespace core::components {
    class OR : public Component {
    private:
        Wire *input1 = nullptr;
        Wire *input2 = nullptr;
        Wire *output = nullptr;

    public:
        inline explicit OR(interface::gfx::Renderer *renderer, const lib::math::Vec2 &pos)
                : Component(renderer, pos, lib::math::Vec2(25, 25)) {}

        inline ~OR() override {

        }

        void Update() override;

        void Render() override;
    };
}