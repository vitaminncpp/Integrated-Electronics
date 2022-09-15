#include "SDL_Resource.h"

using namespace lib::math;
using namespace simulation::core;
using namespace simulation::gfx;

SDL_Resource::SDL_Resource(interface::gfx::Renderer *renderer)
        : Resource(renderer) {
    this->andImage = new SDL_Image(renderer, "res/gates/and.png", Vec2(0, 0), Vec2(122, 122));
    this->orImage = new SDL_Image(renderer, "res/gates/or.png", Vec2(0, 0), Vec2(40, 40));
}

SDL_Resource::~SDL_Resource() {
    if (this->andImage) {
        delete andImage;
    }
    if (this->orImage) {
        delete orImage;
    }
    if (this->notImage) {
        delete notImage;
    }
    if (this->xorImage) {
        delete xorImage;
    }
    if (this->xnorImage) {
        delete xnorImage;
    }
    if (this->dSrcImage) {
        delete dSrcImage;
    }
    if (this->dProbImage) {
        delete dProbImage;
    }
    if (this->switchImage) {
        delete switchImage;
    }
    if (this->andImage) {
        delete andImage;
    }
    if (this->clkImage) {
        delete clkImage;
    }
}
