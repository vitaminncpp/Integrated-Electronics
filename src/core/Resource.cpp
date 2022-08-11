#include "Resource.h"

using namespace core::resources;

void Resource::SetAndIcon(interface::gfx::Image *image) {
    Resource::andIcon = image;
}

void Resource::SetOrIcon(interface::gfx::Image *image) {
    Resource::orIcon = image;
}

void Resource::SetNotIcon(interface::gfx::Image *image) {
    Resource::notIcon = image;
}

void Resource::SetXnorIcon(interface::gfx::Image *image) {
    Resource::xnorIcon = image;
}

void Resource::SetXorIcon(interface::gfx::Image *image) {
    Resource::xorIcon = image;
}

void Resource::SetDProbecon(interface::gfx::Image *image) {
    Resource::dProbIcon = image;
}

void Resource::SetDSourceIcon(interface::gfx::Image *image) {
    Resource::dSourceIcon = image;
}

void Resource::SetClkIcon(interface::gfx::Image *image) {
    Resource::clkIcon = image;
}

void Resource::SetSwitchIcon(interface::gfx::Image *image) {
    Resource::switchIcon = image;
}
