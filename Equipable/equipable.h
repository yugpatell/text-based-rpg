#ifndef __EQUIPABLE_H__
#define __EQUIPABLE_H__
	
class Equipable {
	protected:
		int level;
		int value;
		int role;  //[0 = Knight, 1 = Mage, 2 = Archer]
	public:
		Equipable();
		Equipable(int lvl, int rarity, int role );
		int getLevel();
		int getValue(); 
		int getRole();
};	

#endif //__EQUIPABLE_H__
