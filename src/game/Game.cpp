
#include "Game.h"
#include "../util/util.h"

using namespace lib::math;
using namespace interface::gfx;
using namespace interface::io;
using namespace simulation::gfx;
using namespace simulation::core;
using namespace core;
using namespace game;

Game::Game(interface::window::Window *window, Renderer *renderer)
        : GameLoop(window) {
    Init();
    GameLoop::SetRenderer(renderer);
    resource = new SDL_Resource(GetRenderer());
    simulation = new Simulation(renderer, resource);
    simulation->SetRenderer(GetRenderer());
    simulation->SetResource(resource);
}

Game::~Game() {}

void Game::Go() {
    GameLoop::Go();
}

void Game::Init() {
    GameLoop::Init();
}

void Game::SetRenderer(interface::gfx::Renderer *renderer) {
    GameLoop::SetRenderer(renderer);
    simulation->SetRenderer(renderer);
}

void Game::Render() {
    GameLoop::Render();
    renderer->BeginFrame();
    simulation->Render();
    renderer->Present();
}

void Game::Update() {
    GameLoop::Update();
    simulation->Update();
}

void Game::Reset() {
    GameLoop::Reset();
}

void Game::Enable() {
    GameLoop::Enable();
}

void Game::Disable() {
    GameLoop::Disable();
}

void Game::SendEvent(const interface::io::Event &event) {
    GameLoop::SendEvent(event);
    Vec2 mouse;
    switch (event.GetType()) {
        case EVENT_TYPE_MOUSE:
            mouse.SetXY(event.GetData().mouse.x, event.GetData().mouse.y);
            this->renderer->SetMousePosition(mouse);
            mouse += 10;
            mouse /= 20;
            mouse.Floor();
            this->simulation->SetXY(mouse.GetX(), mouse.GetY());

            switch (event.GetFlag()) {
                case FLAG_MOUSE_L_DOWN:
                    switch (this->state.GetState()) {
                        case NORMAL_STATE:
                            this->simulation->InitWire(mouse);
                            break;
                        default:
                            break;
                    }
                    this->state.SetState(MOUSE_L_DOWN);
                    break;
                case FLAG_MOUSE_L_UP:
                    switch (this->state.GetState()) {
                        case NORMAL_STATE:

                            break;
                        case MOUSE_L_DOWN:
                            this->simulation->AddCurrent();
                            break;
                        default:
                            break;
                    }
                    this->state.SetState(NORMAL_STATE);
                    break;
                case FLAG_MOUSE_R_DOWN:
                    break;
                case FLAG_MOUSE_R_UP:
                    break;
                case FLAG_MOUSE_MOVED:
                    switch (state.GetState()) {
                        case LCTRL_DOWN:
                            renderer->Translate(Vec2(event.GetData().mouse.xrel, event.GetData().mouse.yrel));
                            break;
                        case MOUSE_L_DOWN:
                            this->simulation->RelocateWire(mouse);
                            break;
                        default:
                            break;
                    }
                    break;
                default:
                    break;
            }
            break;
        case EVENT_TYPE_WHEEL:
            double s;
            if (event.GetData().mouse.wheelY == 1) {
                s = 1.05;
            } else if (event.GetData().mouse.wheelY == -1) {
                s = 1 / 1.05;
            }
            this->renderer->Scale(Vec2(event.GetData().mouse.x, event.GetData().mouse.y), s);
            break;

        case EVENT_TYPE_KEYBOARD:
            switch (event.GetFlag()) {
                case FLAG_KEY_DOWN:
                    switch (event.GetData().keyCode) {
                        case KEYCODE_LCTRL:
                            this->state.SetState(LCTRL_DOWN);
                            break;
                        default:
                            break;
                    }
                    break;
                case FLAG_KEY_UP:
                    switch (event.GetData().keyCode) {
                        case KEYCODE_LCTRL:
                            this->state.SetState(NORMAL_STATE);
                            break;
                        default:
                            break;
                    }
                default:
                    break;
            }
            break;
        default:
            break;
    }
}

