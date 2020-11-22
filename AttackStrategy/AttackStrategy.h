#ifndef __ATTACKSTRATEGY_H__
#define __ATTACKSTRATEGY_H__

#include "../Character/Character.h"
#include "../Mob/mob.h"

class Character;

class AttackStrategy {

    public:
        AttackStrategy(){};

        virtual int attackMob(Character * currCharacter, Mob * currMob) = 0;
};

#endif //__ATTACKSTRATEGY_H__