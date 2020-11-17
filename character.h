#ifndef __CHARACTER_H__
#define __CHARACTER_H__

#include <string>
#include <vector>

using namespace std;

enum characterType {KNIGHT, MAGE, ARCHER};

class Character {
	private:
		static Character* _instance;
	protected:
		string name;
		int maxHP;
		int currHP;
	 	characterType role;
		int atk; //attack
		int defense;
		int level;
		int currExp;
		//AttackStrategy* attackMethod;
		//vector<Equipable*> currEquipment;
		//vector<Equipable*> invEquipment;
		//vector<Consumable*> invConsumable;
		Character();
		Character(string name, characterType role);
	public:
	//	virtual void attack(Mob* mob) = 0;
     		virtual void levelUp() = 0;
		static Character* getInstance();
	
		
};


#endif //__CHARACTER_H__
