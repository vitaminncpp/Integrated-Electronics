#pragma once

#include "Component.h"
#include "Wire.h"

namespace core::components {
    class NOT : public Component {
    private:
        Wire *input = nullptr;
        Wire *output = nullptr;

    public:
        inline explicit NOT(interface::gfx::Renderer *renderer, const lib::math::Vec2 &pos)
                : Component(renderer, pos, lib::math::Vec2(25, 25)) {}

        inline ~NOT() override {

        };

    public:
        void Update() override;

        void Render() override;
    };
}