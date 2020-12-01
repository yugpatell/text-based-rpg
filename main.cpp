#include "GameRunner/GameRunner.cpp"
#include <iostream>
#include "FileReader/FileReader.h"
#include "FileReader/Rarity.txt"

//GameRunner * GameRunner::gameInstance = nullptr;

int main() {
    FileReader* reader = new FileReader("Rarity.txt");
    reader->print();
    //GameRunner * newGame = newGame->getInstance();
    //newGame->startGame();
    return 0;
}
