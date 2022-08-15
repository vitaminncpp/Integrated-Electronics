#pragma once

#include "../../interface/gfx/Image.h"
#include "Component.h"
#include "Wire.h"

namespace core::components {
    class CLKDigital : public Component {
    private:
        bool value = false;
        Wire *output = nullptr;
    public:
        inline explicit CLKDigital(interface::gfx::Renderer *renderer, const lib::math::Vec2 &pos)
                : Component(renderer, pos, lib::math::Vec2(25, 25)) {
        }

        inline ~CLKDigital() override {

        }

        inline void SetImage(interface::gfx::Image *image) {
            this->image = image;
        }

    public:
        void Update() override;

        void Render() override;

        inline void Clock() {
            this->value = !value;
        }
    };
}