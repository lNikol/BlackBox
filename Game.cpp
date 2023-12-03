#include <iostream>
#include <string>
#include "Game.h"
using namespace std;

void Game::shootSystem() {
	if (player.getX() == 0 && player.getY() == 0) cout << "lewy_dol\n";
	else if (player.getX() == (arrLength + 2) && player.getY() == 0) cout << "prawy_dolny\n";
	else if (player.getX() == 0 && player.getY() == (arrLength + 2)) cout << "lew_gor\n";
	else if (player.getX() == (arrLength + 2) && player.getY() == (arrLength + 2)) cout << "prawy_gor\n";
}

Cell** Game::getGameField() { return gameField; };


void Game::start() {
	menu.printMenu(menu);
	char turn = '0';
	while (turn != 'k') {
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
			console.drawMap(gameField, arrLength);

		}
		else if (turn != '\n' && isStarted) movementSystem(int(turn));

	}
}


void Game::startGame() {
	isStarted = true;
	gameField = new Cell * [arrLength + 4];
	for (int i = 0; i < arrLength + 4; i++) {
		gameField[i] = new Cell[arrLength + 4];

		for (int j = 0; j < arrLength + 4; j++) {
			gameField[i][j].setX(j);
			gameField[i][j].setY(i);

			if ((i == 0 || i == arrLength + 3) || (j == 0 || j == arrLength + 3)) {
				gameField[i][j].setIsAnswerHere(true);
				gameField[i][j].setAnswerHere('A');
			}
			if (((i < arrLength + 3) && i != 0) && ((j < arrLength + 3) && j != 0)) {

				if (i == 1 && j == 1) {
					gameField[i][j].setBorderHere(201); // lew gorn
					gameField[i][j].setIsBorderHere(true);
				}
				else if (i == 1 && j == arrLength + 2)// praw gorn
				{
					gameField[i][j].setBorderHere(187);
					gameField[i][j].setIsBorderHere(true);
				}
				else if (i == arrLength + 2 && j == 1) {// lew doln

					gameField[i][j].setBorderHere(200);
					gameField[i][j].setIsBorderHere(true);
				}
				else if (i == arrLength + 2 && j == arrLength + 2) {// praw dolny
					gameField[i][j].setBorderHere(188);
					gameField[i][j].setIsBorderHere(true);
				}
				else if ((i == 1 || i == arrLength + 2)) {
					gameField[i][j].setBorderHere(205);
					gameField[i][j].setIsBorderHere(true);

				}
				else if ((j == 1 && i < (arrLength + 2)) || (j == arrLength + 2 && i < (arrLength + 2))) {
					gameField[i][j].setBorderHere(186);
					gameField[i][j].setIsBorderHere(true);
				}


			}
			if (i == 2 && j == 2) {
				gameField[i][j].setIsPlayerHere(true);
				gameField[i][j].setY(i);
				gameField[i][j].setX(j);
			}
		}
		cout << endl;
	}
}

void Game::movement(int key) {
	int px = player.getX();
	int py = player.getY();

	switch (key) {
		//rewrite
	case 119: if (py <= arrLength + 1 && py > 2) { player.setY(player.getY() - 1); } break; //w
	case 115: if (py <= arrLength + 1 && py >= 1) { player.setY(player.getY() + 1); } break; //s
	case 97: if (px <= arrLength + 1 && px > 2) { player.setX(player.getX() - 1); } break; //a
	case 100: if (px < arrLength + 1 && px >= 2) { player.setX(player.getX() + 1); } break; //d
	}
	gameField[player.getOldX()][player.getOldY()].setIsPlayerHere(false);
	gameField[px][py].setIsPlayerHere(true);
	player.setOldX(px); player.setOldY(py);

}

void Game::movementSystem(int key) {
	//game.arrLength - size of map 5x5, 7x7, 10x10

	// game.arrLength + 1 (np. 5+1=6) bo, 1,2,3,4,5 - pole gry, 0 i 6 to krancy karty
	if (key == 119 || key == 115 || key == 97 || key == 100) {
		movement(key);
		//cout << player.getX() << player.getY() << endl;
		console.drawMap(gameField, arrLength);

	}
	else {
		if (key == 113 || key == 81) { // q | Q

		}
		else if (key == 117 || key == 85) { // u | U

		}
		else if (key == 114 || key == 82) { // r | R

		}
		else if (key == 32) { // spacja
			shootSystem();
		}
		else if (key == 111) { // o

		}
		else if (key == 112) { // p

		}
		else if (key == 72) { // H

		}
		else if (key == 107) { // k
			isStarted = false;
			cout << "End" << endl;
		}
		else {
			cout << "Wrong symbol" << endl;
		}
	}
}

void Game::render() {

}