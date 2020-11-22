#ifndef __KNIGHT_H__
#define __KNIGHT_H__

#include "Character.h"


class Knight : public Character {

    public:
       Knight(string, characterType);
       int attack(Mob * currMob);
       void levelUp();

};


#endif //__KNIGHT_H__
