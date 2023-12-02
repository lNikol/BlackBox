#include <iostream>
#include "Menu.h"
using namespace std;

void Menu::printMenu(Menu &menu) {
	menu.showAuthor();

	cout << endl;
	cout << "Write number from 1 to 3\n";
	cout << "1) Field: 5x5\n";
	cout << "2) Field: 8x8\n";
	cout << "3) Field: 10x10\n";
	
}

void Menu::gameMenu() {
	cout << endl;
	cout << "H) Help\n";
	cout << "u|U) Undo\n";
	cout << "r|R) Redo\n";
	cout << "k) Quit\n";

}

void Menu::showAuthor() {
	cout << "Hello!\n";
	cout << "This is game Black Box\n";
	cout << "Author:\n";
	cout << "Nikolai Lavrinov 201302\n\n";
	
}
