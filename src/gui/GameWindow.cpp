#include <chrono>
#include <thread>
#include "../util/util.h"
#include "GameWindow.h"

GameWindow::GameWindow(const std::string &title, int width, int height)
        : Window(title, width, height) {
    window = SDL_CreateWindow(
            title.c_str(),
            100, 100,
            width, height,
            SDL_WINDOW_SHOWN
    );
    if (window == nullptr) {
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
    Window::Show();
    SDL_ShowWindow(window);
}

void GameWindow::Close() {
    Window::Close();
    SDL_HideWindow(window);
}

void GameWindow::Reset() {
    Window::Reset();
}

void GameWindow::Init() {
    Window::Init();
}

void GameWindow::BeginFrame() {
    Window::BeginFrame();
}

void GameWindow::EndFrame() {
    Window::EndFrame();
}

void GameWindow::Update() {
    Window::Update();
}

void GameWindow::Render() {
    Window::Render();
}