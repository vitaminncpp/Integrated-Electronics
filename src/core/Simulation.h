#pragma once

#include <vector>
#include "components/Component.h"

namespace core {

    class Simulation {
    private:
        std::vector<core::components::Component> components;
        int count;

    public:
        Simulation();

        inline int GetComponentCount() { return count; }

        ~Simulation();
    };
}
