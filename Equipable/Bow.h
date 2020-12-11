#ifndef __BOW_H__
#define __BOW_H__

#include "Weapon.h"
#include <string>

class Bow : public Weapon {
	private:
		string name;
	public:
		Bow() : Weapon(){ name = " "; role = 2;}
		Bow(int lvl, int rarity, string n) : Weapon(lvl, rarity, 2){ name = n;}
		virtual string getName() { return name;}
};

#endif //__BOW_H__
