#ifndef __CREATE_KNIGHT_ITEM__
#define __CREATE_KNIGHT_ITEM__

#include "CreateEquipableFactory.h"

class CreateKnightItemFactory : public CreateEquipableFactory{
  public:
    virtual Armor CreateChestArmor(const Character c){

    }

    virtual Armor CreateLegArmor(const Character c){

    }

    virtual Weapon CreateWeapon(const Character c){

    }

};

#endif // __CREATE_KNIGHT_ITEM__
