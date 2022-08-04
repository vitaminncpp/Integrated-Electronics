#pragma once

#include "../../interface/gfx/Drawable.h"


namespace core::components {

    class Component : public interface::gfx::Drawable {
    public:
        inline explicit Component(interface::gfx::Renderer *renderer) : Drawable(renderer) {};

        virtual ~Component();

        virtual void Render();

        virtual void Update();

    };
}