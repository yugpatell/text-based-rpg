#ifndef __CONSUMABLE_H__
#define __CONSUMABLE_H__

#include <string>

class Consumable {
	protected:
		int level;
		int value;
		string name;
	public:
		Consumable();
		Consumable(int lvl, int rarity, string name);
		int getLevel();
		int getValue();
		string getName();
};	

#endif //__CONSUMABLE_H__
