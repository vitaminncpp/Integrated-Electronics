#pragma once

#include <memory>
#include <SDL2/SDL_render.h>
#include "../../interface/gfx/Renderer.h"
#include "SDL_Image.h"


namespace simulation::gfx {

    class SDL_Context : public interface::gfx::Renderer {
    private:
        SDL_Renderer *renderer;
    public:
        inline explicit SDL_Context(SDL_Renderer *renderer)
                : renderer(renderer), Renderer() {
        }

        inline SDL_Renderer *GetSDL_Renderer() const {
            return this->renderer;
        }

        ~SDL_Context();

        void DrawImage(const interface::gfx::Image &image) override;

        void Init() override;

        void Reset() override;

        void Present() override;

        void DrawLine(const lib::math::Vec2 &v1, const lib::math::Vec2 &v2) override;

        void Scale(double s) override;

        void Scale(const lib::math::Vec2 &s) override;

        void Translate(const lib::math::Vec2 &d) override;

        void Rotate(double t) override;

        void DrawShape(const interface::gfx::Shape &shape) override;

        void SetColor(interface::gfx::Color color) override;

        void BeginFrame() override;
    };
}