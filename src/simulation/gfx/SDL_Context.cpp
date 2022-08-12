#include "SDL_Context.h"

using namespace simulation::gfx;
using namespace interface::gfx;
using namespace lib::math;

SDL_Context::~SDL_Context() {
}

void SDL_Context::DrawImage(interface::gfx::Image *image) {
    Renderer::DrawImage(image);
}

void SDL_Context::DrawImage(interface::gfx::Image *image, const Vec2 &pos) {
    Renderer::DrawImage(image, pos);
    SDL_Rect rect = {static_cast<int>(this->pos.GetX()), static_cast<int>(this->pos.GetY()),
                     static_cast<int>(image->GetSize().GetX() * this->fScale.GetX()),
                     static_cast<int>(image->GetSize().GetY() * this->fScale.GetY())};
    SDL_RenderCopy(this->renderer, ((SDL_Image *) image)->GetSDL_Texture(), nullptr, &rect);
}

void SDL_Context::DrawImage(interface::gfx::Image *image, const Vec2 &pos, const Vec2 &size) {
    Renderer::DrawImage(image, pos, size);
}

void SDL_Context::Init() {
    Renderer::Init();
}

void SDL_Context::Reset() {
    Renderer::Reset();
}

void SDL_Context::DrawLine(const Vec2 &v1, const Vec2 &v2) {
    Renderer::DrawLine(v1, v2);
    Vec2 end = v2 - v1;
    end *= this->fScale;
    end += this->pos;
    SDL_RenderDrawLine(this->GetSDL_Renderer(),
                       pos.GetX(), pos.GetY(),
                       end.GetX(), end.GetY());
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

void SDL_Context::SetColor(const interface::gfx::Color &color) {
    Renderer::SetColor(color);
    SDL_SetRenderDrawColor(this->GetSDL_Renderer(), color.GetR(), color.GetG(), color.GetB(), color.GetA());
}

void SDL_Context::BeginFrame() {
    Renderer::BeginFrame();
    SetColor(255);
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

void SDL_Context::DrawRect(const Vec2 &pos, const Vec2 &size) {
    Renderer::DrawRect(pos, size);
    SDL_Rect rect = {static_cast<int>(pos.GetX()),
                     static_cast<int>(pos.GetY()),
                     static_cast<int>(size.GetX() * fScale.GetX()), static_cast<int>(size.GetY() * fScale.GetY())};
    SDL_RenderFillRect(this->renderer, &rect);
}
