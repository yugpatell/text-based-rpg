#include "Character/Knight.cpp"
#include "Character/Mage.cpp"
#include "Character/Archer.cpp"
#include "Mob/drake.h"
#include "Mob/goblin.h"
#include "Mob/wolf.h"
#include "Mob/troll.h"
#include "Mob/yeti.h"



#include <iostream>


using namespace std;


int main() {
    Character* testOne = new Mage("Thomas", MAGE);
    testOne->setLevel(15);

    Mob * testMob = new Wolf(testOne->getLevel());
    cout << "Character's attack to Mob: " << testOne->attack(testMob) << endl;
    cout << "Mob's attack to Character: " << testMob->attackChar(testOne->getDefense()) << endl;



    Character* testTwo = new Mage("Yug", MAGE);
    testTwo->levelUp();
    //testTwo->attack();

    Character* testThree = new Archer("Scott", ARCHER);
    testThree->levelUp();
    //testThree->attack();

    return 0;
}
