#ifndef __CREATE_MAGE_ITEM__
#define __CREATE_MAGE_ITEM__

#include "CreateEquipableFactory.h"
#include "Robe.h"
#include "SilkPants.h"
#include "Staff.h"

class CreateMageItemFactory : public CreateEquipableFactory{
  public:
    virtual Robe* CreateChestArmor(Character * c){
      FileReader reader("FileReader/Rarity.txt");
      srand(time(NULL));
      int randomVal = (rand() % reader.rarities.size()) + 1;
      string rarity = reader.rarities.at(randomVal - 1);
      int lvl = abs(c->getLevel() - 6 + rand() % 11) + 1;
      string name = "Lvl: " + to_string(lvl) + " " + rarity + " Robe";
      return new Robe(lvl, randomVal, name);
    }

    virtual SilkPants* CreateLegArmor(Character * c){
      FileReader reader("FileReader/Rarity.txt");
      srand(time(NULL));
      int randomVal = (rand() % reader.rarities.size()) + 1;
      string rarity = reader.rarities.at(randomVal - 1);
      int lvl = abs(c->getLevel() - 6 + rand() % 11) + 1;
      string name = "Lvl: " + to_string(lvl) + " " + rarity + " Silk Pants";
      return new SilkPants(lvl, randomVal, name);
    }

    virtual Staff * CreateWeapon(Character * c){
      FileReader reader("FileReader/Rarity.txt");
      srand(time(NULL));
      int randomVal = (rand() % reader.rarities.size()) + 1;
      string rarity = reader.rarities.at(randomVal - 1);
      int lvl = abs(c->getLevel() - 6 + rand() % 11) + 1;
      string name = "Lvl: " + to_string(lvl) + " " + rarity + " Staff";
      return new Staff(lvl, randomVal, name);
    }

};

#endif // __CREATE_MAGE_ITEM__
