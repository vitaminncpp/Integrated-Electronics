
#include "AND.h"

using namespace core::components;

void AND::Update() {
    Component::Update();
    if (this->input1 && this->input2 && this->output) {
        this->output->SetValue(this->input1->GetValue() && this->input2->GetValue());
    } else if (this->output) {
        this->output->SetValue(false);
    }
}

void AND::Render() {
    Component::Render();
}

void AND::SetOutput(Wire *output) {
    this->output = output;
}
