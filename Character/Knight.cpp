#include "Knight.h"
#include "../AttackStrategy/KnightAttack.h"
#include <iostream>

using namespace std;

Knight::Knight(string name, characterType role) {
    attackMethod = new KnightAttack();
    chestplate = nullptr;
    leggings = nullptr;
    weapon = nullptr;
    this->name = name;
    this->role = role;
    maxHP = 10;
    currHP = 10;
    atk = 5;
    defense = 5;
    level = 1;
    currXP = 0;
    maxXP = 100;
}

int Knight::attack(Mob * currMob) {
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

void Knight::levelUp() {
    while (currXP >= maxXP) {
        cout << "You have lvled up!" << endl;
        maxHP += 3;
        currHP += 3;
        atk += 2;
        defense += 5;
        level += 1;
        currXP = currXP - maxXP;
	maxXP += 25;
    }
}

