#pragma once

#include "../../interface/gfx/Drawable.h"

class SDL_Drawable : public Drawable {
private:
    SDL_Renderer *renderer;
    const Vec2 translate = Vec2(0, 0);
    const Vec2 scale = Vec2(1, 1);
public:
    inline explicit SDL_Drawable(SDL_Renderer *renderer)
            : renderer(renderer) {

    }

    inline ~SDL_Drawable() override {

    }

    void DrawLine(const Vec2 &v1, const Vec2 &v2) override;

    void Scale(double s) override;

    void Translate(const Vec2 &d) override;

    void Rotate(double t) override;

};