#ifndef __SWORD_H__
#define __SWORD_H__

#include "Weapon.h"
#include <string>

class Sword : public Weapon {
        private:
                string name;
        public:
                Sword() : Weapon(){ name = " ";}
                Sword(int lvl, int rarity, string n) : Weapon(lvl, rarity, 0){ name = n;}
                virtual string getName() { return name;}

};

#endif //__SWORD_H__

