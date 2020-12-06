#include "GameRunner.h"
#include <stdlib.h>
#include <time.h>       /* time */

string userName = "";
bool hasRested = false;

GameRunner::GameRunner() {
    numDays = 1;
    area = FOREST;
}

areaType GameRunner::getCurrentLocation() {
    return area;
}

GameRunner * GameRunner::getInstance() {
    if (gameInstance == nullptr) {
        gameInstance = new GameRunner();
    }
    return gameInstance;
}

void GameRunner::startGame() {
    createCharacter();
    while (currCharacter -> getcurrHP() > 0) {
        cout << string(15, '\n');
        characterOption(printMenu());
    }
}

void GameRunner::fight() {
    if (area == FOREST) {
        Mob * newMob = new Wolf(currCharacter -> getLevel());
        startFight(currCharacter, newMob);
    } else if (area == ARCTIC) {
        Mob * newMob = new Yeti(currCharacter -> getLevel());
        startFight(currCharacter, newMob);
    } else if (area == DESERT) {
        Mob * newMob = new Drake(currCharacter -> getLevel());
        startFight(currCharacter, newMob);
    } else {
        Mob * newMob = new Troll(currCharacter -> getLevel());
        startFight(currCharacter, newMob);
    }
}

void GameRunner::startFight(Character * currCharacter, Mob * newMob) {
    cout << string(15, '\n');
    cout << "You have encountered a level " << newMob -> get_mob_lvl() << " " << newMob -> getName() << " with " << newMob -> get_mob_hp() << "HP !" << endl;
    int mobMaxHP = newMob -> get_mob_hp();
    while (currCharacter -> getcurrHP() > 0) {
        cout << string(5, '\n');
        cout << userName << "'s HP: " << currCharacter -> getcurrHP() << "/" << currCharacter -> getMaxHP() << ", " << newMob -> getName() << "'s HP: " << newMob -> get_mob_hp() << "/" << mobMaxHP << endl;
        int option = fightMenu();
        if (option == 1) {
            newMob -> set_mob_hp(currCharacter -> attack(newMob));
            cout << endl << userName << " attacks the " << newMob -> getName() << ", dealing " << currCharacter -> attack(newMob) << " damage!" << endl;
            if (newMob -> get_mob_hp() > 0) {
                currCharacter -> setcurrHPAttack(newMob -> attackChar(currCharacter -> getDefense()));
                cout << newMob -> getName() << " attacks " << userName << ", dealing " << newMob -> attackChar(currCharacter -> getDefense()) << " damage!" << endl;
            }
        } else if (option == 2) {
            if (currCharacter -> consumablesSize() > 0) {
                printConsumables();
                int option;
                cout << "Select one of the options by the Potion number: ";
                cin >> option;
                currCharacter -> setcurrHP(currCharacter -> consumablesAt(option - 1) -> getValue());
                currCharacter -> removeConsumablesAt(option - 1);
            } else {
                cout << "Sorry! You DONT have any consumables!";
            }
        } else if (option == 3) {
            cout << "You have decided to flee!" << endl;
            return;
        }

        if (currCharacter -> getcurrHP() <= 0) {
            cout << "YOUR CHARACTER HAS DIED!";
        }
        if (newMob -> get_mob_hp() <= 0) {
            cout << "You have killed the " << newMob -> getName() << " and received some loot!" << endl;
            cout << userName << " gained " << newMob -> get_mob_exp() << " XP!" << endl;
            currCharacter -> setcurrXP(newMob -> get_mob_exp());
            currCharacter -> levelUp();
            giveDrops();
            numDays++;
            hasRested = false;
            break;
        }
    }
}
void GameRunner::giveDrops() {
    if (currCharacter -> getcharType() == MAGE) {
        CreateEquipableFactory * loot = new CreateMageItemFactory();
        this -> lootonLoc(loot, this -> getCurrentLocation());
    } else if (currCharacter -> getcharType() == ARCHER) {
        CreateEquipableFactory * loot = new CreateArcherItemFactory();
        this -> lootonLoc(loot, this -> getCurrentLocation());

    } else {
        CreateEquipableFactory * loot = new CreateKnightItemFactory();
        this -> lootonLoc(loot, this -> getCurrentLocation());
    }
}

void GameRunner::lootonLoc(CreateEquipableFactory * loot, areaType currArea) {
    if (currArea == FOREST) {
        currCharacter -> addEquipment(loot -> CreateChestArmor(currCharacter));
    } else if (currArea == ARCTIC) {
        currCharacter -> addEquipment(loot -> CreateWeapon(currCharacter));
    } else if (currArea == DESERT) {
        currCharacter -> addEquipment(loot -> CreateLegArmor(currCharacter));
    } else {
        FileReader reader("FileReader/Rarity.txt");
        srand(time(NULL));
        int randomVal = (rand() % reader.rarities.size()) + 1;
        string rarity = reader.rarities.at(randomVal - 1);
        int lvl = abs(currCharacter->getLevel() - 6 + rand() % 11) + 1;
        currCharacter -> addConsumables(new Potion(lvl, randomVal, rarity));
    }
}

int GameRunner::fightMenu() {
    cout << "--------------------------------------------------" << endl;
    cout << "1) ATTACK               3) RUN" << endl;
    cout << "2) USE HEAL ITEM " << endl;
    cout << "--------------------------------------------------" << endl;
    cout << "Select one of the options by entering 1-3 inputs: ";
    int input;
    cin >> input;

    if (input < 1 || input > 3) {
        cout << "INVALID INPUT DETECTED, REPROMPTING THE MENU!";
        this -> printMenu();
    }
    return input;
}
void GameRunner::printConsumables() {
    cout << string(15, '\n');
    if (currCharacter -> consumablesSize() > 0) {
        cout << "--------------------------------------------------" << endl;
    } else {
        cout << endl << "EMPTY CONSUMABLES!" << endl;
    }
    for (unsigned int i = 0; i < currCharacter -> consumablesSize(); i++) {
        cout << "POTION #" << i + 1 << endl;
        cout << "NAME - " << currCharacter -> consumablesAt(i) -> getName()  << " Potion" << endl;
        cout << "HEAL VALUE - " << currCharacter -> consumablesAt(i) -> getValue() << endl;
        cout << "--------------------------------------------------" << endl;
    }
}

void GameRunner::explore() {
    cout << string(15, '\n');
    cout << userName << ", your current location is: ";
    printArea();
    int choice = exploreMenu();
    if (choice == 1) {
        area = FOREST;
    } else if (choice == 2) {
        area = CAVE;
    } else if (choice == 3) {
        area = DESERT;
    } else {
        area = ARCTIC;
    }
    cout << userName << ", your new location is: ";
    printArea();
}

int GameRunner::exploreMenu() {
    cout << "--------------------------------------------------" << endl;
    cout << "1) FOREST             3) DESERT" << endl;
    cout << "2) CAVE               4) ARCTIC " << endl;
    cout << "--------------------------------------------------" << endl;

    cout << "Select one of the options by entering 1-4 inputs: ";
    int input;
    cin >> input;

    if (input < 1 || input > 4) {
        cout << "INVALID INPUT DETECTED, REPROMPTING THE MENU!";
        this -> exploreMenu();
    }
    return input;
}
void GameRunner::printArea() {
    if (area == 0) {
        cout << "FOREST" << endl;
    } else if (area == 1) {
        cout << "ARCTIC" << endl;
    } else if (area == 2) {
        cout << "DESERT" << endl;
    } else {
        cout << "CAVE" << endl;
    }
}
void GameRunner::printInventory() {
    cout << string(15, '\n');
    if (currCharacter -> equipmentSize() > 0) {
        cout << "--------------------------------------------------" << endl;
    } else {
        cout << endl << "EMPTY INVENTORY!" << endl;
    }
    for (unsigned int i = 0; i < currCharacter -> equipmentSize(); i++) {
        cout << "ITEM #" << i + 1 << endl;
        cout << "NAME - " << currCharacter -> equipmentAt(i) -> getName() << endl;
        if (currCharacter -> equipmentAt(i) -> isArmor()) {
            cout << "ARMOR VALUE - " << currCharacter -> equipmentAt(i) -> getValue() << endl;
        } else {
            cout << "WEAPON DMG - " << currCharacter -> equipmentAt(i) -> getValue() << endl;
        }
        cout << "--------------------------------------------------" << endl;
    }
}

void GameRunner::useInventory() {
    cout << "--------------------------------------------------" << endl;
    cout << "1) EQUIPMENT             2) CONSUMABLES" << endl;
    cout << "3) CHANGE EQUIPMENT      4) CURRENT EQUIPMENT" << endl;
    cout << "--------------------------------------------------" << endl;

    cout << "Select one of the options by entering 1-2 inputs: ";
    int input;
    cin >> input;

    if (input == 1) {
        printInventory();
    } else if (input == 2) {
        printConsumables();
    } else if (input == 3) {
        changeEquipment();
    } else if (input == 4) {
        printCurrentEquipment();
    } else {
        cout << "INVALID INPUT DETECTED, REPROMPTING THE MENU!";
        this -> useInventory();
    }
}

void GameRunner::changeEquipment() {
    printInventory();
    cout << "What item number would you like to equip";
    int choice = 0;
    cin >> choice;
    int compare = choice;
    while (choice != -1) {
        if (compare - 1 > currCharacter -> equipmentSize()) {
            cout << "INVALID ITEM NUMBER, PLEASE TRY AGAIN!" << endl;
            this -> changeEquipment();
        }

        if (currCharacter -> equipmentAt(choice - 1) -> isArmor()) {
            if (currCharacter -> equipmentAt(choice - 1) -> getChestOrPants()) {
                if (currCharacter -> getLeggings() == nullptr) {
                    currCharacter -> setLeggings(currCharacter -> equipmentAt(choice - 1));
                    currCharacter -> removeEquipmentAt(choice - 1);
                    currCharacter -> setDefense(currCharacter -> getLeggings() -> getValue());
                    cout << "You have equipped: " << currCharacter -> getLeggings() -> getName() << endl;
                } else {
                    currCharacter -> setDefense(currCharacter -> getLeggings() -> getValue() * -1);
                    currCharacter -> addEquipment(currCharacter -> getLeggings());
                    currCharacter -> setLeggings(currCharacter -> equipmentAt(choice - 1));
                    currCharacter -> removeEquipmentAt(choice - 1);
                    currCharacter -> setDefense(currCharacter -> getLeggings() -> getValue());
                    cout << "You have equipped: " << currCharacter -> getLeggings() -> getName() << endl;
                }
            } else {
                if (currCharacter -> getChestplate() == nullptr) {
                    currCharacter -> setChest(currCharacter -> equipmentAt(choice - 1));
                    currCharacter -> removeEquipmentAt(choice - 1);
                    currCharacter -> setDefense(currCharacter -> getChestplate() -> getValue());
                    cout << "You have equipped: " << currCharacter -> getChestplate() -> getName() << endl;
                } else {
                    currCharacter -> setDefense(currCharacter -> getChestplate() -> getValue() * -1);
                    currCharacter -> addEquipment(currCharacter -> getChestplate());
                    currCharacter -> setChest(currCharacter -> equipmentAt(choice - 1));
                    currCharacter -> removeEquipmentAt(choice - 1);
                    currCharacter -> setDefense(currCharacter -> getChestplate() -> getValue());
                    cout << "You have equipped: " << currCharacter -> getChestplate() -> getName() << endl;
                }
            }
        } else {
            if (currCharacter -> getWeapon() == nullptr) {
                currCharacter -> setWeapon(currCharacter -> equipmentAt(choice - 1));
                currCharacter -> removeEquipmentAt(choice - 1);
                currCharacter -> setAttack(currCharacter -> getWeapon() -> getValue());
                cout << "You have equipped: " << currCharacter -> getWeapon() -> getName() << endl;
            } else {
                currCharacter -> setAttack(currCharacter -> getWeapon() -> getValue() * -1);
                currCharacter -> addEquipment(currCharacter -> getWeapon());
                currCharacter -> setWeapon(currCharacter -> equipmentAt(choice - 1));
                currCharacter -> removeEquipmentAt(choice - 1);
                currCharacter -> setAttack(currCharacter -> getWeapon() -> getValue());
                cout << "You have equipped: " << currCharacter -> getWeapon() -> getName() << endl;
            }
        }
        cout << string(15, '\n');
        printInventory();
        cout << "What item number would you like to equip (-1 to exit)";
        cin >> choice;
    }

    printStats();
}

void GameRunner::printCurrentEquipment() {
    if (currCharacter -> getChestplate() != nullptr) {
        cout << currCharacter -> getChestplate() -> getName() << endl;
        cout << "ARMOR - " << currCharacter -> getChestplate() -> getValue() << endl;
    } else {
        cout << "You DONT have a chestplate equipped!" << endl;
    }
    if (currCharacter -> getLeggings() != nullptr) {
        cout << currCharacter -> getLeggings() -> getName() << endl;
        cout << "ARMOR - " << currCharacter -> getLeggings() -> getValue() << endl;
    } else {
        cout << "You DONT have leggings equipped!" << endl;
    }
    if (currCharacter -> getWeapon() != nullptr) {
        cout << currCharacter -> getWeapon() -> getName() << endl;
        cout << "DMG - " << currCharacter -> getWeapon() -> getValue() << endl;
    } else {
        cout << "You DONT have a weapon equipped!" << endl;
    }

}

void GameRunner::heal() {
    if (currCharacter -> getcurrHP() < currCharacter -> getMaxHP()) {
        currCharacter -> setcurrHP((currCharacter -> getMaxHP() * 3) / 10);
        cout << userName << ", your current HP is now at: " << currCharacter -> getcurrHP() << "/" << currCharacter -> getMaxHP() << endl;
        return;
    }
    cout << userName << ", you are already at MAX HP: " << currCharacter -> getcurrHP() << "/" << currCharacter -> getMaxHP();
}

void GameRunner::createCharacter() {
    cout << "Welcome! Please enter your name:";
    string name;
    cin >> name;
    userName = name;
    cout << name << ", here is a list of the three characters to play as." << endl;
    cout << "-------------------------------------------------------------------------------------------------------------------" << endl;
    cout << "1) ARCHER - The knight fell from royalty after being betrayed by the King. Now left with nowhere to go, the Knight\nstruggles to survive in the wilderness. The knight specializes in defense." << endl;
    cout << "2) MAGE - The archer ascends from poor beginnings. As he grew up, he hunted to provide for his family. After\nmonsters plagued the earth and ravaged his village, he promised to avenge his family. The archer specializes in attack." << endl;
    cout << "3) KNIGHT - The mage has mystical origins, coming from an unknown dimension. Seeking to master his skills, he travels\nthe realm, practicing his abstract sorcery. The mage specializes in HP." << endl;
    cout << "-------------------------------------------------------------------------------------------------------------------" << endl;
    cout << "Enter the corresponding number of the character you wish to play as: ";
    int charNum;
    cin >> charNum;
    if (charNum < 1 || charNum > 3) {
        cout << "Restarting character selection due to invalid input" << endl;
        this -> createCharacter();
    } else if (charNum == 1) {
        cout << "You have selected the ARCHER Character!" << endl;
        currCharacter = new Archer(name, ARCHER);
    } else if (charNum == 2) {
        cout << "You have selected the MAGE Character!" << endl;
        currCharacter = new Mage(name, MAGE);
    } else {
        cout << "You have selected the KNIGHT Character!" << endl;
        currCharacter = new Knight(name, KNIGHT);
    }
}

int GameRunner::printMenu() {
    cout << "Days Counter: " << numDays << endl;
    cout << userName << "'s LVL: " << currCharacter -> getLevel() << ", HP: " << currCharacter -> getcurrHP() << "/" << currCharacter -> getMaxHP() << ", XP: " << currCharacter -> getcurrXP() << "/" << 100 << endl;
    cout << "--------------------------------------------------" << endl;
    cout << "1) FIGHT               3) ACCESS INVENTORY" << endl;
    cout << "2) EXPLORE             4) REST" << endl;
    cout << "--------------------------------------------------" << endl;

    cout << "Select one of the options by entering 1-4 inputs: ";
    int input;
    cin >> input;

    if (input < 1 || input > 4) {
        cout << "INVALID INPUT DETECTED, REPROMPTING THE MENU!" << endl;
        this -> printMenu();
    }
    return input;

}

void GameRunner::characterOption(int option) {
    if (option == 1) {
        fight();
    } else if (option == 2) {
        explore();
    } else if (option == 3) {
        useInventory();
    } else {
        if (!hasRested) {
            heal();
            if (currCharacter->getLevel() >= 15) {
                hasRested = true;
            }
        }
        else {
            cout << "YOU HAVE ALREADY RESTED TODAY!" << endl;
        }
    }
}

void GameRunner::printStats() {
    if (currCharacter -> getLeggings() != nullptr || currCharacter -> getChestplate() != nullptr) {
        cout << "CURRENT DEFENSE - " << currCharacter -> getDefense() << endl;
    }
    if (currCharacter -> getWeapon() != nullptr) {
        cout << "CURRENT ATTACK - " << currCharacter -> getAtk() << endl;
    }
}
