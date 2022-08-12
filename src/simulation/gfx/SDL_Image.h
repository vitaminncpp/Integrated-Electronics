#pragma once

#include <memory>
#include <string>
#include <SDL_render.h>
#include <SDL_image.h>
#include <stdexcept>
#include "../../interface/gfx/Image.h"
#include "../../lib/math/Vec2.h"
#include "SDL_Context.h"


namespace simulation::gfx {

    class SDL_Image : public interface::gfx::Image {
    private:
        SDL_Texture *texture;
        SDL_Rect rect{};

    public:
        explicit SDL_Image(interface::gfx::Renderer *renderer, const std::string &imagePath, const lib::math::Vec2 &pos,
                           const lib::math::Vec2 &size);

        explicit SDL_Image(interface::gfx::Renderer *renderer, const std::string &path);

        ~SDL_Image() override;

        inline SDL_Texture *GetSDL_Texture() const {
            return this->texture;
        }

        inline SDL_Rect *GetSDL_Rect() const {
            return (SDL_Rect *) &this->rect;
        }
    };
}
