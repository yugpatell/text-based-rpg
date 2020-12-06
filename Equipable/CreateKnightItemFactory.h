#ifndef __CREATE_KNIGHT_ITEM__
#define __CREATE_KNIGHT_ITEM__

#include "CreateEquipableFactory.h"
#include "Chestplate.h"
#include "ArmoredLeggings.h"
#include "Sword.h"

class CreateKnightItemFactory : public CreateEquipableFactory{
  public:
    virtual Chestplate* CreateChestArmor(Character * c){
      FileReader reader("FileReader/Rarity.txt");
      srand(time(NULL));
      int randomVal = (rand() % reader.rarities.size()) + 1;
      string rarity = reader.rarities.at(randomVal - 1);
      int lvl = abs(c->getLevel() - 6 + rand() % 11) + 1;
      string name = "Lvl: " + to_string(lvl) + " " + rarity + " Chestplate";
      return new Chestplate(lvl, randomVal, name);
    }

    virtual ArmoredLeggings* CreateLegArmor(Character * c){
      FileReader reader("FileReader/Rarity.txt");
      srand(time(NULL));
      int randomVal = (rand() % reader.rarities.size()) + 1;
      string rarity = reader.rarities.at(randomVal - 1);
      int lvl = abs(c->getLevel() - 6 + rand() % 11) + 1;
      string name = "Lvl: " + to_string(lvl) + " " + rarity + " Armored Leggings";
      return new ArmoredLeggings(lvl, randomVal, name);
    }

    virtual Sword* CreateWeapon(Character * c){
      FileReader reader("FileReader/Rarity.txt");
      srand(time(NULL));
      int randomVal = (rand() % reader.rarities.size()) + 1;
      string rarity = reader.rarities.at(randomVal - 1);
      int lvl = abs(c->getLevel() - 6 + rand() % 11) + 1;
      string name = "Lvl: " + to_string(lvl) + " " + rarity + " Sword";
      return new Sword(lvl, randomVal, name);
    }

};

#endif // __CREATE_KNIGHT_ITEM__
