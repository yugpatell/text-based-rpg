#ifndef __CREATE_EQUIPABLE__
#define __CREATE_EQUIPABLE__

#include "equipable.cpp"
#include "Armor.h"
#include "Weapon.h"
#include <stdlib.h>
#include <time>

class CreateEquipableFactory{
  public:
    virtual Armor* CreateChestArmor(Character c) = 0;
    virtual Armor* CreateLegArmor(Character c) = 0;
    virtual Weapon* CreateWeapon(Character c) = 0;

};

#endif // __CREATE_EQUIPABLE__


//Chestplate* armor1 = CreateKnightItemFactory()->CreateChestArmor();
//
//CreateEquipableFactory
