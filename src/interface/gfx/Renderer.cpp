
#include "Renderer.h"

using namespace interface::gfx;
using namespace lib::math;

Renderer::~Renderer() {}

void Renderer::Init() {}

void Renderer::Reset() {}

void Renderer::Present() {}

void Renderer::DrawLine(const Vec2 &v1, const Vec2 &v2) {
    this->PrePoss(v1);
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

void Renderer::SetColor(const Color &color) {
    this->color = color;
}

void Renderer::DrawImage(Image *image) {
    PrePoss(image->GetPos());
}

void Renderer::DrawImage(Image *image, const Vec2 &pos) {
    PrePoss(pos);
}

void Renderer::DrawImage(Image *image, const Vec2 &pos, const Vec2 &size) {
    PrePoss(pos);
}

void Renderer::DrawShape(const interface::gfx::Shape &shape) {}

void Renderer::BeginFrame() {

}

void Renderer::DrawPoint(int x, int y) {
    PrePoss(x, y);
}

void Renderer::FillRect(int x1, int y1, int x2, int y2) {
    PrePoss(Vec2(x1, y1));
}

void Renderer::Scale(const Vec2 &center, double s) {
    this->fScale *= s;
    this->fTranslate -= this->fScaleCenter * (this->fScale - 1) / 2;
}

void Renderer::PrePoss(int x, int y) {
    this->pos.SetXY(x, y);
    this->pos -= this->fScaleCenter;
    this->pos *= this->fScale;
    this->pos += this->fScaleCenter;

    this->pos += this->fTranslate;
}

void Renderer::PrePoss(const Vec2 &pos) {
    this->pos = pos;
    this->pos -= this->fScaleCenter;
    this->pos *= this->fScale;
    this->pos += this->fScaleCenter;

    this->pos += this->fTranslate;
}

void Renderer::FillRect(const Vec2 &pos, const Vec2 &size) {
    PrePoss(pos);
}

Vec2 &Renderer::SetMousePosition(Vec2 &v) {
    v -= this->fTranslate;
    v -= this->fScaleCenter;
    v /= this->fScale;
    v += this->fScaleCenter;
    return v;
}

void Renderer::DrawRect(const Vec2 &pos, const Vec2 &size) {
    PrePoss(pos);
}
