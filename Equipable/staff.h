#ifndef __STAFF_H__
#define __STAFF_H__

#include "weapon.h"
#include <string>

class Staff : public Weapon {
        private:
                string name;
        public:
                Staff() : Weapon(){ name = " ";}
                Staff(int lvl, int rarity, string n) : Weapon(lvl, rarity, 1){ name = n;}
                string getName() { return name;}
};

#endif //__STAFF_H__

