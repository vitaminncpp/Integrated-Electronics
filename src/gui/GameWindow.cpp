#include <chrono>
#include <thread>
#include "../util/util.h"
#include "GameWindow.h"

GameWindow::GameWindow(const std::string &title, int width, int height)
        : Window(title, width, height) {

    window = SDL_CreateWindow(
            title.c_str(),
            x, y,
            width, height,
            SDL_WINDOW_SHOWN
    );
    if (window == NULL) {
        LOG("could not create Window");
        exit(1);
    }
    std::this_thread::sleep_for(std::chrono::milliseconds(10000));
}

GameWindow::~GameWindow() {
    if (window != nullptr) {
        SDL_DestroyWindow(window);
    }
}

void GameWindow::Show() {
    SDL_ShowWindow(window);
}

void GameWindow::Close() {
    SDL_HideWindow(window);
}

void GameWindow::Reset() {

}