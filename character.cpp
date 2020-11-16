#ifndef __CHARACTER_CPP__
#define __CHARACTER_CPP__

#include "character.h"

Character* Character::getInstance(){
        if (_instance == 0){
                _instance = new Character();
        }
	return _instance;
}
Character::Character(){
	_instance = 0;
	name = " ";
	maxHP = 30;
	currHP = 30;
	role;
	atk = 10;
	defense = 5;
	level = 1;
	currExp = 0;
//	attackMethod = 0; will be a Pointer to attackStrategy class
//	currEquipment = 0; will be Pointer to current equipment vector of size 3
//	invEquipment = 0; will be Pointer to inventory of Equipment of size 100
//	invConsumable = 0; will be Pointer to inventory of Consumables of size 100
}

Character::Character(string name, characterType role){
	_instance = 0;
	this->name = name;
	maxHP = 30;
	currHP = 30;
	this->role = role;
        atk = 10;
        defense = 5;
        level = 1;
        currExp = 0;
//      attackMethod = 0; will be a Pointer to attackStrategy class
//      currEquipment = 0; will be Pointer to current equipment vector of size 3
//      invEquipment = 0; will be Pointer to inventory of Equipment of size 100
//      invConsumable = 0; will be Pointer to inventory of Consumables of size 100
}


#endif //__CHARACTER_CPP__
