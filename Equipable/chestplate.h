#ifndef __CHESTPLATE_H__
#define __CHESTPLATE_H__

#include "armor.h"
#include <string>

class Chestplate : public Armor {
        private:
                string name;
        public:
                Chestplate() : Armor(){ name = " ";}
                Chestplate(int lvl, int rarity, string n) : Armor(lvl, rarity, 0){ name = n;}
                string getName() { return name;}
};

#endif //__CHESTPLATE_H__

