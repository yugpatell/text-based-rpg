#ifndef __MOB_H__
#define __MOB_H__
#include <stdlib.h>
#include <time.h>
#include <cstdlib>

class Mob {
public:
    Mob() {
    }
    Mob(int characterLevel) {
        hp = characterLevel + 10;
 	    attack = characterLevel + 5;
	    defense = characterLevel + 5;
	    level = characterLevel;
	    giveExp = level * 10 * attack / defense;
    }

protected:
    int hp;
    int attack;
    int defense;
    int level;
    int giveExp;

public:
    virtual int attackChar(int charDefense) = 0;
    get_mob_hp() {
	    return hp;
    }
    get_mob_atk() {
	    return attack;
    }
    get_mob_def() {
	    return defense;
    }
    get_mob_lvl() {
	    return level;
    }
    get_mob_exp() {
	    return giveExp;
    }

};

#endif //__MOB_H__
