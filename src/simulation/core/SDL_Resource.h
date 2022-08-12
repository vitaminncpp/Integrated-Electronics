#pragma once

#include "../gfx/SDL_Image.h"
#include "../../core/Resource.h"

namespace simulation::core {
    class SDL_Resource : public ::core::resources::Resource {
    public:
        inline explicit SDL_Resource(interface::gfx::Renderer *renderer)
                : Resource(renderer) {
            this->andIcon = new simulation::gfx::SDL_Image(renderer, "res/and.png");
            this->orIcon = new simulation::gfx::SDL_Image(renderer, "res/or.png");
        }
    };
}