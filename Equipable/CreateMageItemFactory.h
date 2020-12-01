#ifndef __CREATE_MAGE_ITEM__
#define __CREATE_MAGE_ITEM__

#include "CreateEquipableFactory.h"

class CreateMageItemFactory : public CreateEquipableFactory{
  public:
    virtual Robe* CreateChestArmor(const Character c){
      FileReader reader("..FileReader/Rarity.txt");
      srand(time());
      int randomVal = rand%reader.rarities.size());
      string rarity = reader.rarities.at(rand%reader.rarities.size());
      int lvl = abs(c.getLevel()-5 + rand % 11);
      string name = "Lvl: " + lvl + " " + rarity + " Robe";
      return new Robe(lvl, randomVal, name);
    }

    virtual SilkPants* CreateLegArmor(const Character c){
      FileReader reader("..FileReader/Rarity.txt");
      srand(time());
      string rarity = reader.rarities.at(rand%reader.rarities.size());
      int lvl = abs(c.getLevel()-5 + rand % 11);
      string name = "Lvl: " + lvl + " " + rarity + " Silk Pants";
      return new SilkPants(lvl, randomVal, name);
    }

    virtual Staff* CreateWeapon(const Character c){
      FileReader reader("..FileReader/Rarity.txt");
      srand(time());
      string rarity = reader.rarities.at(rand%reader.rarities.size());
      int lvl = abs(c.getLevel()-5 + rand % 11);
      string name = "Lvl: " + lvl + " " + rarity + " Staff";
      return new Staff(lvl, randomVal, name);
    }

};

#endif // __CREATE_MAGE_ITEM__
