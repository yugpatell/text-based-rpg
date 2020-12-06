#ifndef __GAMERUNNER_H__
#define __GAMERUNNER_H__
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
#include "../Consumable/Potion.h"
#include "../FileReader/FileReader.h"
#include "../Equipable/CreateEquipableFactory.h"
#include "../Equipable/CreateMageItemFactory.h"
#include "../Equipable/CreateArcherItemFactory.h"
#include "../Equipable/CreateKnightItemFactory.h"


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
		areaType getCurrentLocation();
		void startGame();
		void explore();
		int exploreMenu();
		void printArea();
		void fight();
		void startFight(Character *, Mob *);
		void giveDrops();
		void lootonLoc(CreateEquipableFactory *, areaType);
		int fightMenu();
        void printInventory();
		void printConsumables();
		void useInventory();
		void changeEquipment();
		void printCurrentEquipment();
		void heal();
		void createCharacter();
		int  printMenu();
		void characterOption(int option);
		void printStats();
};

#endif //__GAMERUNNER_H__
