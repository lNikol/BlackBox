#include <iostream>
#include <string>
#include "Game.h"
#include "stdlib.h"
using namespace std;

void Game::shootSystem() {
	if (player.getX() == 0 && player.getY() == 0) cout << "lewy_dol\n";
	else if (player.getX() == (arrLength + 2) && player.getY() == 0) cout << "prawy_dolny\n";
	else if (player.getX() == 0 && player.getY() == (arrLength + 2)) cout << "lew_gor\n";
	else if (player.getX() == (arrLength + 2) && player.getY() == (arrLength + 2)) cout << "prawy_gor\n";
}

Cell** Game::getGameField() { return gameField; };


void Game::start() {
	menu.printMenu();
	char turn = '0';
	while (turn != 'Z') {
		cin.get(turn);
		if (turn > 48 && turn < 52 && isStarted == false) {
			menu.gameMenu();
			switch (turn) {
			case 49: arrLength = 5; break;
			case 50: arrLength = 8; break;
			case 51: arrLength = 10; break;
			default: break;
			}
			startGame();
			console.drawMap(gameField, arrLength, isStarted, maxAtoms, counterOfCurrentChoices, showHelp);

		}
		else if (turn != '\n' && isStarted) keySystem(int(turn));
	}
}


void Game::startGame() {
	isStarted = true;
	counterOfChoices = 0;
	counterOfCurrentChoices = 0;
	gameField = new Cell * [arrLength + 6];
	for (int i = 0; i < arrLength + 6; i++) {
		gameField[i] = new Cell[arrLength + 6];

		for (int j = 0; j < arrLength + 6; j++) {
			gameField[i][j].setX(j);
			gameField[i][j].setY(i);

			if ((i == 0 || i == arrLength + 5) || (j == 0 || j == arrLength + 5)) {
				gameField[i][j].setIsAnswerHere(true);
				gameField[i][j].setAnswerHere('A'); // !!!
			}

			if ((j >= 1 && j <= arrLength + 4) && (i >= 1 && i <= arrLength + 4)) { // spacje
				if (j == 1 && (i >= 1 && i <= arrLength + 4)) {
					gameField[i][j].setIsSpaceHere(true);
				}
				else if (j == (arrLength + 4) && (i >= 1 && i <= arrLength + 4)) {
					gameField[i][j].setIsSpaceHere(true);
				}
				else if ((j >= 1 && j <= (arrLength + 4)) && (i == 1 || i == arrLength + 4)) {
					gameField[i][j].setIsSpaceHere(true);
				}
			}

			if (((i > 1 && i < arrLength + 4)) && ((j < arrLength + 4) && j > 1)) { // granicy
				if (i == 2 && j == 2) {
					gameField[i][j].setBorderHere(201); // lew gorn
					gameField[i][j].setIsBorderHere(true);
				}
				else if (i == 2 && j == arrLength + 3)// praw gorn
				{
					gameField[i][j].setBorderHere(187);
					gameField[i][j].setIsBorderHere(true);
				}
				else if (i == arrLength + 3 && j == 2) {// lew doln

					gameField[i][j].setBorderHere(200);
					gameField[i][j].setIsBorderHere(true);
				}
				else if (i == arrLength + 3 && j == arrLength + 3) {// praw dolny
					gameField[i][j].setBorderHere(188);
					gameField[i][j].setIsBorderHere(true);
				}
				else if ((i == 2 || i == arrLength + 3)) {
					gameField[i][j].setBorderHere(205);
					gameField[i][j].setIsBorderHere(true);

				}
				else if ((j == 2 && i < (arrLength + 3)) || (j == arrLength + 3 && i < (arrLength + 3))) {
					gameField[i][j].setBorderHere(186);
					gameField[i][j].setIsBorderHere(true);
				}
			}
			if (i == 3 && j == 3) gameField[i][j].setIsPlayerHere(true);
		}
		cout << endl;
	}
	randomAtoms();

}

void Game::movement(int key) {
	int px = player.getX();
	int py = player.getY();

	switch (key) {
	case 87:
	case 119: if (py <= arrLength + 4 && py > 1) { player.setY(player.getY() - 1); } break; // W || w

	case 83:
	case 115: if (py < arrLength + 4 && py >= 1) { player.setY(player.getY() + 1); } break; // S || s

	case 65:
	case 97: if (px <= arrLength + 4 && px > 1) { player.setX(player.getX() - 1); } break; // A || a

	case 68:
	case 100: if (px < arrLength + 4 && px >= 1) { player.setX(player.getX() + 1); } break; // D || d
	}
	px = player.getX();
	py = player.getY();

	gameField[player.getOldY()][player.getOldX()].setIsPlayerHere(false);
	gameField[py][px].setIsPlayerHere(true);
	player.setOldX(px); player.setOldY(py);

	console.drawMap(gameField, arrLength, isStarted, maxAtoms, counterOfCurrentChoices, showHelp);

}

void Game::keySystem(int key) {
	//game.arrLength - size of map 5x5, 7x7, 10x10

	// game.arrLength + 1 (np. 5+1=6) bo, 1,2,3,4,5 - pole gry, 0 i 6 to krancy karty
	if (key == 87 || key == 119
		|| key == 83 || key == 115
		|| key == 65 || key == 97
		|| key == 68 || key == 100) {
		movement(key);

	}
	else {
		if (key == 113 || key == 81) { // q | Q

		}
		else if (key == 117 || key == 85) { // u | U

		}
		else if (key == 114 || key == 82) { // r | R

		}
		else if (key == 32) { // spacja
			cout << "shoot\n";
			shootSystem();
		}
		else if (key == 109) {// m
			menu.gameMenu();
		}
		else if (key == 111) { // o
			setAtomByPlayer();
		}
		else if (key == 112) { // p

		}
		else if (key == 72) { // H
			showHelp = true;
			console.drawMap(gameField, arrLength, isStarted, maxAtoms, counterOfCurrentChoices, showHelp);
			showHelp = false;
		}
		else if (key == 107) { // k
			endGame();
		}
		else {
			cout << "Wrong symbol" << endl;
		}
	}
}

void Game::render() {

}

void Game::setAtomByPlayer() {
	int px = player.getX();
	int py = player.getY();
	if (gameField[py][px].getAtomIsHereByPlayer()) {
		gameField[py][px].setAtomIsHereByPlayer(false);
		counterOfChoices--;
	}
	else {
		if (counterOfChoices < maxAtoms) {
			gameField[py][px].setAtomIsHereByPlayer(true);
			counterOfChoices++;
		}
		else cout << "Limit of choices\n";
	}
}

void Game::randomAtoms() {
	srand(0);
	int rand1 = rand() % arrLength + 3, rand2 = rand() % arrLength + 3;

	switch (arrLength)
	{
	case 5: maxAtoms = 3; break;
	case 8: maxAtoms = 5; break;
	case 10: maxAtoms = 8; break;
	default:break;
	}

	for (int i = 0; i < maxAtoms; i++) {
		if (gameField[rand1][rand2].getAtomHere() == false) {
			gameField[rand1][rand2].setAtomHere(true);
		}
		else {
			while (gameField[rand1][rand2].getAtomHere() == true) {
				rand1 = rand() % arrLength + 3;
				rand2 = rand() % arrLength + 3;
			}
			gameField[rand1][rand2].setAtomHere(true);
		}
	}
}

void Game::endGame() {
	if (counterOfChoices == maxAtoms) {
		isStarted = false;
		console.drawMap(gameField, arrLength, isStarted, maxAtoms, counterOfCurrentChoices, showHelp);
		delete[] gameField;
	}
	else {
		cout << "You have " << maxAtoms - counterOfChoices << " more choice(s)\n";
	}

}