#include <memory>
#include <iostream>
#include "../simulation/window/GameWindow.h"
#include "../game/Game.h"
#include "../simulation/gfx/SDL_Context.h"

using namespace interface::window;
using namespace interface::gfx;
using namespace simulation::window;
using namespace simulation::gfx;
using namespace game;

int main() {
    std::shared_ptr<GameWindow> window = std::make_shared<GameWindow>("Game", 1366, 768);
    std::shared_ptr<Renderer> renderer = std::make_shared<SDL_Context>(window->GetRenderer());
    std::shared_ptr<Game> game = std::make_shared<Game>(window);
    window->SetInputBridge(game);
    game->SetRenderer(renderer);
    game->Go();


    return 0;
}

