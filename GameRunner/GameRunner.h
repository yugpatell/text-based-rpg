#ifndef __GAMERUNNER_H__
#define __GAMERUNNER_H_
#include <string>
#include <stdlib.h>
#include "../Character/Knight.cpp"
#include "../Character/Mage.cpp"
#include "../Character/Archer.cpp"
#include "../Mob/drake.h"
#include "../Mob/goblin.h"
#include "../Mob/wolf.h"
#include "../Mob/troll.h"
#include "../Mob/yeti.h"
#include "../Consumable/Potion.h";

using namespace std;

enum areaType {FOREST, ARCTIC, DESERT, CAVE};

class GameRunner{
	private:
		int numDays;
		areaType area;
		static GameRunner* gameInstance;
		Character * currCharacter;
		GameRunner();
	public:
		static GameRunner* getInstance();
		void startGame();
		void explore();
		int exploreMenu();
		void printArea();
		void fight();
		void startFight(Character *, Mob *);
		int fightMenu();
		void printConsumables();
		void useInventory();
		void heal();
		void createCharacter();
		int  printMenu();
		void characterOption(int option);
};

#endif //__GAMERUNNER_H__
