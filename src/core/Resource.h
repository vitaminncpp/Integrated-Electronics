#pragma once

#include "../interface/gfx/Image.h"
#include "../interface/gfx/Renderer.h"

namespace core::resources {
    class Resource {
    protected:
        interface::gfx::Renderer *renderer = nullptr;
        interface::gfx::Image *andIcon = nullptr;
        interface::gfx::Image *orIcon = nullptr;
        interface::gfx::Image *notIcon = nullptr;
        interface::gfx::Image *xorIcon = nullptr;
        interface::gfx::Image *xnorIcon = nullptr;
        interface::gfx::Image *dSourceIcon = nullptr;
        interface::gfx::Image *dProbIcon = nullptr;
        interface::gfx::Image *clkIcon = nullptr;
        interface::gfx::Image *switchIcon = nullptr;

    public:
        inline explicit Resource(interface::gfx::Renderer *renderer)
                : renderer(renderer) {}

        virtual ~Resource();
    };
}