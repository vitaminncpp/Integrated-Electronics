

#include "Component.h"

using namespace core::components;

Component::~Component() {}

void Component::Update() {}

void Component::Render() {
    Drawable::Render();
    if (this->image != nullptr) {
        this->renderer->DrawImage(this->image, this->pos);
    }
}

