#include <iostream>
#include "Menu.h"
using namespace std;

void Menu::printMenu() {
	cout << endl;
	cout << "1) Field: 5x5\n";
	cout << "2) Field: 8x8\n";
	cout << "3) Field: 10x10\n";
	cout << "4) Help\n";
	cout << "5) Undo\n";
	cout << "6) Redo\n";
	cout << "7) Quit\n";
}