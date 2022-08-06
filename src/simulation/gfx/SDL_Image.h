#pragma once

#include <memory>
#include <string>
#include <SDL_render.h>
#include <SDL_image.h>
#include <stdexcept>
#include "../../interface/gfx/Image.h"
#include "../../lib/math/Vec2.h"


namespace simulation::gfx {

    class SDL_Image : public interface::gfx::Image {
    private:
        SDL_Renderer *renderer;
        SDL_Texture *texture;
        SDL_Rect rect{};

    public:
        explicit SDL_Image(SDL_Renderer *renderer, const lib::math::Vec2 &pos,
                           const lib::math::Vec2 &size,
                           std::string &imagePath);

        ~SDL_Image() override;

    };
}
