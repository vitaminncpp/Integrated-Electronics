#pragma once

#include <SDL2/SDL_render.h>
#include "../../interface/gfx/Renderer.h"
#include "SDL_Image.h"

class SDL_Context : public Renderer {
private:
    SDL_Renderer *renderer;

    inline explicit SDL_Context(SDL_Renderer *renderer)
            : renderer(renderer) {
    }

    ~SDL_Context();

    void Render(const Image &image) override;

    void Init() override;

    void Reset() override;

    void Present() override;

    void DrawLine(const Vec2 &v1, const Vec2 &v2) override;

    void Scale(double s) override;

    void Scale(const Vec2 &s) override;

    void Translate(const Vec2 &d) override;
};