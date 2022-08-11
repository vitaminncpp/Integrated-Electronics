#include "XOR.h"

using namespace core::components;

void XOR::Update() {
    Component::Update();
    bool Xor = (this->input1->GetValue() && !this->input2->GetValue()) ||
               (!this->input1->GetValue() && this->input2->GetValue());

    this->output->SetValue(Xor);

}

void XOR::Render() {
    Component::Render();
}