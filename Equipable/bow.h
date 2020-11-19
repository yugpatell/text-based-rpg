#ifndef __BOW_H__
#define __BOW_H__

#include "weapon.h"
#include <string>

class Bow : public Weapon {
	private:
		string name;
	public:
		Bow() : Weapon(){ name = " ";}
		Bow(int lvl, int rarity, string n) : Weapon(lvl, rarity, 2){ name = n;}
		string getName() { return name;}
};

#endif //__BOW_H__
