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
        bool value = false;
        int length;
    public:
        Wire(interface::gfx::Renderer *renderer, const lib::math::Vec2 &start, const lib::math::Vec2 &end)
                : core::components::Component(renderer, start, end) {}

        inline ~Wire() override {

        }

    public:
        void Render() override;

        void Update() override;

        inline bool GetValue() {
            return this->value;
        }

        inline void SetValue(bool value) {
            this->value = value;
        }

        void AddPath(const lib::math::Vec2 &v);
    };
}