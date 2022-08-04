
#include "SDL_Image.h"

using namespace simulation::gfx;
using namespace lib::math;

SDL_Image::SDL_Image(SDL_Renderer *renderer, const Vec2 &pos, const Vec2 &size, std::string &imagePath) :
        Image(pos, size), renderer(renderer), texture(nullptr) {
    SDL_Surface *surface = SDL_LoadBMP(imagePath.c_str());
    texture = SDL_CreateTextureFromSurface(this->renderer, surface);

    rect.x = pos.GetX();
    rect.y = pos.GetY();
    rect.w = size.GetX();
    rect.h = size.GetY();

    SDL_FreeSurface(surface);
}

SDL_Image::~SDL_Image() {
    if (texture != nullptr) {
        SDL_DestroyTexture(texture);
    } else {
        throw std::runtime_error("SDL_Image::~SDL_Image() - texture is nullptr");
    }
}