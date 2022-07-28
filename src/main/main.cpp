#include <iostream>
#include "../gui/GameWindow.h"

int main() {
    GameWindow *window = new GameWindow("Game", 1366, 768);
    delete window;
    return 0;
}

