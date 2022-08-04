
#include "../../util/util.h"
#include "GameWindow.h"

using namespace simulation::window;

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
    SDL_Event event;
    int mouseX;
    int mouseY;

    while (SDL_PollEvent(&event)) {
        switch (event.type) {
            case SDL_QUIT:
                LOG("Event:Quit");
                break;
            case SDL_MOUSEBUTTONDOWN:
                LOG("Event:MouseButtonDown");
                break;
            case SDL_MOUSEBUTTONUP:
                LOG("Event:MouseButtonUp");
                break;
            case SDL_KEYDOWN:
                LOG("Event:KeyDown");
                break;
            case SDL_KEYUP:
                LOG("Event:KeyUp");
                break;
            case SDL_MOUSEWHEEL:
                LOG("Event:MouseWheel");
                break;
            case SDL_MOUSEMOTION:
                LOG("Event:MouseMotion");
                break;
            default:
                LOG("Event:Invalid");
                break;
        }
    }
}