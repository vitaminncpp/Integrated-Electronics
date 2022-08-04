
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

void Game::Render() {
    GameLoop::Render();
    renderer->BeginFrame();
    renderer->SetColor(255);
    renderer->DrawLine(p1, p2);
    renderer->Present();
}

void Game::Update() {
    GameLoop::Update();
    p1 += 1;
    p2 -= 1;
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