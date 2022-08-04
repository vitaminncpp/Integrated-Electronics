#pragma once

#include "../../lib/math/Vec2.h"
#include "Renderer.h"


namespace interface::gfx {

    class Drawable {
    protected:
        interface::gfx::Renderer *renderer = nullptr;
    public:
        inline explicit Drawable(interface::gfx::Renderer *renderer)
                : renderer(renderer) {};

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

