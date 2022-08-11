
#include "Renderer.h"

using namespace interface::gfx;
using namespace lib::math;

Renderer::~Renderer() {}

void Renderer::Init() {}

void Renderer::Reset() {}

void Renderer::Present() {}

void Renderer::DrawLine(const Vec2 &v1, const Vec2 &v2) {

}

void Renderer::Scale(double s) {
    this->fScale *= s;
}

void Renderer::Translate(const Vec2 &d) {
    this->fTranslate += d;
}

void Renderer::Rotate(double t) {
    this->rotation += t;
}

void Renderer::SetColor(Color color) {
    this->color = color;
}

void Renderer::DrawImage(const Image &image) {}

void Renderer::DrawShape(const interface::gfx::Shape &shape) {}

void Renderer::BeginFrame() {

}

void Renderer::DrawPoint(int x, int y) {
    PrePoss(x, y);
}

void Renderer::DrawRect(int x1, int y1, int x2, int y2) {
    PrePoss(x1, y1);
}

void Renderer::Scale(const Vec2 &center, double s) {
    this->fScale *= s;
    this->fScaleCenter = center;
}

void Renderer::PrePoss(int x, int y) {
    pos.SetXY(x, y);
    pos -= this->fScaleCenter;
    pos *= this->fScale;
    pos += this->fScaleCenter;

    pos += this->fTranslate;
}