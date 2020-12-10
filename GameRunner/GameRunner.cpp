  
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
    while (currCharacter->getcurrHP() > 0) {
        cout << string(15, '\n');
        characterOption(printMenu());
    }
}

void GameRunner::fight() {
    if (area == FOREST) {
        Mob * newMob = new Wolf(currCharacter->getLevel());
        startFight(currCharacter, newMob);
    } else if (area == ARCTIC) {
        Mob * newMob = new Yeti(currCharacter->getLevel());
        startFight(currCharacter, newMob);
    } else if (area == DESERT) {
        Mob * newMob = new Drake(currCharacter->getLevel());
        startFight(currCharacter, newMob);
    } else {
        Mob * newMob = new Troll(currCharacter->getLevel());
        startFight(currCharacter, newMob);
    }
}

void GameRunner::startFight(Character * currCharacter, Mob * newMob) {
    cout << string(15, '\n');
    cout << "\033[1;35mYou have encountered a level " << newMob->get_mob_lvl() << " " << newMob->getName() << " with " << newMob->get_mob_hp() << "HP !\033[0m" << endl;
    int mobMaxHP = newMob->get_mob_hp();
    while (currCharacter->getcurrHP() > 0) {
        cout << string(5, '\n');
        cout << "\033[1;33m" << userName << "'s HP: " << currCharacter->getcurrHP() << "/" << currCharacter->getMaxHP() << ", " << newMob->getName() << "'s HP: " << newMob->get_mob_hp() << "/" << mobMaxHP << "\033[0m" << endl;
        int option = fightMenu();
        if (option == 1) {
            newMob->set_mob_hp(currCharacter->attack(newMob));
            cout << endl << "\033[1;35m" << userName << " attacks the " << newMob->getName() << ", dealing " << currCharacter->attack(newMob) << " damage!\033[0m" << endl;
            if (newMob->get_mob_hp() > 0) {
                currCharacter->setcurrHPAttack(newMob->attackChar(currCharacter->getDefense()));
                cout << "\033[1;35m" << newMob->getName() << " attacks " << userName << ", dealing " << newMob->attackChar(currCharacter->getDefense()) << " damage!\033[0m" << endl;
            }
        } else if (option == 2) {
            if (currCharacter->consumablesSize() > 0) {
                printConsumables();
                int option;
                cout << "\033[1;36mSelect one of the options by the Potion number:\033[0m ";
                cin >> option;
                currCharacter->setcurrHP(currCharacter->consumablesAt(option - 1)->getValue());
                currCharacter->removeConsumablesAt(option - 1);
                currCharacter->setcurrHPAttack(newMob->attackChar(currCharacter->getDefense()));
                cout << "\033[1;35m" << newMob->getName() << " attacks " << userName << ", dealing " << newMob->attackChar(currCharacter->getDefense()) << " damage!\033[0m" << endl;
            } else {
                cout << "\033[1;31mYou DONT have any consumables!";
            }
        } else if (option == 3) {
            cout << "\033[1;30mYou have decided to flee!\033[0m" << endl;
            return;
        }

        if (currCharacter->getcurrHP() <= 0) {
            cout << "\033[1;31mYOUR CHARACTER HAS DIED!\033[0m" << endl;
        }
        if (newMob->get_mob_hp() <= 0) {
            cout << "\033[1;33mYou have killed the " << newMob->getName() << " and received some loot!\033[0m" << endl;
            cout << "\033[1;33m" << userName << " gained " << newMob->get_mob_exp() << " XP!\033[0m" << endl;
            currCharacter->setcurrXP(newMob->get_mob_exp());
            currCharacter->levelUp();
            giveDrops();
            numDays++;
            hasRested = false;
            break;
        }
    }
}
void GameRunner::giveDrops() {
    if (currCharacter->getcharType() == MAGE) {
        CreateEquipableFactory * loot = new CreateMageItemFactory();
        this->lootonLoc(loot, this->getCurrentLocation());
    } else if (currCharacter->getcharType() == ARCHER) {
        CreateEquipableFactory * loot = new CreateArcherItemFactory();
        this->lootonLoc(loot, this->getCurrentLocation());

    } else {
        CreateEquipableFactory * loot = new CreateKnightItemFactory();
        this->lootonLoc(loot, this->getCurrentLocation());
    }
}

void GameRunner::lootonLoc(CreateEquipableFactory * loot, areaType currArea) {
    if (currArea == FOREST) {
        currCharacter->addEquipment(loot->CreateChestArmor(currCharacter));
    } else if (currArea == ARCTIC) {
        currCharacter->addEquipment(loot->CreateWeapon(currCharacter));
    } else if (currArea == DESERT) {
        currCharacter->addEquipment(loot->CreateLegArmor(currCharacter));
    } else {
        FileReader reader("FileReader/Rarity.txt");
        srand(time(NULL));
        int randomVal = (rand() % reader.rarities.size()) + 1;
        string rarity = reader.rarities.at(randomVal - 1);
        int lvl = abs(currCharacter->getLevel() - 6 + rand() % 11) + 1;
        currCharacter->addConsumables(new Potion(lvl, randomVal, rarity));
    }
}

int GameRunner::fightMenu() {
    cout << "\033[1;30m--------------------------------------------------\033[0m" << endl;
    cout << "\033[1;32m1) ATTACK               3) RUN\033[0m" << endl;
    cout << "\033[1;32m2) USE HEAL ITEM\033[0m" << endl;
    cout << "\033[1;30m--------------------------------------------------\033[0m" << endl;
    cout << "\033[1;36mSelect one of the options by entering 1-3 inputs: ";
    int input;
    cin >> input;

    if (input < 1 || input > 3) {
        cout << "\033[1;31mINVALID INPUT DETECTED, REPROMPTING THE MENU!\033[0m\n";
        this->printMenu(); 
    }
    return input;
}
void GameRunner::printConsumables() {
    cout << string(15, '\n');
    if (currCharacter->consumablesSize() > 0) {
        cout << "\033[1;30m--------------------------------------------------\033[0m" << endl;
    } else {
        cout << "\033[1;31EMPTY CONSUMABLES!" << endl;
    }
    for (unsigned int i = 0; i < currCharacter->consumablesSize(); i++) {
        cout << "\033[1;35mPOTION #" << i + 1 << "\033[0m" << endl;
        cout << "\033[1;35mNAME - " << currCharacter->consumablesAt(i)->getName()  << " Potion\033[0m" << endl;
        cout << "\033[1;35mHEAL VALUE - " << currCharacter->consumablesAt(i)->getValue() << "\033[0m" << endl;
        cout << "\033[1;30m--------------------------------------------------\033[0m" << endl;
    }
}

void GameRunner::explore() {
    cout << string(15, '\n');
    cout << "\033[1;34m" << userName << ", your current location is: ";
    printArea();
    cout << "\033[0m";
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
    cout << "\033[1;34m" << userName << ", your new location is:";
    printArea();
    cout << "\033[0m";
}

int GameRunner::exploreMenu() {
    cout << "\033[1;30m--------------------------------------------------\033[0m" << endl;
    cout << "\033[1;32m1) FOREST - chest armor     3) DESERT - leg armor\033[0m" << endl;
    cout << "\033[1;32m2) CAVE - potions           4) ARCTIC - weapons\033[0m" << endl;
    cout << "\033[1;30m--------------------------------------------------\033[0m" << endl;

    cout << "\033[1;36mSelect one of the options by entering 1-4 inputs:\033[0m ";
    int input;
    cin >> input;

    if (input < 1 || input > 4) {
        cout << "\033[1;31mINVALID INPUT DETECTED, REPROMPTING THE MENU!\033[0m";
        this->exploreMenu();
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
    if (currCharacter->equipmentSize() > 0) {
        cout << "\033[1;30m--------------------------------------------------\033[0m" << endl;
    } else {
        cout << "\033[1;31mEMPTY INVENTORY!" << endl;
    }
    for (unsigned int i = 0; i < currCharacter->equipmentSize(); i++) {
        cout << "\033[1;33mITEM #" << i + 1 << "\033[0m" << endl;
        cout << "\033[1;33mNAME - " << currCharacter->equipmentAt(i)->getName() << "\033[0m" << endl;
        if (currCharacter->equipmentAt(i)->isArmor()) {
            cout << "\033[1;33mARMOR VALUE - " << currCharacter->equipmentAt(i)->getValue() << "\033[0m" << endl;
        } else {
            cout << "\033[1;33mWEAPON DMG - " << currCharacter->equipmentAt(i)->getValue() << "\033[0m" << endl;
        }
        cout << "\033[1;30m--------------------------------------------------\033[0m" << endl;
    }
}

void GameRunner::useInventory() {
    cout << "\033[1;30m--------------------------------------------------\033[0m" << endl;
    cout << "\033[1;32m1) EQUIPMENT             3) CONSUMABLES\033[0m" << endl;
    cout << "\033[1;32m2) CHANGE EQUIPMENT      4) CURRENT EQUIPMENT\033[0m" << endl;
    cout << "\033[1;30m--------------------------------------------------\033[0m" << endl;

    cout << "\033[1;36mSelect one of the options by entering 1-2 inputs:\033[0m ";
    int input;
    cin >> input;

    if (input == 1) {
        printInventory();
    } else if (input == 2) {
        changeEquipment();
    } else if (input == 3) {
        printConsumables();
    } else if (input == 4) {
        printCurrentEquipment();
    } else {
        cout << "\033[1;31mINVALID INPUT DETECTED, REPROMPTING THE MENU!\033[0m";
        this->useInventory();
    }
}

void GameRunner::changeEquipment() {
    if (currCharacter->equipmentSize() == 0) {
        cout << "\033[1;31mEMPTY INVENTORY!\033[0m" << endl;
        return;
    }
    printCurrentEquipment();
    cout << endl;
    printInventory();
    cout << "\033[1;36mWhat item number would you like to equip (-1 to exit)\033[0m";
    int choice = 0;
    cin >> choice;
    int compare = choice;
    while (choice != -1) {
        if (compare - 1 > currCharacter->equipmentSize()) {
            cout << "\033[1;31mINVALID ITEM NUMBER, PLEASE TRY AGAIN!\033[0m" << endl;
            this->changeEquipment();
	    return;
        }

        if (currCharacter->equipmentAt(choice - 1)->isArmor()) {
            if (currCharacter->equipmentAt(choice - 1)->getChestOrPants()) {
                if (currCharacter->getLeggings() == nullptr) {
                    currCharacter->setLeggings(currCharacter->equipmentAt(choice - 1));
                    currCharacter->removeEquipmentAt(choice - 1);
                    currCharacter->setDefense(currCharacter->getLeggings()->getValue());
                    cout << "\033[1;34mYou have equipped: " << currCharacter->getLeggings()->getName() << "\033[0m" << endl;
                } else {
                    currCharacter->setDefense(currCharacter->getLeggings()->getValue() * -1);
                    currCharacter->addEquipment(currCharacter->getLeggings());
                    currCharacter->setLeggings(currCharacter->equipmentAt(choice - 1));
                    currCharacter->removeEquipmentAt(choice - 1);
                    currCharacter->setDefense(currCharacter->getLeggings()->getValue());
                    cout << "\033[1;34mYou have equipped: " << currCharacter->getLeggings()->getName() << "\033[0m" << endl;
                }
            } else {
                if (currCharacter->getChestplate() == nullptr) {
                    currCharacter->setChest(currCharacter->equipmentAt(choice - 1));
                    currCharacter->removeEquipmentAt(choice - 1);
                    currCharacter->setDefense(currCharacter->getChestplate()->getValue());
                    cout << "\033[1;34mYou have equipped: " << currCharacter->getChestplate()->getName() << "\033[0m" << endl;
                } else {
                    currCharacter->setDefense(currCharacter->getChestplate()->getValue() * -1);
                    currCharacter->addEquipment(currCharacter->getChestplate());
                    currCharacter->setChest(currCharacter->equipmentAt(choice - 1));
                    currCharacter->removeEquipmentAt(choice - 1);
                    currCharacter->setDefense(currCharacter->getChestplate()->getValue());
                    cout << "\033[1;34mYou have equipped: " << currCharacter->getChestplate()->getName() << "\033[0m" << endl;
                }
            }
        } else {
            if (currCharacter->getWeapon() == nullptr) {
                currCharacter->setWeapon(currCharacter->equipmentAt(choice - 1));
                currCharacter->removeEquipmentAt(choice - 1);
                currCharacter->setAttack(currCharacter->getWeapon()->getValue());
                cout << "\033[1;34mYou have equipped: " << currCharacter->getWeapon()->getName() << "\033[0m" << endl;
            } else {
                currCharacter->setAttack(currCharacter->getWeapon()->getValue() * -1);
                currCharacter->addEquipment(currCharacter->getWeapon());
                currCharacter->setWeapon(currCharacter->equipmentAt(choice - 1));
                currCharacter->removeEquipmentAt(choice - 1);
                currCharacter->setAttack(currCharacter->getWeapon()->getValue());
                cout << "\033[1;34mYou have equipped: " << currCharacter->getWeapon()->getName() << "\033[0m" << endl;
            }
        }
        cout << string(15, '\n');
        printCurrentEquipment();
        cout << endl;
        printInventory();
        cout << "\033[1;36mWhat item number would you like to equip (-1 to exit)\033[0m";
        cin >> choice;
    }

    printStats();
}

void GameRunner::printCurrentEquipment() {
    if (currCharacter->getChestplate() != nullptr) {
        cout << "\033[1;36m" << currCharacter->getChestplate()->getName() << "\033[0m" << endl;
        cout << "\033[1;33mARMOR - " << currCharacter->getChestplate()->getValue() << "\033[0m" << endl;
    } else {
        cout << "\033[1;31mYou DONT have a chestplate equipped!\033[0m" << endl;
    }
    if (currCharacter->getLeggings() != nullptr) {
        cout << "\033[1;36m" << currCharacter->getLeggings()->getName() << "\033[0m" << endl;
        cout << "\033[1;33mARMOR - " << currCharacter->getLeggings()->getValue() << "\033[0m" << endl;
    } else {
        cout << "\033[1;31mYou DONT have leggings equipped!\033[0m" << endl;
    }
    if (currCharacter->getWeapon() != nullptr) {
        cout << "\033[1;36m" << currCharacter->getWeapon()->getName() << "\033[0m" << endl;
        cout << "\033[1;33mDMG - " << currCharacter->getWeapon()->getValue() << "\033[0m" << endl;
    } else {
        cout << "\033[1;31mYou DONT have a weapon equipped!\033[0m" << endl;
    }

}

void GameRunner::heal() {
    if (currCharacter->getcurrHP() < currCharacter->getMaxHP()) {
        currCharacter->setcurrHP((currCharacter->getMaxHP() * 3) / 10);
        cout << "\033[1;34m" << userName << ", your current HP is now at: " << currCharacter->getcurrHP() << "/" << currCharacter->getMaxHP() << "\033[0m" << endl;
        return;
    }
    cout << "\033[1;31m" << userName << ", you are already at MAX HP: " << currCharacter->getcurrHP() << "/" << currCharacter->getMaxHP() << "\033[0m" << endl;
}

void GameRunner::createCharacter() {
    cout << "\033[1;36mWelcome! Please enter your name:\033[0m";
    string name;
    getline(cin, name);
    userName = name;
    cout << "\033[1;36m" << name << ", here is a list of the three characters to play as." << "\033[0m" << endl;
    cout << "\033[1;30m-------------------------------------------------------------------------------------------------------------------\033[0m" << endl;
    cout << "\033[1;33m1) ARCHER - The archer ascends from poor beginnings. As he grew up, he hunted to provide for his family. After\nmonsters plagued the earth and ravaged his village, he promised to avenge his family. The archer specializes in attack.\033[0m\n" << endl;
    cout << "\033[1;33m2) MAGE - The mage has mystical origins, coming from an unknown dimension. Seeking to master his skills, he travels\nthe realm, practicing his abstract sorcery. The mage specializes in HP.\033[0m\n" << endl;
    cout << "\033[1;33m3) KNIGHT - The knight fell from royalty after being betrayed by the King. Now left with nowhere to go, the Knight\nstruggles to survive in the wilderness. The knight specializes in defense.\033[0m\n";
    cout << "\033[1;30m-------------------------------------------------------------------------------------------------------------------\033[0m" << endl;
    cout << "\033[1;36mEnter the corresponding number of the character you wish to play as: \033[0m";
    int charNum;
    cin >> charNum;
    if (charNum < 1 || charNum > 3) {
        cout << "\033[1;31mRestarting character selection due to invalid input\033[0m" << endl;
        cin.ignore();
        this->createCharacter();
    } else if (charNum == 1) {
        cout << "\033[1;35mYou have selected the ARCHER Character!\033[0m" << endl;
        currCharacter = new Archer(name, ARCHER);
    } else if (charNum == 2) {
        cout << "\033[1;35mYou have selected the MAGE Character!\033[0m" << endl;
        currCharacter = new Mage(name, MAGE);
    } else {
        cout << "\033[1;35mYou have selected the KNIGHT Character!\033[0m" << endl;
        currCharacter = new Knight(name, KNIGHT);
    }
}

int GameRunner::printMenu() {
    cout << "\033[1;36mDays Counter: " << numDays << "\033[0m" << endl;
    cout << "\033[1;33m" << userName << "'s LVL: " << currCharacter->getLevel() << ", HP: " << currCharacter->getcurrHP() << "/" << currCharacter->getMaxHP() << ", XP: " << currCharacter->getcurrXP() << "/" << currCharacter->getMaxXP() << "\033[0m" << endl;
    cout << "\033[1;30m--------------------------------------------------\033[0m" << endl;
    cout << "\033[1;32m1) FIGHT               3) ACCESS INVENTORY\033[0m" << endl;
    cout << "\033[1;32m2) EXPLORE             4) REST\033[0m" << endl;
    cout << "\033[1;30m--------------------------------------------------\033[0m" << endl;

    cout << "\033[1;36mSelect one of the options by entering 1-4 inputs:\033[0m ";
    int input;
    cin >> input;

    if (input < 1 || input > 4) {
        cout << "\033[1;31mINVALID INPUT DETECTED, REPROMPTING THE MENU!\033[0m" << endl;
        this->printMenu();
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
            cout << "\033[1;31mYOU HAVE ALREADY RESTED TODAY!\033[0m" << endl;
        }
    }
}

void GameRunner::printStats() {
    if (currCharacter->getLeggings() != nullptr || currCharacter->getChestplate() != nullptr) {
        cout << "\033[1;35mCURRENT DEFENSE - " << currCharacter->getDefense() << "\033[0m" << endl;
    }
    if (currCharacter->getWeapon() != nullptr) {
        cout << "\033[1;35mCURRENT ATTACK - " << currCharacter->getAtk() << "\033[0m" << endl;
    }
}
