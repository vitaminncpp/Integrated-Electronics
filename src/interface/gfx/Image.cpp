#pragma once

#include "Image.h"

Image::~Image() {}

void Image::Render() {
    Drawable::Render();
}

void Image::Translate(const Vec2 &d) {
    Drawable::Translate(d);
}

void Image::Scale(double s) {
    Drawable::Scale(s);
}

void Image::Scale(const Vec2 &s) {
    Drawable::Scale(s);
}

void Image::Rotate(double t) {
    Drawable::Rotate(t);
}