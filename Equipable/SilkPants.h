#ifndef __SILKPANTS_H__
#define __SILKPANTS_H__

#include "Armor.h"
#include <string>

class SilkPants : public Armor {
        private:
                string name;
        public:
                SilkPants() : Armor(){ name = " ";  isChestPiece = 1; role = 1;}
                SilkPants(int lvl, int rarity, string n) : Armor(lvl, rarity, 1, 1){ name = n;}
                virtual string getName() { return name;}
};

#endif //__SILKPANTS_H__
