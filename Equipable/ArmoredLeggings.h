#ifndef __ARMOREDLEGGINGS_H__
#define __ARMOREDLEGGINGS_H__

#include "Armor.h"
#include <string>

class ArmoredLeggings : public Armor {
        private:
                string name;
        public:
                ArmoredLeggings() : Armor(){ name = " "; isChestPiece = 1;}
                ArmoredLeggings(int lvl, int rarity, string n) : Armor(lvl, rarity, 0, 1){ name = n;}
                virtual string getName() { return name;}
};

#endif //__ARMOREDLEGGINGS_H__
