#pragma once

#include <vector>
#include "components/Component.h"

class Simulation {
private:
    std::vector<Component *> components;
    int count;

public:
    Simulation();

    inline int GetComponentCount() { return count; }

    ~Simulation();
};