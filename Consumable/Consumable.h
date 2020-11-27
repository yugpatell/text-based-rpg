#ifndef __CONSUMABLE_H__
#define __CONSUMABLE_H__
	
class Consumable {
	protected:
		int level;
		int value;
	public:
		Consumable();
		Consumable(int lvl, int rarity);
		int getLevel();
		int getValue(); 
};	

#endif //__CONSUMABLE_H__
