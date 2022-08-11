
#include "AND.h"

using namespace core::components;

void AND::Update() {
    Component::Update();
    this->output->SetValue(this->input1->GetValue() && this->input2->GetValue());
}

void AND::Render() {
    Component::Render();

}