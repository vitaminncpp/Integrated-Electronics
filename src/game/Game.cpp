
#include "Game.h"

void Game::Go() {
    GameLoop::Go();
}

void Game::Init() {
    GameLoop::Init();
}

void Game::Render() {
    GameLoop::Render();
}

void Game::Update() {
    GameLoop::Update();
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

void Game::SendEvent(const Event &event) {
    
}