#pragma once

#include <string>
#include "../../lib/math/Vec2.h"

namespace interface::gfx {
    class Renderer;
}

namespace interface::gfx {
    class Image {
    protected:
        lib::math::Vec2 pos;
        lib::math::Vec2 size;
        Renderer *renderer = nullptr;
        std::string path;

    public:
        inline explicit Image(const lib::math::Vec2 &pos, const lib::math::Vec2 &size, const std::string &path)
                : pos(pos), size(size) {}

        inline explicit Image(interface::gfx::Renderer *renderer, const std::string &path)
                : renderer(renderer), path(path) {}

        inline explicit Image(interface::gfx::Renderer *renderer, const lib::math::Vec2 &pos,
                              const lib::math::Vec2 &size)
                : renderer(renderer), pos(pos), size(size) {}

        virtual ~Image();

        inline lib::math::Vec2 &GetPos() {
            return this->pos;
        }

        inline lib::math::Vec2 &GetSize() {
            return this->size;
        }

        inline interface::gfx::Renderer *GetRenderer() {
            return this->renderer;
        }
    };
}
