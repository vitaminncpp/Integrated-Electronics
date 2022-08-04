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
    SDL_RenderDrawLine(this->GetSDL_Renderer(), v1.GetX(), v1.GetY(), v2.GetX(), v2.GetY());
}

void SDL_Context::Scale(double s) {
    Renderer::Scale(s);
}

void SDL_Context::Scale(const Vec2 &s) {
    Renderer::Scale(s);
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