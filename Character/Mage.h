#ifndef __MAGE_H__
#define __MAGE_H__

#include "Character.h"


class Mage : public Character {

public:
    Mage(string, characterType);
    int attack(Mob * currMob);
    void levelUp();

};


#endif //__MAGE_H__
