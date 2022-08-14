
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
    switch (event.GetType()) {
        case EVENT_TYPE_MOUSE:
            switch (event.GetFlag()) {
                case FLAG_MOUSE_L_DOWN:
                    break;
                case FLAG_MOUSE_L_UP:
                    break;
                case FLAG_MOUSE_R_DOWN:
                    break;
                case FLAG_MOUSE_R_UP:
                    break;
                case FLAG_MOUSE_MOVED:
                    switch (state.GetState()) {
                        case ENABLE_TRANSLATION:
                            renderer->Translate(Vec2(event.GetData().mouse.x, event.GetData().mouse.y));
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
            if (event.GetData().mouse.wheelDelta == 1) {
                s = 1.05;
            } else if (event.GetData().mouse.wheelDelta == -1) {
                s = 1 / 1.05;
            }
            this->renderer->Scale(Vec2(event.GetData().mouse.x, event.GetData().mouse.y), s);
            break;

        case EVENT_TYPE_KEYBOARD:
            switch (event.GetFlag()) {
                case FLAG_KEY_DOWN:
                    switch (event.GetData().keyCode) {
                        case KEYCODE_LCTRL:
                            this->state.SetState(ENABLE_TRANSLATION);
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

