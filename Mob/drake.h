#ifndef __DRAKE_H__
#define __DRAKE_H__
#include <stdlib.h>
#include <time.h>
#include <stdlib.h>
#include "mob.h"

class Drake : public Mob {
public:
    Drake() {
    }

    Drake(int characterlevel){
        srand(time(NULL));
    	hp = 3 * characterlevel + rand() % (5 * characterlevel / 4);
	attack = 3 * characterlevel + rand() % (5 * characterlevel / 4);
	defense = 2 * characterlevel + rand() % (5*characterlevel / 4);
        level = abs(characterlevel - 4 + rand() % 6) + 1;
	giveExp = level*10*attack/defense;
	name = "DRAKE";
    }

     int attackChar(int charDefense) {
        return abs((((((2 * level / 5) + 2) * (35 + (level * 9 / 10)) * attack) / charDefense) / 50) + 2);
    }


};

#endif //__MOB_H__
