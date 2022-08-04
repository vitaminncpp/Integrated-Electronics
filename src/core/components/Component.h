#pragma once

#include "../../interface/gfx/Drawable.h"

class Component : public Drawable {
public:
    inline explicit Component() {};

    virtual ~Component();

    virtual void Render();

    virtual void Update();

};