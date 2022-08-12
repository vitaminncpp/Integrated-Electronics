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
        int length = 0;
    public:
        inline explicit Wire(interface::gfx::Renderer *renderer, const lib::math::Vec2 &start,
                             const lib::math::Vec2 &end)
                : core::components::Component(renderer, start, end) {}

        inline explicit Wire(interface::gfx::Renderer *renderer)
                : core::components::Component(renderer, lib::math::Vec2(0, 0), lib::math::Vec2(0, 0)) {}

        inline explicit Wire(interface::gfx::Renderer *renderer, const lib::math::Vec2 &start)
                : core::components::Component(renderer, start, lib::math::Vec2(0, 0)) {}

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

        inline void SetStart(const lib::math::Vec2 &start) {
            this->pos = start;
        }

        inline void SetEnd(const lib::math::Vec2 &end) {
            this->size = end;
        }

        void AddPath(const lib::math::Vec2 &v);
    };
}