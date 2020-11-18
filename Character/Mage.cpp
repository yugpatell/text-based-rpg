#include "Mage.h"
#include "../AttackStrategy/MageAttack.h"
#include <iostream>

using namespace std;

Mage::Mage(string name, characterType role) {
    attackMethod = new MageAttack();
    this->name = name;
    this->role = role;
    int maxHP = 10;
    int currHP = 10;
    int atk = 5;
    int defense = 5;
    int level = 5;
    int currXP = 5;
}

void Mage::attack() {
    try {
        if (this->attackMethod == nullptr) {
            throw std::invalid_argument("Nullptr detected");
        }
        else {
            this->attackMethod->attack(this);
        }
    }
    catch (std::invalid_argument error) {
        cerr << error.what() << endl;
    }
}

void Mage::levelUp() {
    maxHP += 3;
    currHP += 3;
    atk += 2;
    defense += 1;
    level += 1;
    currXP = 0;
}