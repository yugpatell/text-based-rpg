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
		virtual bool isArmor() {
		    return true;
		}
		virtual string getName() {
		    return "";
		}
		virtual bool getChestOrPants() {
		    return 0;
		}
};	

#endif //__EQUIPABLE_H__
