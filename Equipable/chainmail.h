#ifndef __CHAINMAIL_H__
#define __CHAINMAIL_H__

#include "armor.h"
#include <string>

class Chainmail : public Armor {
        private:
                string name;
        public:
                Chainmail() : Armor(){ name = " ";}
                Chainmail(int lvl, int rarity, string n) : Armor(lvl, rarity, 0){ name = n;}
                string getName() { return name;}
};

#endif //__CHAINMAIL_H__

