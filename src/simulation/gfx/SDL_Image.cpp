
#include "SDL_Image.h"
#include "../../util/util.h"

using namespace lib::math;
using namespace interface::gfx;
using namespace simulation::gfx;


SDL_Image::SDL_Image(Renderer *renderer, const std::string &imagePath, const Vec2 &pos, const Vec2 &size)
        :
        Image(renderer, pos, size), texture(nullptr) {

    SDL_Surface *surface = SDL_LoadBMP(imagePath.c_str());
    texture = SDL_CreateTextureFromSurface(((SDL_Context *) this)->GetSDL_Renderer(), surface);

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
        LOG("SDL_Image::~SDL_Image() - texture is nullptr");
    }
}

SDL_Image::SDL_Image(interface::gfx::Renderer *renderer, const std::string &path) : Image(renderer, path) {

}
