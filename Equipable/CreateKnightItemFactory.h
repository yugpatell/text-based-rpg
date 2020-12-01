#ifndef __CREATE_KNIGHT_ITEM__
#define __CREATE_KNIGHT_ITEM__

#include "CreateEquipableFactory.h"

class CreateKnightItemFactory : public CreateEquipableFactory{
  public:
    virtual Chestplate* CreateChestArmor(const Character c){
      FileReader reader("..FileReader/Rarity.txt");
      srand(time());
      int randomVal = rand%reader.rarities.size());
      string rarity = reader.rarities.at(rand%reader.rarities.size());
      int lvl = abs(c.getLevel()-5 + rand % 11);
      string name = "Lvl: " + lvl + " " + rarity + " Chestplate";
      return new Chestplate(lvl, randomVal, name);
    }

    virtual ArmoredLeggings* CreateLegArmor(const Character c){
      FileReader reader("..FileReader/Rarity.txt");
      srand(time());
      string rarity = reader.rarities.at(rand%reader.rarities.size());
      int lvl = abs(c.getLevel()-5 + rand % 11);
      string name = "Lvl: " + lvl + " " + rarity + " Armored Leggings";
      return new ArmoredLeggings(lvl, randomVal, name);
    }

    virtual Sword* CreateWeapon(const Character c){
      FileReader reader("..FileReader/Rarity.txt");
      srand(time());
      string rarity = reader.rarities.at(rand%reader.rarities.size());
      int lvl = abs(c.getLevel()-5 + rand % 11);
      string name = "Lvl: " + lvl + " " + rarity + " Sword";
      return new Sword(lvl, randomVal, name);
    }

};

#endif // __CREATE_KNIGHT_ITEM__
