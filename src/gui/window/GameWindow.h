#pragma once

#include <SDL.h>
#include "../../interface/window/Window.h"


class GameWindow : public Window {
private:
    SDL_Window *window;
    SDL_Renderer *renderer;


public:
    inline explicit GameWindow(const std::string &title, int width, int height)
            : Window(title, width, height) {
        Init();
    }

    ~GameWindow() override;

    void Init() override;

    void Update() override;

    void Render() override;

    void Reset() override;

    void EndFrame() override;

    void BeginFrame() override;

    void Close() override;

    void Show() override;

    void HandleInput() override;
};

