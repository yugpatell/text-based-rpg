#ifndef __WEAPON_H__
#define __WEAPON_H__

#include "Equipable.h"

class Weapon : public Equipable {
	private:

	public:
		Weapon() : Equipable() {};
		Weapon(int lvl, int rarity, int role) : Equipable(lvl, rarity, role) {};
		virtual bool isArmor() {
		    return false;
		}
};

#endif //__WEAPON_H__
