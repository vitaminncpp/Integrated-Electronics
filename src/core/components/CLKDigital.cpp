#include "CLKDigital.h"

using namespace core::components;

void CLKDigital::Update() {
    this->output->SetValue(this->value);
}

void CLKDigital::Render() {
    this->renderer->DrawImage(this->image);
}