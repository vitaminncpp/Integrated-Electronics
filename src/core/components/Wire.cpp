#include "Wire.h"

using namespace core::components;
using namespace interface::gfx;

Wire::~Wire() {

}

void Wire::Render() {
    renderer->SetColor(255);
    renderer->DrawLine(path[0], path[length]);
}

void Wire::Update() {

}