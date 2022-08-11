#include "Wire.h"

using namespace core::components;
using namespace interface::gfx;

Wire::~Wire() {

}

void Wire::Render() {
    renderer->SetColor(0);
    for (int i = 0; i < length; i++) {
        renderer->DrawLine(path[i], path[i + 1]);
    }
}

void Wire::Update() {

}

void Wire::AddPath(const lib::math::Vec2 &v) {
    path.push_back(v);
    length++;
}
