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
    SDL_Rect rect = {static_cast<int>(pos.GetX() + this->fTranslate.GetX()),
                     static_cast<int>(pos.GetY() + this->fTranslate.GetY()),
                     static_cast<int>(image->GetSize().GetX()),
                     static_cast<int>(image->GetSize().GetY())};
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

    SDL_RenderDrawLine(this->GetSDL_Renderer(),
                       v1.GetX() + this->fTranslate.GetX(), v1.GetY() + this->fTranslate.GetY(),
                       v2.GetX() + this->fTranslate.GetX(), v2.GetY() + this->fTranslate.GetY());
}

void SDL_Context::Scale(double s) {
    Renderer::Scale(s);
}

void SDL_Context::Scale(const Vec2 &center, double s) {
    Renderer::Scale(center, s);
    SDL_RenderSetScale(this->renderer, this->fScale.GetX(), this->fScale.GetY());

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

void SDL_Context::FillRect(int x, int y, int w, int h) {
    Renderer::FillRect(x, y, w, h);
    SDL_Rect rect = {x + static_cast<int>( this->fTranslate.GetX()), y + static_cast<int>( this->fTranslate.GetY()),
                     w, h};
    SDL_RenderFillRect(this->renderer, &rect);
}

void SDL_Context::DrawPoint(int x, int y) {
    Renderer::DrawPoint(x, y);
    SDL_RenderDrawPoint(this->renderer, this->pos.GetX() + this->fTranslate.GetX(),
                        this->pos.GetY() + this->fTranslate.GetY());
}

void SDL_Context::FillRect(const Vec2 &pos, const Vec2 &size) {
    Renderer::FillRect(pos, size);
    SDL_Rect rect = {static_cast<int>(pos.GetX() + this->fTranslate.GetX()),
                     static_cast<int>(pos.GetY() + this->fTranslate.GetY()),
                     static_cast<int>(size.GetX()), static_cast<int>(size.GetY())};
    SDL_RenderFillRect(this->renderer, &rect);
}

void SDL_Context::DrawRect(const Vec2 &pos, const Vec2 &size) {
    Renderer::DrawRect(pos, size);
    SDL_Rect rect = {static_cast<int>(pos.GetX() + this->fTranslate.GetX()),
                     static_cast<int>(pos.GetY() + this->fTranslate.GetY()),
                     static_cast<int>(size.GetX()), static_cast<int>(size.GetY())};
    SDL_RenderDrawRect(this->renderer, &rect);
}
