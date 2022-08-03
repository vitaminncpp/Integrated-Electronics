#pragma once


#include "../../lib/math/Vec2.h"
#include "Drawable.h"

class Image : public Drawable {

private:
    Vec2 pos;
    Vec2 size;
public:
    inline explicit Image(const Vec2 &pos, const Vec2 &size)
            : pos(pos), size(size) {

    }

    inline Vec2 &GetPos() {
        return this->pos;
    }

    inline Vec2 &GetSize() {
        return this->size;
    }

    void Render() override;

    ~Image() override;

    void Scale(double s) override;

    void Scale(const Vec2 &s) override;

    void Translate(const Vec2 &d) override;

    void Rotate(double t) override;

};