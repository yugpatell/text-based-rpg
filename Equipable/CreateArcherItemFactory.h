#ifndef __CREATE_ARCHER_ITEM__
#define __CREATE_ARCHER_ITEM__

#include "CreateEquipableFactory.h"

class CreateArcherItemFactory : public CreateEquipableFactory{
  public:
    virtual Chainmail* CreateChestArmor(const Character c){
      FileReader reader("..FileReader/Rarity.txt");
      srand(time());
      int randomVal = rand%reader.rarities.size());
      string rarity = reader.rarities.at(rand%reader.rarities.size());
      int lvl = abs(c.getLevel()-5 + rand % 11);
      string name = "Lvl: " + lvl + " " + rarity + " Chainmail";
      return new Chainmail(lvl, randomVal, name);
    }

    virtual LeatherPants* CreateLegArmor(const Character c){
      FileReader reader("..FileReader/Rarity.txt");
      srand(time());
      string rarity = reader.rarities.at(rand%reader.rarities.size());
      int lvl = abs(c.getLevel()-5 + rand % 11);
      string name = "Lvl: " + lvl + " " + rarity + " Leather Pants";
      return new LeatherPants(lvl, randomVal, name);
    }

    virtual Bow* CreateWeapon(const Character c){
      FileReader reader("..FileReader/Rarity.txt");
      srand(time());
      string rarity = reader.rarities.at(rand%reader.rarities.size());
      int lvl = abs(c.getLevel()-5 + rand % 11);
      string name = "Lvl: " + lvl + " " + rarity + " Bow";
      return new Bow(lvl, randomVal, name);
    }

};

#endif // __CREATE_ARCHER_ITEM__
