
#include "Drawable.h"

using namespace interface::gfx;
using namespace lib::math;

Drawable::~Drawable() {}

void Drawable::Render() {}

void Drawable::Scale(const Vec2 &s) {
    this->scale *= s;
}

void Drawable::Scale(double s) {
    this->scale *= s;
}

void Drawable::Translate(const Vec2 &d) {
    this->translate += d;
}

void Drawable::Rotate(double t) {
    this->rotation += t;
}