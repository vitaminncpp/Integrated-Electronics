#pragma once

#include "Drawable.h"
#include "Image.h"

class Renderer {
private:
    Vec2 translate;
    Vec2 scale;
    double rotate = 0;
public:
    inline explicit Renderer() :
            translate(0, 0), scale(1, 1) {};

    virtual ~Renderer();

    virtual void Init();

    virtual void Reset();

    virtual void Present();

    virtual void Render(const Image &image);

    virtual void DrawLine(const Vec2 &v1, const Vec2 &v2);

    virtual void Scale(double s);

    virtual void Scale(const Vec2 &s);

    virtual void Translate(const Vec2 &d);

    virtual void Rotate(double t);

};