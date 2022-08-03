#pragma once

#include "Drawable.h"

class Renderer {
public:
    inline explicit Renderer() {};

    virtual ~Renderer();

    virtual void Init();

    virtual void Reset();

    virtual void Present();

    virtual void Render(Drawable *drawable);
};