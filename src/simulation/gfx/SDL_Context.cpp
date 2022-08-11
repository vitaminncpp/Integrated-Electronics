#include "SDL_Context.h"

using namespace simulation::gfx;
using namespace interface::gfx;
using namespace lib::math;

SDL_Context::~SDL_Context() {
}

void SDL_Context::DrawImage(const Image &image) {
    Renderer::DrawImage(image);
}

void SDL_Context::Init() {
    Renderer::Init();
}

void SDL_Context::Reset() {
    Renderer::Reset();
}


void SDL_Context::DrawLine(const Vec2 &v1, const Vec2 &v2) {
    Renderer::DrawLine(v1, v2);
    SDL_RenderDrawLine(this->GetSDL_Renderer(),
                       v1.GetX() + fTranslate.GetX(), v1.GetY() + fTranslate.GetY(),
                       v2.GetX() + fTranslate.GetX(), v2.GetY() + fTranslate.GetY());
}

void SDL_Context::Scale(double s) {
    Renderer::Scale(s);
}

void SDL_Context::Scale(const Vec2 &center, double s) {
    Renderer::Scale(center, s);
}

void SDL_Context::Translate(const Vec2 &d) {
    Renderer::Translate(d);
}

void SDL_Context::Rotate(double t) {
    Renderer::Rotate(t);
}

void SDL_Context::DrawShape(const Shape &shape) {
    Renderer::DrawShape(shape);
}

void SDL_Context::SetColor(interface::gfx::Color color) {
    Renderer::SetColor(color);
    SDL_SetRenderDrawColor(this->GetSDL_Renderer(), color.GetR(), color.GetG(), color.GetB(), color.GetA());
}

void SDL_Context::BeginFrame() {
    Renderer::BeginFrame();
    SetColor(0);
    SDL_RenderClear(this->renderer);
}

void SDL_Context::Present() {
    Renderer::Present();
    SDL_RenderPresent(renderer);
}

void SDL_Context::DrawRect(int x, int y, int w, int h) {
    Renderer::DrawRect(x, y, w, h);
    SDL_Rect rect = {static_cast<int>(pos.GetX()),
                     static_cast<int>(pos.GetY()),
                     static_cast<int>(w * fScale.GetX()), static_cast<int>(h * fScale.GetY())};
    SDL_RenderFillRect(this->renderer, &rect);
}

void SDL_Context::DrawPoint(int x, int y) {
    Renderer::DrawPoint(x, y);
    SDL_RenderDrawPoint(this->renderer, this->pos.GetX(), this->pos.GetY());
}
