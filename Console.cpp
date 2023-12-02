#include <iostream>
#include "Console.h"
using namespace std;

void Console::drawMap(Cell** gameField, int length) {
	// if 5x5 -> length is 5	; i to Y; j to X
	for (int i = 0; i < length + 4; i++) {
		for (int j = 0; j < length + 4; j++) {
			//cout << (gameField[i][j].getX()) << (gameField[i][j].getY()) << " ";
			if (gameField[i][j].getIsAnswerHere()) {
				if ((j == 0) && i < (length + 3)) cout << (gameField[i][j].getAnswerHere()) << " ";
				else if (j == (length + 3) && i < (length + 3)) cout << " " << (gameField[i][j].getAnswerHere());
				else if (j < length + 3) cout << (gameField[i][j].getAnswerHere()) << " ";
			}
			else if (gameField[i][j].getIsBorderHere()) {
				if (
					(i == 1 && j != 1) && ((i == 1) && (j != length + 2)) // gorny 
					||
					(((i == length + 2) && (j != length + 2)) && ((i == length + 2) && (j != 1)))
					) // dolny
				{
					cout << (gameField[i][j].getBorderHere()) << (gameField[i][j].getBorderHere());
				}
				else cout << (gameField[i][j].getBorderHere());
			}
			else if (gameField[i][j].getPlayerHere()) cout << " P";
			else if (j == length + 1) cout << ". ";// fix
			else cout << " .";
		}
		cout << endl;


	}
	//for (int i = 0; i < length + 2; i++) {
	//	for (int j = 0; j < length + 2; j++) {
	//		if (gameField[i][j].getBorderHere()) {

	//			if (j == 0 && i == 0) cout << char(201);
	//			else if (j == length + 1 && i == 0) cout << char(187);
	//			else if (j == 0 && i < length + 1) cout << char(186);
	//			else if (j == length + 1 && i < length + 1) cout << char(186);
	//			else if (j == 0 && i == length + 1) cout << char(200);
	//			else if (j == length + 1 && i == length + 1) cout << char(188);
	//			else { cout << char(205); cout << char(205); }

	//			//(i == 0) ? cout << char(201) : (j !=0 && j<length+2) ? cout << char(205) : cout << char(187); // draw top
	//			//(i == length) ? cout << char(200) : (j == length + 2) ? cout << char(205) : cout << char(188); // draw down

	//			//if (j == 0) cout << char(186);
	//			//else if (j == length + 2) cout << " " << char(186);

	//		}
	//		else if (gameField[i][j].getPlayerHere()) {
	//			cout << " P";
	//		}
	//		else cout << " .";
	//	}
	//	cout << endl;
	//}

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