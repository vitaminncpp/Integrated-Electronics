
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
    int x = 0, y = 0;
    while (SDL_PollEvent(&event)) {
        toBeSent.Reset();
        switch (event.type) {
            case SDL_QUIT:
                LOG("Event:Quit");
                toBeSent.SetFlag(EVENT_TYPE_QUIT);
                /**Scope to add return type for getting feedback from Game Object*/
                this->input->SendEvent(toBeSent);
                exit(0);
                break;
            case SDL_MOUSEBUTTONDOWN:
                LOG("Event:MouseButtonDown");
                toBeSent.SetType(EVENT_TYPE_MOUSE);
                if (event.button.button == SDL_BUTTON_LEFT) {
                    toBeSent.SetFlag(FLAG_MOUSE_L_DOWN);
                } else if (event.button.button == SDL_BUTTON_RIGHT) {
                    toBeSent.SetFlag(FLAG_MOUSE_R_DOWN);
                }
                toBeSent.SetData(
                        {.mouse={.x=static_cast<short>(event.motion.x), .y=static_cast<short>(event.motion.y), .wheelDelta=0}});
                break;
            case SDL_MOUSEBUTTONUP:
                LOG("Event:MouseButtonUp");
                toBeSent.SetType(EVENT_TYPE_MOUSE);
                if (event.button.button == SDL_BUTTON_LEFT) {
                    toBeSent.SetFlag(FLAG_MOUSE_L_UP);
                } else if (event.button.button == SDL_BUTTON_RIGHT) {
                    toBeSent.SetFlag(FLAG_MOUSE_R_UP);
                } else {
                }
                toBeSent.SetData(
                        {.mouse={.x=static_cast<short>(event.motion.x), .y=static_cast<short>(event.motion.y), .wheelDelta=0}});
                break;
            case SDL_KEYDOWN:
                LOG("Event:KeyDown");
                break;
            case SDL_KEYUP:
                LOG("Event:KeyUp");
                break;
            case SDL_MOUSEWHEEL:
                SDL_GetMouseState(&x, &y);
                toBeSent.SetType(EVENT_TYPE_WHEEL);
                toBeSent.SetFlag(FLAG_NONE);
                toBeSent.SetData(
                        {.mouse={.x=static_cast<short>(x), .y=static_cast<short>(y), .wheelDelta=static_cast<short>(event.wheel.y)}});
                LOG("Event:MouseWheel");
                LOG("WheelDelta : " + std::to_string(event.wheel.y));
                break;
            case SDL_MOUSEMOTION:
                LOG("Event:MouseMotion");
                toBeSent.SetType(EVENT_TYPE_MOUSE);
                toBeSent.SetFlag(FLAG_MOUSE_MOVED);
                toBeSent.SetData(
                        {.mouse={.x=static_cast<short>(event.motion.xrel), .y=static_cast<short>(event.motion.yrel), .wheelDelta=0}});
                break;
            default:
                LOG("Event:Invalid");
                break;
        }
        this->input->SendEvent(toBeSent);
    }
}