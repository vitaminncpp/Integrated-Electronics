#pragma once

#include <SDL.h>
#include "../../lib/math/Vec2.h"
#include "Image.h"

class Drawable {
public:
    inline Drawable() {}

    virtual ~Drawable() = 0;

public:
    virtual void DrawLine(const Vec2 v1, const Vec2 v2) = 0;

    virtual void DrawImage(const Image image) = 0;

    virtual void DrawImage(const Image image, const Vec2 pos) = 0;

    virtual void Scale(const double s) = 0;

    virtual void Translate(const Vec2 &d) = 0;

    virtual void Rotate(const double t) = 0;

};