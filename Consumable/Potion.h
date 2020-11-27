#ifndef __POTION_H__
#define __POTION_H__

#include "Consumable.h"
#include <string>

class Potion : public Consumable {
        private:
                string name;
        public:
                Potion() : Consumable(){ name = " ";}
                Potion(int lvl, int rarity, string n) : Consumable(lvl, rarity){ name = n;}
                string getName() { return name;}
};

#endif //__POTION_H__
