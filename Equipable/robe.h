#ifndef __ROBE_H__
#define __ROBE_H__

#include "armor.h"
#include <string>

class Robe : public Armor {
        private:
                string name;
        public:
                Robe() : Armor(){ name = " ";}
                Robe(int lvl, int rarity, string n) : Armor(lvl, rarity, 1, 0){ name = n;}
                string getName() { return name;}
};

#endif //__ROBE_H__

