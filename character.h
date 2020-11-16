#ifndef __CHARACTER_H__
#define __CHARACTER_H__

#include <string>
#include <vector>

using namespace std;

class Character {
	private:
		static Character* _instance;
	protected:
		string name;
		int maxHP;
		int currHP;
		//enum role;
		int attack;
		int defense;
		int level;
		int currExp;
		AttackStrategy* attackMethod;
		vector<Equipable*> currEquipment;
		vector<Equipable*> invEquipment;
		vector<Consumable*> invConsumable;
		Character();
	public:
		virtual void attack(Mob* mob) = 0;
		virtual void levelUp() = 0;
		static Character* instance();
		
};


#endif //__CHARACTER_H__
