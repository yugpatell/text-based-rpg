#include "Equipable.h"

Equipable::Equipable(){
	level = 1; //level required to equip item
	value = 5; //number to increase (STAT) by
	role = 0; //defaulted to knight role
}

Equipable::Equipable(int lvl, int rarity, int role){
	level = lvl;
	value = lvl + (rarity*3);
	this->role = role;
}

int Equipable::getLevel(){
	return level;
}

int Equipable::getValue(){
	return value;
}
 
int Equipable::getRole(){
	return role;
}
