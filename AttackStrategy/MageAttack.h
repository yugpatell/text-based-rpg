#ifndef __MAGEATTACK_H__
#define __MAGEATTACK_H__

#include "../Character/Character.h"
#include "AttackStrategy.h"
#include <iostream>
#include <stdlib.h>

class Character;

class MageAttack : public AttackStrategy {

    public:
        MageAttack() : AttackStrategy() { };

        int attackMob(Character * currCharacter, Mob * currMob) {
            return abs(((((((2 * currCharacter->getLevel()) / 5) + 2) * ((currCharacter->getcurrHP() / 2) + 2) * currCharacter->getAtk()) / currMob->get_mob_def()) / 50) + 2);
        }
};

#endif //__MAGEATTACK_H__
