#ifndef __KNIGHTATTACK_H__
#define __KNIGHTATTACK_H__

#include "../Character/Character.h"
#include "AttackStrategy.h"
#include <iostream>
#include <stdlib.h>

class Character;

class KnightAttack : public AttackStrategy {

    public:
        KnightAttack() : AttackStrategy() { };

        int attackMob(Character * currCharacter, Mob * currMob) {
            return abs(((((((2 * currCharacter->getLevel()) / 5) + 2) * 35 * currCharacter->getAtk()) * currCharacter->getMaxHP() / currCharacter->getcurrHP()) / currCharacter->getcurrHP() / 50) + 2);
        }
};

#endif //__KNIGHTATTACK_H__
