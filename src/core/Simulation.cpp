
#include "Simulation.h"

using namespace lib::math;
using namespace interface::gfx;
using namespace core;
using namespace core::components;
using namespace core::resources;

Simulation::Simulation(Renderer *renderer, Resource *resource)
        : renderer(renderer), resource(resource) {

    TestCircuit();
}

Simulation::~Simulation() noexcept {
    for (auto &component: components) {
        if (component) {
            delete component;
        }
    }
    if (current) {
        delete current;
    }
}

void Simulation::Update() {
    for (auto &component: this->components) {
        component->Update();
    }
    if (this->current) {
        current->Update();
    }
}

void Simulation::Render() {
    DrawGrid();
    for (auto &component: this->components) {
        component->Render();
    }
    if (this->current) {
        this->current->Render();
    }
}

void Simulation::DrawGrid() {
    this->renderer->SetColor(0);
    for (int i = 0; i < 100; i++) {
        for (int j = 0; j < 100; j++) {
            this->renderer->FillRect(i * 20 - 1, j * 20 - 1, 3, 3);
        }
    }
    if (state.GetX() != 1 && state.GetY() != -1) {
        this->renderer->FillRect(state.GetX() * 20 - 3, state.GetY() * 20 - 3, 7, 7);
    }
}

void Simulation::TestCircuit() {
    AND *andGate = new AND(renderer, Vec2(8, 8));
    andGate->SetImage(this->resource->GetAndImage());


    components.push_back(andGate);

}

void Simulation::InitWire(const Vec2 &v) {
    if (this->current) {
        delete this->current;
        this->current = nullptr;
    }
    this->current = new components::Wire(this->renderer, v);
}

void Simulation::RelocateWire(const Vec2 &v) {
    if (this->current) {
        (static_cast<Wire *> (this->current))->SetEnd(v);
    }
}
