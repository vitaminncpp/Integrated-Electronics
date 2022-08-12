
#include "Simulation.h"

using namespace core;

using namespace core;
using namespace interface::gfx;
using namespace core::components;

Simulation::Simulation(Renderer *renderer)
        : renderer(renderer) {}

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
    if (current) {
        current->Update();
    }
}

void Simulation::Render() {
    DrawGrid();
    for (auto &component: this->components) {
        component->Render();
    }
    if (current) {
        current->Render();
    }
}

void Simulation::DrawGrid() {
    this->renderer->SetColor(0);
    for (int i = 0; i < 1000; i += 20) {
        for (int j = 0; j < 1000; j += 20) {
            this->renderer->DrawRect(i - 1, j - 1, 3, 3);
        }
    }
}

void Simulation::TestCircuit() {
    Component *wire1 = new Wire(renderer);
}
