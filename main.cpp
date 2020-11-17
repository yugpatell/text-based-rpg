#include "Character/Knight.cpp"
#include "Character/Mage.cpp"
#include "Character/Archer.cpp"

#include <iostream>


using namespace std;


int main() {
    Character* testOne = new Knight("Thomas", KNIGHT);
    testOne->levelUp();
    testOne->attack();

    Character* testTwo = new Mage("Yug", MAGE);
    testTwo->levelUp();
    testTwo->attack();

    Character* testThree = new Archer("Scott", ARCHER);
    testThree->levelUp();
    testThree->attack();

    return 0;
}
