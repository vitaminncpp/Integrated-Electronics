#pragma once

#include <memory>
#include "Wire.h"

namespace core::components {
    class AND : public Component {
    private:
        Wire *input1 = nullptr;
        Wire *input2 = nullptr;
        Wire *output = nullptr;
    public:
        inline explicit AND(interface::gfx::Renderer *renderer, const lib::math::Vec2 &pos)
                : Component(renderer, pos, lib::math::Vec2(40, 40)) {

        }

        inline ~AND() override {

        };

        inline void SetInput1(Wire *input1) {
            this->input1 = input1;
        }

        inline void SetInput2(Wire *input2) {
            this->input2 = input2;
        }

        inline Wire *GetInput1(Wire *input1) const {
            return this->input1;
        }

        inline Wire *GetInput2(Wire *input2) const {
            return this->input2;
        }

    public:

        void Update() override;

        void Render() override;

        void SetOutput(Wire *output);
    };
}