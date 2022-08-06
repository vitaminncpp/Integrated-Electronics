#pragma once

#include "Image.h"
#include "Color.h"
#include "Shape.h"

namespace interface::gfx {

    class Renderer {
    protected:
        lib::math::Vec2 translate;
        lib::math::Vec2 scale;
        double rotation = 0;
        Color color;

    public:
        inline explicit Renderer() :
                translate(0, 0), scale(1, 1), color(0) {};

        virtual ~Renderer();

        virtual void Init();

        virtual void Reset();

        virtual void BeginFrame();

        virtual void Present();

        virtual void DrawImage(const Image &image);

        virtual void DrawLine(const lib::math::Vec2 &v1, const lib::math::Vec2 &v2);

        virtual void Scale(double s);

        virtual void SetColor(Color color);

        virtual void Scale(const lib::math::Vec2 &s);

        virtual void Translate(const lib::math::Vec2 &d);

        virtual void Rotate(double t);

        virtual void DrawShape(const Shape &shape);

        virtual void DrawPoint(int i, int i1);

        virtual void DrawRect(int x1, int y1, int x2, int y2);
    };
}
