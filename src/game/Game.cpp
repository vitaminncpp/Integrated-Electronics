
#include "Game.h"
#include "../util/util.h"

using namespace game;

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
}