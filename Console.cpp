#include <iostream>
#include "Console.h"
using namespace std;

void Console::drawMap(Cell** gameField, int length, bool isGameStarted, int atoms, int& currentChoices, bool showHelp) {
	// if 5x5 -> length is 5;  i to Y; j to X
	if (isGameStarted) {
		cout << "\nThere are " << atoms << " atoms on the map\n";
	}

	if (showHelp) cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";

	for (int i = 0; i < length + 6; i++) {
		for (int j = 0; j < length + 6; j++) {
			bool shown = false;
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
					if (j == 1 && (i >= 1 && i <= length + 4)
						||
						(j >= 2 && j < (length + 3)) && (i == 1 || i == length + 4)
						||
						(j == (length + 4) && (i >= 1 && i <= (length + 4)))
						)
					{
						cout << "  ";
					}
					else if (j == (length + 3)) cout << " ";
				}
			}
			else if (gameField[i][j].getIsBorderHere()) {
				if (gameField[i][j].getIsPlayerHere()) {
					showPlayer(j, i, length);
					if ((j == (length + 2)) && (i == 2 || i == length + 3)) cout << gameField[i][j].getBorderHere();
					shown = true; // tylko dla murow
				}
				else {
					if (
						(i == 2 && (j > 2 && j < length + 3)) // gorny 
						||
						((i == length + 3) && (j > 2 && j < length + 3))
						) // dolny
					{
						cout << gameField[i][j].getBorderHere() << gameField[i][j].getBorderHere();
					}
					else cout << gameField[i][j].getBorderHere();
					if (j == length + 2) cout << gameField[i][j].getBorderHere();
				}
			}
			else if (gameField[i][j].getIsPlayerHere() && shown != true && isGameStarted) {
				if (gameField[i][j].getAtomHere()) { // delete
					showSymbol(length + 2, j, 'O');
				}
				else if (gameField[i][j].getAtomIsHereByPlayer() && showHelp == false) {
					showSymbol(length + 2, j, 'o');
				}
				else {
					showSymbol(length + 2, j, 'P');
				}
			}
			else if ((j >= 3 && j < length + 3) && (i >= 3 && i < (length + 3))) {
				if (gameField[i][j].getAtomIsHereByPlayer()) {
					if (isGameStarted == false) {
						if (gameField[i][j].getAtomIsHereByPlayer() && gameField[i][j].getAtomHere() == false) {
							showSymbol(length + 2, j, 'X');
						}
						else if (gameField[i][j].getAtomIsHereByPlayer() && gameField[i][j].getAtomHere())
						{
							currentChoices++;
							showSymbol(length + 2, j, 'O');
						}
					}
					else {
						showSymbol(length + 2, j, 'o');
					}
				}
				else if (gameField[i][j].getAtomHere() && (isGameStarted == false || showHelp == true)) {
					showSymbol(length + 2, j, 'O');
				}
				else {
					showSymbol(length + 2, j, '.');
				}
			}
		}
		cout << endl;
	}

	if(!isGameStarted){
		cout << "\nYou have found " << currentChoices << " of " << atoms << " atoms\n";
	}
	if (showHelp) cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
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

void Console::showSymbol(int max, int j, char s) {
	if (j == max)  cout << " " << s << " ";
	else  cout << " " << s;
}