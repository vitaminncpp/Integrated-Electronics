#pragma once

#include "Image.h"
#include "Color.h"
#include "Shape.h"

namespace interface::gfx {

    class Renderer {
    protected:
        lib::math::Vec2 fTranslate;
        lib::math::Vec2 fScale;
        lib::math::Vec2 fScaleCenter;
        lib::math::Vec2 pos;
        double rotation = 0;
        Color color;

    public:
        inline explicit Renderer() :
                fTranslate(0, 0), fScale(1, 1), color(0) {};

        virtual ~Renderer();

        virtual void Init();

        virtual void Reset();

        virtual void BeginFrame();

        virtual void Present();

        virtual void DrawImage(Image *image);

        virtual void DrawImage(Image *image, const lib::math::Vec2 &pos);

        virtual void DrawImage(Image *image, const lib::math::Vec2 &pos, const lib::math::Vec2 &size);

        virtual void DrawLine(const lib::math::Vec2 &v1, const lib::math::Vec2 &v2);

        virtual void Scale(double s);

        virtual void SetColor(const Color &color);

        virtual void Scale(const lib::math::Vec2 &center, double s);

        virtual void Translate(const lib::math::Vec2 &d);

        virtual void Rotate(double t);

        virtual void DrawShape(const Shape &shape);

        virtual void DrawPoint(int i, int i1);

        virtual void DrawRect(int x1, int y1, int x2, int y2);

        virtual void DrawRect(const lib::math::Vec2 &pos, const lib::math::Vec2 &size);


    private:

        void PrePoss(const lib::math::Vec2 &pos);

        void PrePoss(int x, int y);
    };
}
