#ifndef __KNIGHTATTACK_H__
#define __KNIGHTATTACK_H__

#include "../Character/Character.h"
#include "AttackStrategy.h"
#include <iostream>

class Character;

class KnightAttack : public AttackStrategy {

    public:
        KnightAttack() : AttackStrategy() { };

        int attackMob(Character * currCharacter, Mob * currMob) {
            return ((((((2 * currCharacter->getLevel()) / 5) + 2) * 35 * currCharacter->getAtk()) / currCharacter->getcurrHP()) / 5 / 50) + 2;
        }
};

#endif //__KNIGHTATTACK_H__