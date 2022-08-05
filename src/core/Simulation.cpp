
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
    current->Update();
}

void Simulation::Render() {
    for (auto &component: this->components) {
        component->Render();
    }
    current->Update();
}
