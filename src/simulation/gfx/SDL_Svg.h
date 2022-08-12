#pragma once

#include "../../interface/gfx/Renderer.h"

#include <string>

namespace simulation::gfx {
    class SDL_Svg : public interface::gfx::Image {
    private:

    public:
        explicit SDL_Svg(interface::gfx::Renderer *renderer, const std::string &path);

        ~SDL_Svg() override;
    };
}