#pragma once

#include "Renderer.h"

Renderer::~Renderer() {}

void Renderer::Init() {}

void Renderer::Reset() {}

void Renderer::Present() {}

void Renderer::DrawLine(const Vec2 &v1, const Vec2 &v2) {}

void Renderer::Scale(double s) {}

void Renderer::Scale(const Vec2 &s) {}

void Renderer::Translate(const Vec2 &d) {}

void Renderer::Rotate(double t) {}

void Renderer::Render(const Image &image) {}
