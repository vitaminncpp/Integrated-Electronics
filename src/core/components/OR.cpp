
#include "OR.h"

using namespace core::components;

void OR::Update() {
    Component::Update();
    this->output->SetValue(this->input1->GetValue() || this->input2->GetValue());
}

void OR::Render() {
    Component::Render();
}