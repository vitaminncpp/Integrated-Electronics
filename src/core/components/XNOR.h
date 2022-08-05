#pragma once

#include "Component.h"

namespace core::components {
    class XNOR : public components::Component {
    private:
        components::Component *input1;
        components::Component *input2;
        components::Component *output;
    public:
        inline explicit XNOR(interface::gfx::Renderer *renderer, const lib::math::Vec2 &pos,
                             const lib::math::Vec2 &size)
                : core::components::Component(renderer, pos, size) {}

        ~XNOR();

        void Update() override;

        void Render() override;
    };
}