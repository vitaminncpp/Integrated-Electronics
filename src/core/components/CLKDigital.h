#pragma once

#include "../../interface/gfx/Image.h"
#include "Component.h"
#include "Wire.h"

namespace core::components {
    class CLKDigital : public Component {
    private:
        bool value = false;
        interface::gfx::Image *image = nullptr;
        Wire *output = nullptr;
    public:
        inline explicit CLKDigital(interface::gfx::Renderer *renderer, const lib::math::Vec2 &pos,
                                   const lib::math::Vec2 &size)
                : Component(renderer, pos, size) {
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