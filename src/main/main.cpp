#include <iostream>
#include "../simulation/window/GameWindow.h"
#include "../game/Game.h"

using namespace simulation::window;
using namespace game;

int main() {
    GameWindow *window = new GameWindow("Game", 1366, 768);
    Game *game = new Game(window);
    window->SetInputBridge(game);
    game->Go();
    return 0;
    std::cout << std::endl;
}

