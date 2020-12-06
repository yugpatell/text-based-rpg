#ifndef __CREATE_ARCHER_ITEM__
#define __CREATE_ARCHER_ITEM__

#include "CreateEquipableFactory.h"
#include "Chainmail.h"
#include "Bow.h"
#include "LeatherPants.h"

class CreateArcherItemFactory : public CreateEquipableFactory{
  public:
    virtual Chainmail* CreateChestArmor(Character * c){
      FileReader reader("FileReader/Rarity.txt");
      srand(time(NULL));
      int randomVal = (rand() % reader.rarities.size()) + 1;
      string rarity = reader.rarities.at(randomVal - 1);
      int lvl = abs(c->getLevel() - 6 + rand() % 11) + 1;
      string name = "Lvl: " + to_string(lvl)   + " " + rarity + " Chainmail";
      return new Chainmail(lvl, randomVal, name);
    }

    virtual LeatherPants* CreateLegArmor(Character * c){
      FileReader reader("FileReader/Rarity.txt");
      srand(time(NULL));
      int randomVal = (rand() % reader.rarities.size()) + 1;
      string rarity = reader.rarities.at(randomVal - 1);
      int lvl = abs(c->getLevel() - 6 + rand() % 11) + 1;
      string name = "Lvl: " + to_string(lvl) + " " + rarity + " Leather Pants";
      return new LeatherPants(lvl, randomVal, name);
    }

    virtual Bow* CreateWeapon(Character * c){
      FileReader reader("FileReader/Rarity.txt");
      srand(time(NULL));
      int randomVal = (rand() % reader.rarities.size()) + 1;
      string rarity = reader.rarities.at(randomVal - 1);
      int lvl = abs(c->getLevel() - 6 + rand() % 11) + 1;
      string name = "Lvl: " + to_string(lvl) + " " + rarity + " Bow";
      return new Bow(lvl, randomVal, name);
    }

};

#endif // __CREATE_ARCHER_ITEM__
