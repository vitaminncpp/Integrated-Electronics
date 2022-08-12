#pragma once

#include "../gfx/SDL_Image.h"
#include "../../core/Resource.h"

namespace simulation::core {
    class SDL_Resource : public ::core::resources::Resource {
    public:
        explicit SDL_Resource(interface::gfx::Renderer *renderer);

        ~SDL_Resource() override;
    };
}