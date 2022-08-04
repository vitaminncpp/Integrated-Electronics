#pragma once


#include "../../lib/math/Vec2.h"
#include "Drawable.h"

class Image {

private:
    Vec2 pos;
    Vec2 size;
public:
    inline explicit Image(const Vec2 &pos, const Vec2 &size)
            : pos(pos), size(size) {

    }

    virtual ~Image();

    inline Vec2 &GetPos() {
        return this->pos;
    }

    inline Vec2 &GetSize() {
        return this->size;
    }
};