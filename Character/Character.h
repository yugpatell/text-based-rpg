#ifndef __CHARACTER_H__
#define __CHARACTER_H__

#include <iostream>
#include <vector>
#include "../AttackStrategy/AttackStrategy.h"
#include "../Mob/mob.h"
#include "../Consumable/Consumable.cpp"
#include "../Equipable/equipable.cpp"

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
	int maxXP;
        characterType role;
        vector<Consumable *> consumables;
        vector<Equipable *> inventory;
        Equipable * chestplate;
        Equipable * leggings;
        Equipable * weapon;

    public:
        Character() {
            attackMethod = nullptr;
            chestplate = nullptr;
            leggings = nullptr;
            weapon = nullptr;
            name = "";
            int maxHP = 10;
            int currHP = 10;
            int atk = 5;
            int defense = 5;
            int level = 5;
            int currXP = 0;
	    int maxXP = 100;
        };

        void setattackMethod(AttackStrategy * attackMethod) {
            this->attackMethod = attackMethod;
        }
        void setDefense(int def) {
            defense += def;
        }

        void setAttack(int attack) {
            atk += attack;
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
	
	int getMaxXP() const {
	    return maxXP;
	}

        characterType getcharType() const {
            return role;
        }
        void setcurrHP(int additionalHP) {
            if (additionalHP + currHP < this->getMaxHP()) {
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
            if (currXP >= maxXP) {
                this->levelUp();
            }
        }
        void addConsumables(Consumable * consum) {
            consumables.push_back(consum);
        }

        void removeConsumablesAt(int index) {
            if (index < this->equipmentSize()) {
                consumables.erase(consumables.begin() + index);
            }
        }

        int consumablesSize() {
            return consumables.size();
        }

        Consumable * consumablesAt(int index) {
            if (this->consumablesSize()) {
                return consumables.at(index);
            }
            return nullptr;
        }

        void addEquipment(Equipable * equip) {
            inventory.push_back(equip);
        }
        void removeEquipmentAt(int index) {
            if (index < this->equipmentSize()) {
                inventory.erase(inventory.begin() + index);
            }
        }
        int equipmentSize() {
            return inventory.size();
        }
        Equipable * equipmentAt(int index) {
            if (index < this->equipmentSize()) {
                return inventory.at(index);
            }
            return nullptr;
        }
        void setChest(Equipable * chest) {
            chestplate = chest;
        }
        void setLeggings(Equipable * leg) {
            leggings = leg;
        }
        void setWeapon(Equipable * wep) {
            weapon = wep;
        }
        Equipable * getChestplate() {
            return chestplate;
        }
        Equipable * getLeggings() {
            return leggings;
        }
        Equipable * getWeapon() {
            return weapon;
        }


};


#endif //__CHARACTER_H__
