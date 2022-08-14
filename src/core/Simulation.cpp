
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
    for (int i = 0; i < 1000; i += 20) {
        for (int j = 0; j < 1000; j += 20) {
            this->renderer->DrawRect(i - 1, j - 1, 3, 3);
        }
    }
    if (this->current) {
        this->current->Render();
    }
}

void Simulation::TestCircuit() {
    Wire *input1 = new Wire(renderer);
    Wire *input2 = new Wire(renderer);
    Wire *output = new Wire(renderer);
    AND *andGate = new AND(renderer, Vec2(100, 100), Vec2(50, 50));
    andGate->SetImage(this->resource->GetAndImage());
    andGate->SetInput1(input1);
    andGate->SetInput2(input2);
    andGate->SetOutput(output);

    input1->SetStart(Vec2(100, 100));
    input1->SetEnd(Vec2(100, 200));

    input2->SetStart(Vec2(150, 100));
    input2->SetEnd(Vec2(150, 200));

    output->SetStart(Vec2(200, 125));
    output->SetEnd(Vec2(400, 125));

    input1->SetValue(true);
    input2->SetValue(true);

    components.push_back(andGate);
    components.push_back(input1);
    components.push_back(input2);
    components.push_back(output);

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
