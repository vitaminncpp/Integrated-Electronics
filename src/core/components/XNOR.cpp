
#include "XNOR.h"

using namespace core::components;

void XNOR::Update() {
    Component::Update();
    bool xnor = (this->input1->GetValue() && this->input2->GetValue()) ||
                (!(this->input1->GetValue() || this->input2->GetValue()));
    this->output->SetValue(xnor);
}