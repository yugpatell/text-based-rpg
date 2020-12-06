#ifndef __ARCHERATTACK_H__
#define __ARCHERATTACK_H__

#include "../Character/Character.h"

#include "AttackStrategy.h"
#include <iostream>
#include <stdlib.h>

class Character;

class ArcherAttack : public AttackStrategy {

    public:
        ArcherAttack() : AttackStrategy() { };

        int attackMob(Character * currCharacter, Mob * currMob) {
            return abs((((((2 * currCharacter->getLevel() / 5 ) + 2) * (35 + (currCharacter->getLevel())) * currCharacter->getAtk()) / currMob->get_mob_def()) / 50) + 1);
        }
};

#endif //__ARCHERATTACK_H__
