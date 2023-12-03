#include <iostream>
#include "Console.h"
using namespace std;

void Console::drawMap(Cell** gameField, int length) {
	// if 5x5 -> length is 5;  i to Y; j to X
	for (int i = 0; i < length + 6; i++) {
		for (int j = 0; j < length + 6; j++) {
			bool shown = false;

			//cout << (gameField[i][j].getX()) << (gameField[i][j].getY()) << " ";
			if (gameField[i][j].getIsAnswerHere()) {
				if (j < length + 4) cout << gameField[i][j].getAnswerHere() << " ";
				else if (j == length + 4) cout << gameField[i][j].getAnswerHere();
				else if (j == length + 5) cout << " " << (gameField[i][j].getAnswerHere());
			}

			if (gameField[i][j].getIsSpaceHere()) { // optymalizacja!
				if (gameField[i][j].getIsPlayerHere()) {
					showPlayer(j, i, length);
				}
				else {
					if (j == 1 && (i >= 1 && i <= length + 4)) {
					cout << "  ";
				}
				else if ((j >= 2 && j < (length + 3)) && (i == 1 || i == length + 4)) {
					cout << "  ";
				}
				else if (j == (length + 3)) cout << " ";
				else if (j == (length + 4) && (i >= 1 && i <= (length + 4))) {
					cout << "  ";
				}	
				}
			}
			else if (gameField[i][j].getIsBorderHere()) {
				if (gameField[i][j].getIsPlayerHere()) {
					showPlayer(j, i, length);
					if (( j == (length + 2)) && (i == 2 || i == length + 3)) cout << (gameField[i][j].getBorderHere());
					shown = true; // tylko dla murow
				}
				else{
					if (
						(i == 2 && (j > 2 && j < length + 3)) // gorny 
						||
						((i == length + 3) && (j > 2 && j < length + 3))
						) // dolny
					{
						cout << (gameField[i][j].getBorderHere()) << (gameField[i][j].getBorderHere());
						//cout << (gameField[i][j].getX()) << (gameField[i][j].getY()) << " ";
					}
					else cout << (gameField[i][j].getBorderHere());
					if (j == length + 2) cout << (gameField[i][j].getBorderHere());
				}
			}
			else if (gameField[i][j].getIsPlayerHere() && shown!=true) {
				if (j == length + 2)  cout << " P ";
				else  cout << " P";
			}
			else if ((j >= 3 && j < length + 3) && (i >= 3 && i < (length + 3))) {
				if (j == length + 2) cout << " . ";
				else cout << " .";
			}
		}
		cout << endl;
	}
}

void Console::drawTopBorder(int length) {
	cout << "\n";
	length = length * 2 + 1 + 2; //*2 = length of space+cell, +2 = line border

	cout << "    "; // adding space for ray output 3 space for number 1 for letter

	for (int i = 0; i < length; i++) {
		(i == 0) ? cout << char(201) : (i == length - 1) ? cout << char(187) : cout << char(205);
	}
	cout << endl;
}

void Console::drawBorderContent(int length) {

	for (int i = 0; i < length; i++)
	{
		cout << "    "; // adding space for ray output 3 space for number 1 for letter


		for (int j = 0; j < length + 2; j++) {
			if (j == 0) cout << char(186);
			else if (j == length + 2 - 1) cout << " " << char(186);
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
	cout << "\n";
}

void Console::showPlayer(int x, int y, int length) {
	if ((x == 2 || x == length + 3) && (y == 2 || y == length + 3)) cout << "P"; //krawedzi
	else if (x == 1) cout << "P ";
	else if (x == (length + 3) && (y == 1 || y == (length + 4))) cout << "P";
	else if ((x == 2 || x == length + 3) && (y >= 3 && y <= length + 2)) cout << "P"; // pionowe mury
	else if ((y == 2 || y == length + 3) && (x >= 2 && x <= length + 3)) cout << " P"; // poziomy mur
	else if (x == (length + 4)) cout << " P";
	else cout << "P ";
}