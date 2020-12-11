#ifndef __CHAINMAIL_H__
#define __CHAINMAIL_H__

#include "Armor.h"
#include <string>

class Chainmail : public Armor {
        private:
                string name;
        public:
                Chainmail() : Armor(){ name = " "; role = 2;}
                Chainmail(int lvl, int rarity, string n) : Armor(lvl, rarity, 2, 0){ name = n;}
                virtual string getName() { return name;}
};

#endif //__CHAINMAIL_H__
