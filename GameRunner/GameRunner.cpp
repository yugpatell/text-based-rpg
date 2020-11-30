#include "GameRunner.h"

GameRunner::GameRunner(){
	numDays = 0;
	area = FOREST;	
}

GameRunner* GameRunner::getInstance(){
	if (gameInstance = nullptr){
		gameInstance = new GameRunner();
	}
	return gameInstance;
}

void GameRunner::fight(){

}

areaType GameRunner::explore(){
	
}

void GameRunner::useInventory(){

}

void GameRunner::rest(){
	
}

int GameRunner::getNumDays(){
	return numDays;
}

areaType GameRunner::getArea(){
	return area;
}

void GameRunner::nextDay(){
	numDays += 1;
}

void GameRunner::changeArea(areaType area){
	this->area = area;
}
