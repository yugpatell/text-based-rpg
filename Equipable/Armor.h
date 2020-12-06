#ifndef __ARMOR_H__
#define __ARMOR_H__

#include "Equipable.h"

class Armor : public Equipable{
	protected:
		bool isChestPiece = 0; //0 = chest, 1 = pants
	public:
		Armor(): Equipable(){ isChestPiece = 0;}
		Armor(int lvl, int rarity, int role, bool chestOrPants): Equipable(lvl, rarity, role){ isChestPiece = chestOrPants;}
		bool getChestOrPants(){ return isChestPiece;}
};


#endif //__ARMOR_H__
