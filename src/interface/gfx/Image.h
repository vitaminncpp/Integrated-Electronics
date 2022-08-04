#pragma once


#include "../../lib/math/Vec2.h"

namespace interface {
    namespace gfx {

        class Image {

        private:
            lib::math::Vec2 pos;
            lib::math::Vec2 size;
        public:
            inline explicit Image(const lib::math::Vec2 &pos, const lib::math::Vec2 &size)
                    : pos(pos), size(size) {

            }

            virtual ~Image();

            inline lib::math::Vec2 &GetPos() {
                return this->pos;
            }

            inline lib::math::Vec2 &GetSize() {
                return this->size;
            }
        };
    }
}
