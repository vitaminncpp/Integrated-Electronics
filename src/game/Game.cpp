
#include "Game.h"
#include "../util/util.h"

using namespace game;
using namespace interface::io;


Game::~Game() {}

void Game::Go() {
    GameLoop::Go();
}

void Game::Init() {
    GameLoop::Init();
}

void Game::SetRenderer(interface::gfx::Renderer *renderer) {
    GameLoop::SetRenderer(renderer);
    simulation.SetRenderer(renderer);
}

void Game::Render() {
    GameLoop::Render();
    renderer->BeginFrame();
    simulation.Render();
    renderer->Present();
}

void Game::Update() {
    GameLoop::Update();
    simulation.Update();
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
                case FLAG_MOUSE_MOVED:
                    renderer->Translate(
                            lib::math::Vec2(((Event) event).GetData().mouse.y, ((Event) event).GetData().mouse.y));
                    break;
                default:
                    break;
            }
            break;
        default:
            break;
    }
}