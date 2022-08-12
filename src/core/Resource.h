#pragma once

#include "../interface/gfx/Image.h"
#include "../interface/gfx/Renderer.h"

namespace core::resources {
    class Resource {
    protected:
        interface::gfx::Renderer *renderer = nullptr;
        interface::gfx::Image *andImage = nullptr;
        interface::gfx::Image *orImage = nullptr;
        interface::gfx::Image *notImage = nullptr;
        interface::gfx::Image *xorImage = nullptr;
        interface::gfx::Image *xnorImage = nullptr;
        interface::gfx::Image *dSrcImage = nullptr;
        interface::gfx::Image *dProbImage = nullptr;
        interface::gfx::Image *clkImage = nullptr;
        interface::gfx::Image *switchImage = nullptr;

    public:
        inline explicit Resource(interface::gfx::Renderer *renderer)
                : renderer(renderer) {}

        virtual ~Resource();

        interface::gfx::Image *GetAndImage();
    };
}