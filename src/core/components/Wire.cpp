#include "Wire.h"

using namespace core::components;
using namespace interface::gfx;


void Wire::Render() {
    this->renderer->SetColor(this->value ? Color(0, 255, 0) : Color(255, 0, 0));
    this->renderer->DrawLine(this->pos * 20, this->size * 20);

//    renderer->SetColor(0);
//    for (int i = 0; i < length; i++) {
//        renderer->DrawLine(path[i], path[i + 1]);
//    }
}

void Wire::Update() {
//IDK
}

void Wire::AddPath(const lib::math::Vec2 &v) {
    path.push_back(v);
    length++;
}
