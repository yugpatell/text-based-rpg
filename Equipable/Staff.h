#ifndef __STAFF_H__
#define __STAFF_H__

#include "Weapon.h"
#include <string>

class Staff : public Weapon {
        private:
                string name;
        public:
                Staff() : Weapon(){ name = " "; role = 1;}
                Staff(int lvl, int rarity, string n) : Weapon(lvl, rarity, 1){ name = n;}
                virtual string getName() { return name;}
};

#endif //__STAFF_H__
