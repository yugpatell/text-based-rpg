#include "GameRunner/GameRunner.cpp"


GameRunner * GameRunner::gameInstance = nullptr;

int main() {
    GameRunner * newGame = newGame->getInstance();
    newGame->startGame();
    return 0;
}
