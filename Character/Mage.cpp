#include "Mage.h"
#include "../AttackStrategy/MageAttack.h"
#include <iostream>

using namespace std;

Mage::Mage(string name, characterType role) {
    attackMethod = new MageAttack();
    this->name = name;
    this->role = role;
    maxHP = 10;
    currHP = 10;
    atk = 5;
    defense = 5;
    level = 1;
    currXP = 0;
}

int Mage::attack(Mob * currMob) {
    try {
        if (this->attackMethod == nullptr) {
            throw std::invalid_argument("Nullptr detected");
        }
        else {
            return this->attackMethod->attackMob(this, currMob);
        }
    }
    catch (std::invalid_argument error) {
        cerr << error.what() << endl;
        return -1;
    }
}

void Mage::levelUp() {
    maxHP += 5;
    currHP +=5;
    atk += 3;
    defense += 2;
    level += 1;
    currXP = 0;
}