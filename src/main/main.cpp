#include <iostream>
#include "../gui/GameWindow.h"
#include "../game/Game.h"

int main() {
    GameWindow *window = new GameWindow("Game", 1366, 768);
    Game *game = new Game(window);
    game->Go();
    return 0;
}

