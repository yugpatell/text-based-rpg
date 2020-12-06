#ifndef __CREATE_EQUIPABLE__
#define __CREATE_EQUIPABLE__

#include "Equipable.h"
#include "../Character/Archer.h"
#include "../Character/Knight.h"
#include "../Character/Mage.h"
#include "../FileReader/FileReader.h"
#include "Armor.h"
#include "Weapon.h"
#include <stdlib.h>
#include <time.h>

class CreateEquipableFactory{
  public:
    virtual Armor* CreateChestArmor(Character * c) = 0;
    virtual Armor* CreateLegArmor(Character * c) = 0;
    virtual Weapon* CreateWeapon(Character * c) = 0;

};

#endif // __CREATE_EQUIPABLE__

