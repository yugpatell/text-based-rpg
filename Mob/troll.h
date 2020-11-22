#ifndef __TROLL_H__
#define __TROLL_H__

#include "mob.h"

class Troll : public Mob {
public:
    Troll(){
    }

    Troll(int characterlevel) {
        srand(time(NULL));
    	hp = 2 * characterlevel + rand() % (5 * characterlevel / 4);
	    attack = 2 * characterlevel + rand() % (5 * characterlevel / 4);
	    defense = 4 * characterlevel + rand() % (5 * characterlevel / 4);
	    level = abs(characterlevel - 3 + rand() % 6);
	    giveExp = level * 10 * attack / defense;
    }

    int attackChar(int charDefense) {
	    return (((((2 * level / 5) + 2) * (35 + (level * 9 / 10)) * attack) / charDefense) / 50) +2;
    }

};

#endif //__MOB_H__
