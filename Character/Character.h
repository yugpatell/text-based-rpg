#ifndef __CHARACTER_H__
#define __CHARACTER_H__

#include <iostream>
#include "../AttackStrategy/AttackStrategy.h"
using namespace std;

enum characterType {KNIGHT, MAGE, ARCHER};

class Character {
    protected:
        AttackStrategy * attackMethod;
        string name;
        int maxHP;
        int currHP;
        int atk;
        int defense;
        int level;
        int currXP;
        characterType role;

    public:
        Character() {
            attackMethod = nullptr;
            name = "";
            int maxHP = 10;
            int currHP = 10;
            int atk = 5;
            int defense = 5;
            int level = 5;
            int currXP = 5;
        };

        void setattackMethod(AttackStrategy * attackMethod) {
            this->attackMethod = attackMethod;
        }

        virtual void attack() = 0;

        virtual void levelUp() = 0;
};


#endif //__CHARACTER_H__
