#pragma once

#include "../../lib/math/Vec2.h"

class Drawable {
public:
    inline explicit Drawable() {};

    virtual ~Drawable();

public:
    virtual void Render();

    virtual void Scale(double s);

    virtual void Scale(const Vec2 &s);

    virtual void Translate(const Vec2 &d);

    virtual void Rotate(double t);

};