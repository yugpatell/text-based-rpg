#ifndef __WEAPON_H__
#define __WEAPON_H__

#include "equipable.h"

class Weapon : Equipable {
	private:
		int weaponType; //[0 = Knight, 1 = Mage, 2 = Archer]
	protected:
		Weapon() : Equipable() { weaponType = 0;} 
		Weapon(int lvl, int rarity, int weaponType) : Equipable(lvl, rarity) { this->weaponType = weaponType;}
		int getWeaponType(){ return weaponType;}
};

#endif //__WEAPON_H__
