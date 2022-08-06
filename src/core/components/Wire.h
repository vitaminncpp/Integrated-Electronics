#pragma once

#include <memory>
#include <vector>
#include "Component.h"

namespace core::components {
    class Wire : public core::components::Component {
    private:
        core::components::Component *input;
        core::components::Component *output;
        std::vector<lib::math::Vec2> path;
        int length;
    public:
        Wire(interface::gfx::Renderer *renderer, const lib::math::Vec2 &start, const lib::math::Vec2 &end)
                : core::components::Component(renderer, start, end) {}

        ~Wire();

    public:
        void Render() override;

        void Update() override;
    };
}