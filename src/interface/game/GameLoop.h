#pragma once

#include <memory>
#include "../window/Window.h"
#include "../io/InputBridge.h"
#include "../gfx/Renderer.h"


namespace interface::game {
    class GameLoop : public interface::io::InputBridge {
    protected:
        bool isRunning = false;
        interface::window::Window *window = nullptr;
        interface::gfx::Renderer *renderer = nullptr;
    public:
        inline explicit GameLoop(interface::window::Window *window) {
            this->window = window;
        }

        inline interface::window::Window *GetWindow() const {
            return this->window;
        }

        virtual void SetRenderer(interface::gfx::Renderer *renderer);

        inline gfx::Renderer *GetRenderer() const {
            return this->renderer;
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

        void SendEvent(const interface::io::Event &event) override;

    };
}
