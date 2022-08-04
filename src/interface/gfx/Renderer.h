#pragma once

#include "Image.h"


namespace interface::gfx {

    class Renderer {
    protected:
        lib::math::Vec2 translate;
        lib::math::Vec2 scale;
        double rotation = 0;

    public:
        inline explicit Renderer() :
                translate(0, 0), scale(1, 1) {};

        virtual ~Renderer();

        virtual void Init();

        virtual void Reset();

        virtual void Present();

        virtual void Render(const Image &image);

        virtual void DrawLine(const lib::math::Vec2 &v1, const lib::math::Vec2 &v2);

        virtual void Scale(double s);

        virtual void Scale(const lib::math::Vec2 &s);

        virtual void Translate(const lib::math::Vec2 &d);

        virtual void Rotate(double t);

    };
}
