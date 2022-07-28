
#include "../util/util.h"
#include "GameWindow.h"


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


    if (SDL_Init(SDL_INIT_EVERYTHING)) {
        LOG("Subsystem Initialized");
        window = SDL_CreateWindow(
                this->GetTitle().c_str(),
                100, 100,
                this->GetWidth(), this->GetHeight(),
                SDL_WINDOW_SHOWN
        );
        if (window) {
            LOG("Window Created");
        }


        renderer = SDL_CreateRenderer(window, 0, 0);
        LOG("Just to make sure that Renderer initialize with Direct3D11 backend");

        if (renderer) {
            LOG("Renderer is Created Successfully");
        }

    } else {
        LOG("Subsystem Failed");
    }
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

void GameWindow::HandleInput() {
    Window::HandleInput();
}