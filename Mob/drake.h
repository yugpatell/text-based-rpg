#ifndef __DRAKE_H__
#define __DRAKE_H__

#include "mob.h"

class Drake : public Mob {
public:
    Drake(int characterlevel) {
    	hp = 3*characterlevel + rand() % (5*characterlevel/4);
	attack = 3*characterlevel + rand() % (5*characterlevel/4);
	defense = 2*characterlevel + rand() % (5*characterlevel/4);
	level = abs(characterlevel - 3 + rand() % 6);
	giveExp = level*10*attack/defense;
    }

protected:
    virtual attack() {
	return (((((2*level/5)+2)*(35+(level*9/10))*attack)/get_character_defense())/50)+2;
    };

};

#endif //__MOB_H__
