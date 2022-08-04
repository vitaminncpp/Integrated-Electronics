#pragma once

#include "../window/Window.h"
#include "../io/InputBridge.h"


namespace interface::game {


    class GameLoop : public interface::io::InputBridge {
    private:
        bool isRunning = false;
        interface::window::Window *window;
    public:
        inline explicit GameLoop(interface::window::Window *window) {
            this->window = window;
        }

        inline interface::window::Window *GetWindow() const {
            return this->window;
        }

        inline bool IsRunning() const {
            return this->isRunning;
        }

        virtual ~GameLoop();

    public:
        virtual void Init();

        virtual void Reset();

        virtual void Update();

        virtual void Render();

        virtual void Go();

        virtual void HandleInput();

        virtual void Enable();

        virtual void Disable();

        void SendEvent(const interface::io::Event &event) override = 0;
    };
}
