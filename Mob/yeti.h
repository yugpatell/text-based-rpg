#ifndef __YETI_H__
#define __YETI_H__

#include "mob.h"

class Yeti : public Mob {
public:
    Yeti(int characterlevel) {
    	hp = 4*characterlevel + rand() % (5*characterlevel/4);
	attack = 2*characterlevel + rand() % (5*characterlevel/4);
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
