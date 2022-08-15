

#include "Component.h"

using namespace core::components;

Component::~Component() {
    if (this->image) {
        delete image;
    }
}

void Component::Update() {}

void Component::Render() {
    Drawable::Render();
    if (this->image) {
        this->renderer->DrawImage(this->image, this->pos * 20);
    }
}

