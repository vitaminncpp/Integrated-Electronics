#pragma once

#define INVALID_STATE -1
#define NORMAL_STATE 0
#define LCTRL_DOWN 10
#define MOUSE_L_DOWN 11

namespace game {
    class State {
        struct KeyState {
            int keyCode = -1;
            unsigned int keyFlags = 0;
        };
        struct MouseState {
            int mouseButton = -1;
            int mouseX = -1;
            int mouseY = -1;
            int mouseXrel = 0;
            int mouseYrel = 0;
            int wheelX = 0;
            int wheelY = 0;
            unsigned int mouseFlags = 0;
        };
    private:
        int state = -1;
        unsigned int stateFlags = -1;
        int statePrev = -1;
        unsigned int statePrevFlags = -1;
        int stateNext = -1;
        unsigned int stateNextFlags = 0;


        KeyState keyState;
        MouseState mouseState;
        KeyState keyStatePrev;
        MouseState mouseStatePrev;
        KeyState keyStateNext;
        MouseState mouseStateNext;


    public:
        inline State() {
            Reset();
        };

        inline  ~State() = default;

    public:
        inline int GetState() const {
            return this->state;
        }

        inline void SetState(int state) {
            this->state = state;
        }

        inline KeyState &GetKeyState() {
            return this->keyState;
        }

        inline MouseState &GetMouseState() {
            return this->mouseState;
        }

        inline KeyState &GetKeyStatePrev() {
            return this->keyStatePrev;
        }

        inline MouseState &GetMouseStatePrev() {
            return this->mouseStatePrev;
        }

        inline KeyState &GetKeyStateNext() {
            return this->keyStateNext;
        }

        inline MouseState &GetMouseStateNext() {
            return this->mouseStateNext;
        }

        inline void SetKeyState(const KeyState &keyState) {
            this->keyState = keyState;
        }

        inline void SetMouseState(const MouseState &mouseState) {
            this->mouseState = mouseState;
        }

        inline void SetKeyStatePrev(const KeyState &keyState) {
            this->keyStatePrev = keyState;
        }

        inline void SetMouseStatePrev(const MouseState &mouseState) {
            this->mouseStatePrev = mouseState;
        }

        inline void SetKeyStateNext(const KeyState &keyState) {
            this->keyStateNext = keyState;
        }

        inline void SetMouseStateNext(const MouseState &mouseState) {
            this->mouseStateNext = mouseState;
        }

        void Reset();

    };
}