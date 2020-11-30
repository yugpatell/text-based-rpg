#include "GameRunner.h"
#include <stdlib.h>
#include <time.h>       /* time */

string userName = "";

GameRunner::GameRunner(){
	numDays = 1;
	area = ARCTIC;
}

GameRunner* GameRunner::getInstance(){
	if (gameInstance == nullptr){
		gameInstance = new GameRunner();
	}
	return gameInstance;
}

void GameRunner::startGame() {
    createCharacter();
    Consumable * test = new Potion(1, 1, "test");
    currCharacter->addConsumables(test);
    while(currCharacter->getcurrHP() > 0) {
        cout << string(35, '\n');
        characterOption(printMenu());
    }
}

void GameRunner::fight() {
    if (area == FOREST) {
        Mob * newMob = new Wolf(currCharacter->getDefense());
        startFight(currCharacter, newMob);
    }
    else if (area == ARCTIC) {
        Mob * newMob = new Yeti(currCharacter->getDefense());
        startFight(currCharacter, newMob);
    }
    else if (area == DESERT) {
        Mob * newMob = new Drake(currCharacter->getDefense());
        startFight(currCharacter, newMob);
    }
    else {
        Mob * newMob = new Troll(currCharacter->getDefense());
        startFight(currCharacter, newMob);
    }
}

void GameRunner::startFight(Character * currCharacter, Mob * newMob) {
    cout << string(35, '\n');
    system("Color 5");
    cout << "You have encountered a level " << newMob->get_mob_lvl() << " " << newMob->getName() << " with " << newMob->get_mob_hp() << "HP !" << endl;
    while (currCharacter->getcurrHP() > 0) {
        int option = fightMenu();
        if (option == 1) {
            newMob->set_mob_hp(currCharacter->attack(newMob));
            system("Color 5");
            cout << userName << " attacks the " << newMob->getName() << ", dealing " << currCharacter->attack(newMob) << " damage!" <<  endl;
            currCharacter->setcurrHPAttack(newMob->attackChar(currCharacter->getDefense()));
            cout << newMob->getName() << " attacks " << userName << ", dealing " << newMob->attackChar(currCharacter->getDefense()) << " damage!" << endl;
            system("Color 7");
        }
        else if (option == 2) {
            if (currCharacter->consumablesSize() > 0) {
                printConsumables();
                int option;
                cout << "Select one of the options by the Potion number: ";
                cin >> option;
                currCharacter->setcurrHP(currCharacter->consumablesAt(option - 1)->getValue());
                currCharacter->removeConsumablesAt(option - 1);
            }
            else {
                cerr << "Sorry! You DONT have any consumables!" << endl;
            }
        }
        else if (option == 3) {
            cout << "You have decided to flee!" << endl;
            return;
        }

        if (currCharacter->getcurrHP() <= 0) {
            cerr << "YOUR CHARACTER HAS DIED!" << endl;
        }
        else if (newMob->get_mob_hp() <= 0) {
            system("Color 5");
            cout << "You have killed the " << newMob->getName() << " and received some loot!" << endl;
            cout << userName << " gained " << newMob->get_mob_exp() << " XP!";
            currCharacter->setcurrXP(newMob->get_mob_exp());
            numDays++;
        }
    }
    system("Color 7");
}
int GameRunner::fightMenu() {
    system("Color 8");
    cout << "--------------------------------------------------" << endl;
    system("Color B");
    cout << "1) ATTACK               3) RUN" << endl;
    cout << "2) USE HEAL ITEM " << endl;
    system("Color 8");
    cout << "--------------------------------------------------" << endl;

    system("Color 7");
    cout << "Select one of the options by entering 1-3 inputs: ";
    int input;
    cin >> input;

    if (input < 1 || input > 3) {
        cerr << "INVALID INPUT DETECTED, REPROMPTING THE MENU!" << endl;
        this->printMenu();
    }
    return input;
}
void GameRunner::printConsumables() {
    cout << string(35, '\n');
    system("Color 8");
    cout << "--------------------------------------------------" << endl;
    for (unsigned int i = 0; i < currCharacter->consumablesSize(); i++) {
        system("Color B");
        cout << "POTION #" << i + 1 << endl;
        cout << "HEAL VALUE - " << currCharacter->consumablesAt(i)->getValue() << endl;

        if (i > 1) {
            system("Color 8");
            cout << "--------------------------------------------------" << endl;
        }
    }
    system("Color 8");
    cout << "--------------------------------------------------" << endl;
    system("Color 7");
}

void GameRunner::explore() {
    system("Color D");
    cout << string(35, '\n');
    cout << userName << ", your current location is: ";
    printArea();
    int choice = exploreMenu();
    if (choice == 1) {
       area = FOREST;
    }
    else if (choice == 2) {
       area = CAVE;
       system("Color D");
    }
    else if (choice == 3) {
       area = DESERT;
       system("Color D");
    }
    else {
       area = ARCTIC;
    }
    system("Color D");
    cout << userName << ", your new location is: ";
    printArea();
}

int GameRunner::exploreMenu() {
    system("Color 8");
    cout << "--------------------------------------------------" << endl;
    system("Color B");
    cout << "1) FOREST             3) DESERT" << endl;
    cout << "2) CAVE               4) ARCTIC " << endl;
    system("Color 8");
    cout << "--------------------------------------------------" << endl;

    system("Color 7");
    cout << "Select one of the options by entering 1-4 inputs: ";
    int input;
    cin >> input;

    if (input < 1 || input > 4) {
        cerr << "INVALID INPUT DETECTED, REPROMPTING THE MENU!" << endl;
        this->exploreMenu();
    }
    return input;
}
void GameRunner::printArea() {
    if (area == 0) {
        cout << "FOREST" << endl;
    }
    else if (area == 1) {
        cout << "ARCTIC" << endl;
    }
    else if (area == 2) {
        cout << "DESERT" << endl;
    }
    else {
        cout << "CAVE" << endl;
    }
    system("Color 7");
}

void GameRunner::useInventory() {
    system("Color 8");
    cout << "--------------------------------------------------" << endl;
    system("Color B");
    cout << "1) EQUIPMENT             2) CONSUMABLES" << endl;
    system("Color 8");
    cout << "--------------------------------------------------" << endl;

    system("Color 7");
    cout << "Select one of the options by entering 1-2 inputs: ";
    int input;
    cin >> input;

    if (input == 1) {

    }
    else if (input == 2) {
        printConsumables();
    }
    else {
        cerr << "INVALID INPUT DETECTED, REPROMPTING THE MENU!" << endl;
        this->useInventory();
    }
}

void GameRunner::heal() {
    if (currCharacter->getcurrHP() < currCharacter->getMaxHP()) {
        currCharacter->setcurrHP(currCharacter->getMaxHP() * 0.30);
        system("Color 5");
        cout << userName << ", your current HP is now at: " << currCharacter->getcurrHP() << "/" << currCharacter->getMaxHP() << endl;
        system("Color 7");
    }
    cerr << userName << ", you are already at MAX HP: " << currCharacter->getcurrHP() << "/" << currCharacter->getMaxHP() << endl;
}

void GameRunner::createCharacter() {
    cout << "Welcome! Please enter your name:";
    string name;
    cin >> name;
    userName = name;
    cout << name << ", here is a list of the three characters to play as." << endl;
    system("Color 2");
    cout << "-------------------------------------------------------------------------------------------------------------------" << endl;
    system("Color B");
    cout << "1) ARCHER - The knight fell from royalty after being betrayed by the King. Now left with nowhere to go, the Knight\nstruggles to survive in the wilderness. The knight specializes in defense." << endl;
    cout << "2) MAGE - The archer ascends from poor beginnings. As he grew up, he hunted to provide for his family. After\nmonsters plagued the earth and ravaged his village, he promised to avenge his family. The archer specializes in attack." << endl;
    cout << "3) KNIGHT - The mage has mystical origins, coming from an unknown dimension. Seeking to master his skills, he travels\nthe realm, practicing his abstract sorcery. The mage specializes in HP." << endl;
    system("Color 2");
    cout << "-------------------------------------------------------------------------------------------------------------------" << endl;
    system("Color 7");
    cout << "Enter the corresponding number of the character you wish to play as:";
    int charNum;
    cin >> charNum;
    if (charNum < 1 || charNum > 3) {
        cerr << "Restarting character selection due to invalid input" << endl;
        this->createCharacter();
    }
    else if (charNum == 1) {
        system("Color A");
        cout << "You have selected the ARCHER Character!" << endl;
        currCharacter = new Archer(name, ARCHER);
    }
    else if (charNum == 2) {
        system("Color A");
        cout << "You have selected the MAGE Character!" << endl;
        currCharacter = new Mage(name, MAGE);
    }
    else {
        system("Color A");
        cout << "You have selected the KNIGHT Character!" << endl;
        currCharacter = new Knight(name, KNIGHT);
    }
    system("Color 7");
}

int GameRunner::printMenu() {
    system("Color 4");
    cout << "Days Counter: " << numDays << endl;
    system("Color 8");
    cout << "--------------------------------------------------" << endl;
    system("Color B");
    cout << "1) FIGHT               3) ACCESS INVENTORY" << endl;
    cout << "2) EXPLORE             4) REST" << endl;
    system("Color 8");
    cout << "--------------------------------------------------" << endl;

    system("Color 7");
    cout << "Select one of the options by entering 1-4 inputs: ";
    int input;
    cin >> input;

    if (input < 1 || input > 4) {
        cerr << "INVALID INPUT DETECTED, REPROMPTING THE MENU!" << endl;
        this->printMenu();
    }
    return input;

}

void GameRunner::characterOption(int option) {
    if (option == 1) {
        fight();
    }
    else if (option == 2) {
        explore();
    }
    else if (option == 3) {
        useInventory();
    }
    else {
        heal();
    }

}

