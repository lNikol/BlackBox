#include <iostream>
#include "Console.h"
using namespace std;

void Console::showAuthor() {
	cout << "Hello!\n";
	cout << "This is game Black Box\n";
	cout << "Author:\n";
	cout << "Nikolai Lavrinov 201302\n\n";

}

void Console::drawTopBorder(int length) {
	cout << "\n\n";
	length = length * 2 + 1 + 2; //*2 = length of space+cell, +2 = line border

	cout << "    "; // adding space for ray output 3 space for number 1 for letter

	for (int i = 0; i < length; i++) {
		(i == 0) ? cout << char(201) : (i == length - 1) ? cout << char(187) : cout << char(205);
	}
	cout << endl;
}

void Console::drawBorderContent (int length) {

	for (int i = 0; i < length; i++)
	{
		cout << "    "; // adding space for ray output 3 space for number 1 for letter


		for (int j = 0; j < length+2; j++) {
			if (j == 0) cout << char(186);
			else if (j == length+2-1) cout << " " << char(186);
			else cout << " .";
		}
		cout << "    "; // adding space for ray output 3 space for number 1 for letter


		cout << endl;

	}
	
}

void Console::drawBottomBorder(int length) {
	cout << "    "; // adding space for ray output 3 space for number 1 for letter

	length = length * 2 + 1 + 2; //*2 = length of space+cell, +2 = line border
	for (int i = 0; i < length; i++) (i == 0) ? cout << char(200) : (i == length - 1) ? cout << char(188) : cout << char(205);
	cout << endl;
	cout << "\n\n";
}

void Console::showPlayer(Game& game) {
	game.player.getX();

}
