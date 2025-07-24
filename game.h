#ifndef BREAKOUT___GAME_H
#define BREAKOUT___GAME_H

#include "objects.h"
#include <termios.h>
#include <iostream>
#include <unistd.h>
#include <chrono>
#include <thread>

class Game {
    int mapX, mapY;
    Paddle player;
    bool validPaddlePos();
public:
    Game(int mapX, int mapY) : mapX(mapX), mapY(mapY), player(7,17,5) {
    }

    static void clearScreen();

    void setBufferedInput(bool enable);

    void render();

    static void delay(int time);

    void commands(char input);

    Point ball;

};


void Game::clearScreen() {
    std::cout << "\033[2J\033[H" << std::flush;
}

void Game::setBufferedInput(bool enable) {
    static bool initialized = false;
    static struct termios old;
    struct termios newt;

    if (!initialized) {
        tcgetattr(STDIN_FILENO, &old);
        initialized = true;
    }

    newt = old;
    newt.c_lflag &= ~(ICANON | ECHO);
    if (enable) newt = old;

    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
}

void Game::render() {
    bool paddleRendered = false;
    Game::clearScreen();
    for (int i = 0; i < mapX; i++) {
        int ignoreCounter = 0;
        for (int j = 0; j < mapY; j++) {
            if (i == 0 || i == mapX - 1 || j == 0 || j == mapY - 1) {
                std::cout << "* ";
                continue;
            }


            if (player.pointArray(0).y == i && !paddleRendered && player.pointArray(0).x == j) {
                for (int k = 0; k < player.paddleSize(); k++) {
                    std::cout << "--";
                }

                paddleRendered = true;

            }
            if (ignoreCounter < player.paddleSize() && paddleRendered) {
                ignoreCounter++;
            } else std::cout << "  ";

        }
        paddleRendered = false;
        std::cout << std::endl;
    }
}

void Game::delay(int time) {
    std::this_thread::sleep_for(std::chrono::milliseconds(time));
}

void Game::commands(char input) {
switch(input){
    case 'd':{
        player.updateX(1);
        if(!validPaddlePos()){
            player.updateX(-1);
        }
        break;
    }
    case 'a':{
        player.updateX(-1);
        if(!validPaddlePos()){
            player.updateX(1);
        }
        break;
    }
}
}

bool Game::validPaddlePos() {
    if(player.pointArray(player.paddleSize()-1).x == mapX-1){
        return false;
    }
    if(player.pointArray(0).x == 0){
        return false;
    }
    return true;
}

#endif //BREAKOUT___GAME_H
