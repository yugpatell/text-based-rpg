#ifndef __KNIGHTATTACK_H__
#define __KNIGHTATTACK_H__

#include "../Character/Character.h"
#include "AttackStrategy.h"
#include <iostream>

class Character;

class KnightAttack : public AttackStrategy {

    public:
        KnightAttack() : AttackStrategy() { };

        int attack(Character * currCharacter) {
            cout << "Knight attack to be implemented" << endl;
            return -1;
        }
};

#endif //__KNIGHTATTACK_H__