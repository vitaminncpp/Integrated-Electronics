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
        inline explicit OR(interface::gfx::Renderer *renderer, const lib::math::Vec2 &pos, const lib::math::Vec2 &size)
                : Component(renderer, pos, size) {}

        inline ~OR() override {

        }

        void Update() override;

        void Render() override;
    };
}