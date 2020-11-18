#ifndef __MAGEATTACK_H__
#define __MAGEATTACK_H__

#include "../Character/Character.h"
#include "AttackStrategy.h"
#include <iostream>

class Character;

class MageAttack : public AttackStrategy {

    public:
        MageAttack() : AttackStrategy() { };

        int attack(Character * currCharacter) {
            cout << "Mage attack to be implemented" << endl;
            return -1;
        }
};

#endif //__MAGEATTACK_H__