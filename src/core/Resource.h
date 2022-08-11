#pragma once

#include "../interface/gfx/Image.h"

namespace core::resources {
    class Resource {
    private:
        static interface::gfx::Image *andIcon;
        static interface::gfx::Image *orIcon;
        static interface::gfx::Image *notIcon;
        static interface::gfx::Image *xorIcon;
        static interface::gfx::Image *xnorIcon;
        static interface::gfx::Image *dSourceIcon;
        static interface::gfx::Image *dProbIcon;
        static interface::gfx::Image *clkIcon;
        static interface::gfx::Image *switchIcon;

    public:
        static void SetAndIcon(interface::gfx::Image *image);

        static void SetOrIcon(interface::gfx::Image *image);

        static void SetNotIcon(interface::gfx::Image *image);

        static void SetXorIcon(interface::gfx::Image *image);

        static void SetXnorIcon(interface::gfx::Image *image);

        static void SetIcon(interface::gfx::Image *image);

        static void SetDSourceIcon(interface::gfx::Image *image);

        static void SetDProbecon(interface::gfx::Image *image);

        static void SetSwitchIcon(interface::gfx::Image *image);

        static void SetClkIcon(interface::gfx::Image *image);
    };
}