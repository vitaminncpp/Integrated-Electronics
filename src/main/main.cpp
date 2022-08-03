#include <iostream>
#include "../gui/window/GameWindow.h"
#include "../game/Game.h"

int main() {
    GameWindow *window = new GameWindow("Game", 1366, 768);
    Game *game = new Game(window);
    window->SetInputBridge(game);
    game->Go();
    return 0;
}

