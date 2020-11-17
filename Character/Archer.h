#ifndef __ARCHER_H__
#define __ARCHER_H__

#include "Character.h"

class Archer : public Character {

public:
    Archer(string, characterType);
    void attack();
    void levelUp();
};











#endif //__MAGE_H__