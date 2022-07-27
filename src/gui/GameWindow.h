#pragma once

#include <SDL.h>
#include "../interface/game/GameLoop.h"


class GameWindow : public Window {
private:
    SDL_Window *window;
    SDL_Renderer *renderer;


public:
    GameWindow(const std::string &title, int width, int height);

    ~GameWindow();

    void Init();

    void Update();

    void Render();

    void Reset();

    void EndFrame();

    void BeginFrame();

    void Close();

    void Show();
};

