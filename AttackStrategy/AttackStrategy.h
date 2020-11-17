#ifndef __ATTACKSTRATEGY_H__
#define __ATTACKSTRATEGY_H__

#include "../Character/Character.h"

class Character;

class AttackStrategy {

    public:
        AttackStrategy(){};

        virtual int attack(Character *) = 0;
};

#endif //__ATTACKSTRATEGY_H__