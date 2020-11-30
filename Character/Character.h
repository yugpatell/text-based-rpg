#ifndef __CHARACTER_H__
#define __CHARACTER_H__

#include <iostream>
#include <vector>
#include "../AttackStrategy/AttackStrategy.h"
#include "../Mob/mob.h"
#include "../Consumable/Consumable.cpp"

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
        vector<Consumable *> consumables;

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
        void setcurrHP(int additionalHP) {
            if (additionalHP + currHP > this->getMaxHP()) {
                currHP += additionalHP;
            }
            else {
                currHP = maxHP;
            }
        }
        void setcurrHPAttack(int additionalHP) {
            currHP -= additionalHP;
        }
        void setcurrXP(int XP) {
            currXP += XP;
            if (currXP >= 100) {
                this->levelUp();
            }
        }
        void addConsumables(Consumable * consum) {
            consumables.push_back(consum);
        }
        void removeConsumablesAt(int index) {
            consumables.erase(consumables.begin() + index);
        }
        int consumablesSize() {
            return consumables.size();
        }
        Consumable * consumablesAt(int index) {
            return consumables.at(index);
        }

};


#endif //__CHARACTER_H__
