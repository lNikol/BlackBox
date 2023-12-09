#include <iostream>
#include "Menu.h"
using namespace std;

void Menu::printMenu() {
	cout << "Write number from 1 to 3\n";
	cout << "1) Field: 5x5\n";
	cout << "2) Field: 8x8\n";
	cout << "3) Field: 10x10\n";
	cout << "Or write Z to end the program\n";
}

void Menu::gameMenu() {
	cout << endl;
	cout << "H) Help\n";
	cout << "u|U) Undo\n";
	cout << "r|R) Redo\n";
	cout << "x) Restart this map\n";
	cout << "k) Finish the game\n\n";
}

void Menu::showAuthor() {
	cout << "Hello!\n";
	cout << "This is game Black Box\n";
	cout << "Author:\n";
	cout << "Nikolai Lavrinov 201302\n\n\n";
}
