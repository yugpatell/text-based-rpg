#include "GameRunner/GameRunner.cpp"
#include <iostream>

GameRunner * GameRunner::gameInstance = nullptr;


int main() {
    GameRunner * newGame = newGame->getInstance();
    newGame->startGame();
    return 0;
}
