#pragma once

#include "../../lib/math/Vec2.h"
#include "Renderer.h"

class Drawable {
protected:
    Renderer *renderer = nullptr;
public:
    inline explicit Drawable(Renderer *renderer)
            : renderer(renderer) {};

    virtual ~Drawable();

    inline void SetRenderer(Renderer *renderer) {
        this->renderer = renderer;
    }

public:
    virtual void Render();

    virtual void Scale(double s);

    virtual void Scale(const Vec2 &s);

    virtual void Translate(const Vec2 &d);

    virtual void Rotate(double t);

};