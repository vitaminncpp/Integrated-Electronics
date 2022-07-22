#include <iostream>
#include "gui/Window.h"

int main() {
    Window window("Hello World", 100, 100, 640, 480);
    window.Show();
    SDL_Delay(2000);
    return 0;
}

