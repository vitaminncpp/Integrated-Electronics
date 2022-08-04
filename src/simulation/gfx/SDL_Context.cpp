#include "SDL_Context.h"

SDL_Context::~SDL_Context() {}

void SDL_Context::Render(const Image &image){
    Renderer::Render(image);
}

void SDL_Context::Init() {
    Renderer::Init();
}

void SDL_Context::Reset() {
    Renderer::Reset()
}

void SDL_Context::Present() {
    Renderer::Present();
}

void SDL_Context::DrawLine(const Vec2 &v1, const Vec2 &v2) {
    Renderer::DrawLine(v1,v2);
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
