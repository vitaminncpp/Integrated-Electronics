#include "SDL_Svg.h"

using namespace simulation::gfx;

SDL_Svg::SDL_Svg(interface::gfx::Renderer *renderer, const std::string &path)
        : interface::gfx::Image(renderer, path) {

}

SDL_Svg::~SDL_Svg() noexcept {

}
