
#include "Renderer.h"

using namespace interface::gfx;
using namespace lib::math;

Renderer::~Renderer() {}

void Renderer::Init() {}

void Renderer::Reset() {}

void Renderer::Present() {}

void Renderer::DrawLine(const Vec2 &v1, const Vec2 &v2) {}

void Renderer::Scale(double s) {}

void Renderer::Scale(const Vec2 &s) {
    this->scale *= s;
}

void Renderer::Translate(const Vec2 &d) {
    this->translate += d;
}

void Renderer::Rotate(double t) {
    this->rotation += t;
}

void Renderer::Render(const Image &image) {}
