
#include "../../util/util.h"
#include "GameWindow.h"

using namespace simulation::window;
using namespace interface::io;

GameWindow::~GameWindow() {
    if (renderer) {
        SDL_DestroyRenderer(renderer);
    }
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

    if (renderer) {
        LOG("Renderer is Created Successfully");
    }
    SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND);
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
    Event toBeSent;
    while (SDL_PollEvent(&event)) {
        toBeSent.Reset();
        switch (event.type) {
            case SDL_QUIT:
                LOG("Event:Quit");
                toBeSent.Reset();
                toBeSent.SetFlag(EVENT_TYPE_QUIT);
                /**Scope to add return type for getting feedback from Game Object*/
                this->input->SendEvent(toBeSent);
                exit(0);
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

                input->SendEvent(toBeSent);
                LOG("Event:MouseMotion");
                break;
            default:
                LOG("Event:Invalid");
                break;
        }
        this->input->SendEvent(toBeSent);
    }
}