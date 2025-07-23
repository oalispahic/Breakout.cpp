#include "game.h"
#include "objects.h"
#include <iostream>

int main() {
    Game g1(20, 20);
    char input;
    g1.setBufferedInput(false);
    Game::clearScreen();
    while (true) {
        if (read(STDIN_FILENO, &input, 1) == 1) {
            g1.commands(input);
            g1.render();

            if (input == 'q') break;
        }
        Game::delay(25);

    }
    Game::clearScreen();
return 0;
}