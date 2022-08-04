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
    GameWindow *window = new GameWindow("Game", 1366, 768);
    Renderer *renderer = new SDL_Context(window->GetRenderer());
    Game *game = new Game(window);
    window->SetInputBridge(game);
    game->SetRenderer(renderer);
    game->Go();
    return 0;
    std::cout << std::endl;
}

