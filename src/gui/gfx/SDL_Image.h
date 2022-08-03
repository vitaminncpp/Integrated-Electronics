#pragma once

#include <string>
#include <SDL_render.h>
#include <SDL_image.h>
#include <stdexcept>
#include "../../interface/gfx/Image.h"
#include "../../lib/math/Vec2.h"

class SDL_Image : public Image {
private:
    SDL_Renderer *renderer;
    SDL_Texture *texture;
    SDL_Rect rect{};

public:
    inline explicit SDL_Image(SDL_Renderer *renderer, const Vec2 &pos, const Vec2 &size, std::string &imagePath) :
            Image(pos, size), renderer(renderer), texture(nullptr) {
        SDL_Surface *surface = SDL_LoadBMP(imagePath.c_str());
        texture = SDL_CreateTextureFromSurface(this->renderer, surface);

        rect.x = pos.GetX();
        rect.y = pos.GetY();
        rect.w = size.GetX();
        rect.h = size.GetY();

        SDL_FreeSurface(surface);
    }

    ~SDL_Image() override;

    void Render() override;
};