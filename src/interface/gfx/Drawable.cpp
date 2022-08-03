#pragma once

#include "Drawable.h"


Drawable::~Drawable() {}

void Drawable::Render() {}

void Drawable::Scale(const Vec2 &s) {}

void Drawable::Scale(double s) {}

void Drawable::Translate(const Vec2 &d) {}

void Drawable::Rotate(double t) {}