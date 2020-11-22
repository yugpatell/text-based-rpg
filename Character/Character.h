#ifndef __CHARACTER_H__
#define __CHARACTER_H__

#include <iostream>
#include "../AttackStrategy/AttackStrategy.h"
#include "../Mob/mob.h"

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

        virtual int attack(Mob * currMob) = 0;

        virtual void levelUp() = 0;

        int getMaxHP() const {
            return maxHP;
        }
        int getcurrHP() const {
            return currHP;
        }
        int getAtk() const {
            return atk;
         }
        int getDefense() const {
            return defense;
        }
        int getLevel() const {
            return level;
        }
        int getcurrXP() const {
            return currXP;
        }
        void setLevel(int newLevel)  {
            for (unsigned int i = 0; i < newLevel; i++) {
                this->levelUp();
            }
        }
};


#endif //__CHARACTER_H__
