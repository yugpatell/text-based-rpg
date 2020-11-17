#include "character.cpp"
#include <iostream>
using namespace std;

int main() {
	Character* test1 = new Character();
	cout << "Created a default character" << endl;

	string name2 = "Thomas";
	characterType role2= KNIGHT;
	Character* test2 = new Character(name2, role2);
	cout << "Created a Character with the name Thomas and the class Knight" <<endl;

	string name3 = "Yug";
	characterType role3 = MAGE;
	Character* test3 = new Character(name3, role3);
	cout << "Created a Character with the name Yug and the class Mage" <<endl;

	string name4 = "Scott";
        characterType role4 = ARCHER;
        Character* test4 = new Character(name4, role4);
        cout << "Created a Character with the name Scott and the class Archer" <<endl;

	return 0;
}
