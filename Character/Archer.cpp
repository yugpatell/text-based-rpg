#include "Archer.h"
#include "../AttackStrategy/ArcherAttack.h"
#include <iostream>

using namespace std;

Archer::Archer(string name, characterType role) {
    attackMethod = new ArcherAttack();
    this->name = name;
    this->role = role;
    int maxHP = 10;
    int currHP = 10;
    int atk = 5;
    int defense = 5;
    int level = 5;
    int currXP = 5;
}

void Archer::attack() {
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

void Archer::levelUp() {
   maxHP += 2;
   currHP += 2;
   atk += 3;
   defense += 1;
   level += 1;
   currXP = 0;
}