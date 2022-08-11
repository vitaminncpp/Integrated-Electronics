#pragma once

#include "NOT.h"

void core::components::NOT::Update() {
    this->output->SetValue(!this->input->GetValue());
}

void core::components::NOT::Render() {

}