#pragma once

#include "Window.h"

Window::Window(const char *title, int x, int y, int width, int height) {
    window = SDL_CreateWindow(
            title,
            x, y,
            width, height,
            SDL_WINDOW_SHOWN
    );
    if (window == NULL) {
        fprintf(stderr, "could not create Window: %s\n", SDL_GetError());
        exit(1);
    }
}

Window::~Window() {
    if (window != NULL) {
        SDL_DestroyWindow(window);
    }
}

void Window::Show() {
    SDL_ShowWindow(window);
}

void Window::Close() {
    SDL_HideWindow(window);
}