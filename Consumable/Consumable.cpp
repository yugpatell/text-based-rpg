#include "Consumable.h"

Consumable::Consumable(){
	level = 1; //level required to equip item
	value = 5; //number to increase (STAT) by
}

Consumable::Consumable(int lvl, int rarity, string name){
	level = lvl;
	value = lvl + (rarity*3);
	this->name = name;
}

int Consumable::getLevel(){
	return level;
}

int Consumable::getValue(){
	return value;
}
string Consumable::getName() {
    return name;
}