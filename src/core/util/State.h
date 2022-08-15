#pragma once

namespace core::util {
    class State {
        static constexpr int INVALID = -1;
        static constexpr int NORMAL = 0;

        static constexpr int AND_SELECTED = 10;
        static constexpr int WIRE_SELECTED = 12;
        static constexpr int OR_SELECTED = 13;
        static constexpr int XOR_SELECTED = 14;
        static constexpr int XNOR_SELECTED = 15;
        static constexpr int NOR_SELECTED = 16;
        static constexpr int NAND_SELECTED = 17;

    private:
        int state = -1;
        int selected = -1;
        int currX = -1;
        int currY = -1;

    public:
        inline explicit State() {
            Reset();
        }

        inline ~State() {}

        inline int GetState() {
            return this->state;
        }

        inline void SetState(int state) {
            this->state = state;
        }

        inline int GetSelected() {
            return this->selected;
        }

        inline void SetSelected(int selected) {
            this->selected = selected;
        }

        inline void SetXY(int x, int y) {
            this->currX = x;
            this->currY = y;
        }

        inline int GetX() {
            return this->currX;
        }

        inline int GetY() {
            return this->currY;
        }

    public:
        void Reset();

    };
}