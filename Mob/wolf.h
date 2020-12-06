#ifndef __WOLF_H__
#define __WOLF_H__
#include <stdlib.h>
#include <time.h>
#include <stdlib.h>
#include "mob.h"

class Wolf : public Mob {
public:
    Wolf() {
    }

    Wolf(int characterlevel) {
        srand(time(NULL));
    	hp = 2 * characterlevel + rand() % (5 * characterlevel / 4);
	attack = 4 * characterlevel + rand() % (5 * characterlevel / 4);
	defense = 2 * characterlevel + rand() % (5 * characterlevel / 4);
        level = abs(characterlevel - 4 + rand() % 6) + 1;
	giveExp = level*10*attack/defense;
        name = "WOLF";
    }

    int attackChar(int charDefense) {
	    return abs((((((2 * level / 5) + 2 ) * (35 + (level * 9 / 10)) * attack) / charDefense) / 50) + 2);
    }

};

#endif //__MOB_H__
