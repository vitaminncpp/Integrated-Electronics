#pragma once

#include <memory>
#include <string>
#include "../io/InputBridge.h"
#include "../gfx/Renderer.h"

namespace interface::window {

    class Window {
    protected:
        int height;
        int width;
        std::string title;
        std::shared_ptr<interface::io::InputBridge> input;
        std::shared_ptr<interface::gfx::Renderer> renderer;
    public:
        inline Window(const std::string &title, int width, int height)
                : title(title), width(width), height(height) {}

        virtual ~Window();

        inline int GetWidth() const {
            return width;
        }

    public:
        inline void SetWidth(int width) {
            this->width = width;
        }

        inline int GetHeight() const {
            return this->height;
        }

        inline void SetHeight(int height) {
            this->height = height;
        }

        inline const std::string &GetTitle() const {
            return this->title;
        }

        inline void SetTitle(const std::string &title) {
            this->title = title;
        }

        inline void SetInputBridge(const std::shared_ptr<interface::io::InputBridge> &input) {
            this->input = input;
        }

        virtual void Init();

        virtual void Update();

        virtual void Render();

        virtual void Reset();

        virtual void EndFrame();

        virtual void BeginFrame();

        virtual void Close();

        virtual void Show();

        virtual void HandleInput();
    };
}


