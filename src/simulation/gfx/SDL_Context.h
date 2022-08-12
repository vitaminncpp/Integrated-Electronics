#pragma once

#include <memory>
#include <SDL2/SDL_render.h>
#include "../../interface/gfx/Renderer.h"
#include "SDL_Image.h"


namespace simulation::gfx {

    class SDL_Context : public interface::gfx::Renderer {
    private:
        SDL_Renderer *renderer = nullptr;
    public:
        inline explicit SDL_Context(SDL_Renderer *renderer)
                : renderer(renderer), Renderer() {
        }

        inline SDL_Renderer *GetSDL_Renderer() const {
            return this->renderer;
        }


        ~SDL_Context();

        void DrawImage(interface::gfx::Image *image) override;

        void DrawImage(interface::gfx::Image *image, const lib::math::Vec2 &pos) override;

        void DrawImage(interface::gfx::Image *image, const lib::math::Vec2 &pos, const lib::math::Vec2 &size) override;

        void Init() override;

        void Reset() override;

        void Present() override;

        void DrawLine(const lib::math::Vec2 &v1, const lib::math::Vec2 &v2) override;

        void Scale(double s) override;

        void Scale(const lib::math::Vec2 &center, double s) override;

        void Translate(const lib::math::Vec2 &d) override;

        void Rotate(double t) override;

        void DrawShape(const interface::gfx::Shape &shape) override;

        void DrawRect(int x1, int y1, int x2, int y2) override;

        void DrawRect(const lib::math::Vec2 &pos, const lib::math::Vec2 &size) override;

        void SetColor(const interface::gfx::Color &color) override;

        void BeginFrame() override;

        void DrawPoint(int x, int y) override;

    };
}