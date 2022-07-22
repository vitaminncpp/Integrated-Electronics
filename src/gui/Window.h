#pragma once

#include <SDL2/SDL.h>

class Window {
private:
    SDL_Window *window;
public:
    Window(const char *title, int x, int y, int width, int height);

    void Show();

    void Close();

    ~Window();
};