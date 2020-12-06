#include "GameRunner/GameRunner.cpp"


GameRunner * GameRunner::gameInstance = nullptr;

int main() {
   // FileReader* reader = new FileReader("FileReader/Rarity.txt");
    GameRunner * newGame = newGame->getInstance();
    newGame->startGame();
    return 0;
}
