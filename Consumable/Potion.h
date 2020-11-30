#ifndef __POTION_H__
#define __POTION_H__

#include "Consumable.h"
#include <string>

class Potion : public Consumable {
        public:
                Potion() : Consumable() {
                }
                Potion(int lvl, int rarity, string n) : Consumable(lvl, rarity, n) {
                }
};

#endif //__POTION_H__
