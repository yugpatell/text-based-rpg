#ifndef __MOB_H__
#define __MOB_H__

#include <cstdlib>

class Mob {
public:
    Mob(int characterLevel) {
        hp = characterLevel + 10;
 	attack = characterLevel + 5;
	defense = characterLevel + 5;
	level = characterLevel;
	giveExp = level*10*attack/defense;
    }

protected:
    int hp;
    int attack;
    int defense;
    int level;
    int giveExp;
    virtual attack() = 0;

public:
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
