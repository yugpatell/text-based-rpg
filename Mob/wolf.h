#ifndef __WOLF_H__
#define __WOLF_H__
#include <stdlib.h>
#include <time.h>
#include "mob.h"

class Wolf : public Mob {
public:
    Wolf() {
    }

    Wolf(int characterlevel) {
        srand(time(NULL));
    	hp = 1 * characterlevel + rand() % (5 * characterlevel / 4);
	    attack = 2 * characterlevel + rand() % (5 * characterlevel / 4);
	    defense = 1 * characterlevel + rand() % (5 * characterlevel / 4);
	    level = abs(characterlevel - 3 + rand() % 6);
	    giveExp = level*10*attack/defense;
        name = "WOLF";
    }

    int attackChar(int charDefense) {
	    return (((((2 * level / 5) + 2 ) * (35 + (level * 9 / 10)) * attack) / charDefense) / 50) + 2;
    }

};

#endif //__MOB_H__
