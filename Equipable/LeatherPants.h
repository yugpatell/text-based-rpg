#ifndef __LEATHERPANTS_H__
#define __LEATHERPANTS_H__

#include "Armor.h"
#include <string>

class LeatherPants : public Armor {
        private:
                string name;
        public:
                LeatherPants() : Armor(){ name = " ";  isChestPiece = 1; role = 2;}
                LeatherPants(int lvl, int rarity, string n) : Armor(lvl, rarity, 2, 1){ name = n;}
                virtual string getName() { return name;}
};

#endif //__LEATHERPANTS_H__
