#ifndef __YETI_H__
#define __YETI_H__
#include <stdlib.h>
#include <time.h>
#include "mob.h"
#include <stdlib.h>

class Yeti : public Mob {
public:
    Yeti() {
    }

    Yeti(int characterlevel) {
        srand(time(NULL));
        hp = 4 * characterlevel + rand() % (5 * characterlevel / 4);
        attack = 2 * characterlevel + rand() % (5 * characterlevel / 4);
        defense = 2 * characterlevel + rand() % (5 * characterlevel / 4);
        level = abs(characterlevel - 4 + rand() % 6) + 1;
        giveExp = level * 10 * attack / defense;
        name = "YETI";
    }

    int attackChar(int charDefense) {
	    return abs((((((2 * level / 5) + 2) * (35 + (level * 9 /10)) * attack) / charDefense) /50 ) + 2);
    }

};

#endif //__MOB_H__
