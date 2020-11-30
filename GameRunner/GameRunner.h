#ifndef __GAMERUNNER_H__
#define __GAMERUNNER_H_

#include <string>
#include <stdlib.h>

using namespace std;

enum areaType {FOREST, ARCTIC, DESERT, CAVE};

class GameRunner{
	private:
		int numDays;
		areaType area;
		static GameRunner* gameInstance;
		GameRunner();
	public:
		static GameRunner* getInstance();
		void nextDay();
		void changeArea();
		int getNumDays();
		areaType getArea();
		void battle();
		void explore();
		void useInventory();
		void rest();	
		
};

#endif //__GAMERUNNER_H__
