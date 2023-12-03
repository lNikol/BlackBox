#include <iostream>
#include "Console.h"
using namespace std;

void Console::drawMap(Cell** gameField, int length) {
	// if 5x5 -> length is 5;  i to Y; j to X
	for (int i = 0; i < length + 4; i++) {
		for (int j = 0; j < length + 4; j++) {
			//cout << (gameField[i][j].getX()) << (gameField[i][j].getY()) << " ";
			if (gameField[i][j].getIsAnswerHere()) {
				if (j < length + 2) cout << gameField[i][j].getAnswerHere() << " ";
				else if (j == length + 2) cout << gameField[i][j].getAnswerHere();
				else if (j == length + 3) cout << " " << (gameField[i][j].getAnswerHere());
			}
			else if (gameField[i][j].getIsBorderHere()) {
				//cout << (gameField[i][j].getX()) << (gameField[i][j].getY()) << " ";
				if (
					(i == 1 && (j > 1 && j < length + 2	)) // gorny 
					||
					((i == length + 2) && (j > 1 && j < length + 2))
					) // dolny
				{
					cout << (gameField[i][j].getBorderHere()) << (gameField[i][j].getBorderHere());
					//cout << (gameField[i][j].getX()) << (gameField[i][j].getY()) << " ";
				}
				else cout << (gameField[i][j].getBorderHere());
				if (j == (length)) cout << (gameField[i][j].getBorderHere()); // wyswietlanie brakujacego muru

			}
			else if (gameField[i][j].getIsPlayerHere()) {
				if (j == length + 1)  cout << " P ";
				else  cout << " P";
			}
			else if (j == length + 1) cout << " . ";
			else cout << " .";
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