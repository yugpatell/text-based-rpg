#ifndef __ARMOR_H__
#define __ARMOR_H__

#include "equipable.h"

class Armor : public Equipable{
	private:
		bool isChestPiece; //0 = chest, 1 = pants
	protected:
		Armor(): Equipable(){ isChestPiece = 0;}
		Armor(int lvl, int rarity, bool chestOrPants): Equipable(lvl, rarity){ isChestPiece = chestOrPants;}
		bool getChestOrPants(){ return isChestPiece;}
}; 


#endif //__ARMOR_H__
