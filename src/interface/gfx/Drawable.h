#pragma once

#include "../../lib/math/Vec2.h"
#include "Renderer.h"


namespace interface::gfx {

    class Drawable {
    protected:
        interface::gfx::Renderer *renderer = nullptr;
        lib::math::Vec2 translate;
        lib::math::Vec2 scale;
        double rotation = 0;
    public:
        inline explicit Drawable(interface::gfx::Renderer *renderer)
                : renderer(renderer), translate(0, 0), scale(1, 1), rotation(0) {};

        virtual ~Drawable();

        inline void SetRenderer(interface::gfx::Renderer *renderer) {
            this->renderer = renderer;
        }

    public:
        virtual void Render();

        virtual void Scale(double s);

        virtual void Scale(const lib::math::Vec2 &s);

        virtual void Translate(const lib::math::Vec2 &d);

        virtual void Rotate(double t);

    };
}

