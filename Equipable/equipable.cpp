#ifndef __EQUIPABLE_CPP__
#define __EQUIPABLE_CPP__

#include <equipable.h>

Equipable::Equipable(){
	level = 1; //level required to equip item
	value = 5; //number to increase (STAT) by
}

Equipable::Equipable(int lvl, int rarity){
	level = lvl;
	value = lvl + (rarity*3);
}

int Equipable::getLevel(){
	return level;
}

int Equipable::getValue(){
	return value;
}
 
#endif //__EQUIPABLE_CPP__
