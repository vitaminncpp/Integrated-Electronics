
#include "Simulation.h"

using namespace core;

using namespace core;
using namespace interface::gfx;
using namespace core::components;

Simulation::Simulation(Renderer *renderer)
        : renderer(renderer) {}

Simulation::~Simulation() {

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
    this->renderer->SetColor(255);
    for (int i = 0; i < 10000; i += 20) {
        for (int j = 0; j < 10000; j += 20) {
            this->renderer->DrawRect(i, j, 1, 1);
        }
    }
}
