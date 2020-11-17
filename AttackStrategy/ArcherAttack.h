#ifndef __ARCHERATTACK_H__
#define __ARCHERATTACK_H__

#include "../Character/Character.h"
#include "AttackStrategy.h"
#include <iostream>

class Character;

class ArcherAttack : public AttackStrategy {

    public:
        ArcherAttack() : AttackStrategy() { };

        int attack(Character * currCharacter) {
            cout << "Archer attack to be implemented" << endl;
            return -1;
        }
};

#endif //__ARCHERATTACK_H__