#pragma once

#include "SDL_Image.h"

void SDL_Image::Render() {
    SDL_RenderCopy(renderer, texture, NULL, &rect);
}

SDL_Image::~SDL_Image() {
    if (texture != nullptr) {
        SDL_DestroyTexture(texture);
    } else {
        throw std::runtime_error("SDL_Image::~SDL_Image() - texture is nullptr");
    }
}