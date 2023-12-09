#include <iostream>
#include <string>
#include <stdio.h>
#include "Game.h"
#include "Ray.h"
using namespace std;

void Game::shootSystem() {
	if ((player.getX() == 2 && player.getY() == 2)
		|| (player.getX() == (arrLength + 3) && player.getY() == 2)
		|| (player.getX() == 2 && player.getY() == (arrLength + 3))
		|| (player.getX() == (arrLength + 3) && player.getY() == (arrLength + 3))
		) cout << "You can't shoot, you're at the end of the border\n";
	else
	{
		int px = player.getX();
		int py = player.getY();

		if (py == arrLength + 3 || py == 2 ||
			(px == arrLength + 3 && py < (arrLength + 3)) ||
			(px == 2 && py < (arrLength + 3)))
		{
			shootCounter++;

			Ray ray;
			ray.setX(px); ray.setY(py);

			if (py == arrLength + 3) {
				setShootingInfo(px, arrLength + 4);
				ray.setDirection('0');
				ray.setStartDirection('0');
				ray.setX(px);
				ray.setY(py - 1);
			}
			else if (py == 2) {
				setShootingInfo(px, py - 1);
				ray.setDirection('1');
				ray.setStartDirection('1');
				ray.setX(px);
				ray.setY(py + 1);
			}
			else if (px == arrLength + 3 && py < (arrLength + 3)) {
				setShootingInfo(px + 1, py);
				ray.setDirection('2');
				ray.setStartDirection('2');
				ray.setX(px - 1);
				ray.setY(py);
			}
			else if (px == 2 && py < (arrLength + 3)) {
				setShootingInfo(px - 1, py);
				ray.setDirection('3');
				ray.setStartDirection('3');
				ray.setX(px + 1);
				ray.setY(py);
			}
			int rx = ray.getX();
			int ry = ray.getY();

			while ((rx > 2 && rx < (arrLength + 3)) && (ry > 2 && ry < (arrLength + 3))) {
				gameField[ry][rx].setIsRayHere(true);
				//console.drawMap(gameField, arrLength, isStarted, maxAtoms, counterOfCurrentChoices, showHelp);
				ray.setOldY(ry); ray.setOldX(rx);

				gameField[ray.getOldY()][ray.getOldX()].setIsRayHere(false);

				switch (ray.getDirection()) {
				case '0': // 0 - w - w gore
					if (gameField[ry - 1][rx].getAtomHere() || gameField[ry][rx].getAtomHere()) {
						std::cout << "case 0" << std::endl;
						ray.setIsHit(true);
						ray.setY(2);
					} break;
				case '1': // 1 - s - w dol	
					if (gameField[ry + 1][rx].getAtomHere() || gameField[ry][rx].getAtomHere()) {
						std::cout << "case 1" << std::endl;
						ray.setIsHit(true);
						ray.setY(arrLength + 3);
					}
					break;
				case '2': // 2 - a - w lewo 
					if (gameField[ry][rx - 1].getAtomHere() || gameField[ry][rx].getAtomHere()) {
						std::cout << "case 2" << std::endl;
						ray.setIsHit(true);
						ray.setY(2);
					}
					break;
				case '3': // 3 - d - w prawo
					if (gameField[ry][rx + 1].getAtomHere() || gameField[ry][rx].getAtomHere()) {
						std::cout << "case 3" << std::endl;
						ray.setIsHit(true);
						ray.setY(arrLength + 3);
					}
					break;
				default: break;
				}

				if (ray.getIsHit() == false) {
					switch (ray.getDirection()) {
					case '0': ray.setY(ry - 1); break; // 0 - w - w gore
					case '1': ray.setY(ry + 1); break; // 1 - s - w dol
					case '2': ray.setX(rx - 1); break; // 2 - a - w lewo 
					case '3': ray.setX(rx + 1); break; // 3 - d - w prawo
					default: break;
					}
					int coun = gameField[ry][rx].getCounterOfAtomsArea();
					cout << "coun " << coun << endl;

					int res = (coun + int(ray.getDirection())) % 4;
					cout << "res " << res << endl;

					switch (ray.getStartDirection()) {
						case '0': ray.setDirection('0'); break;
						case '1': ray.setDirection('1'); break;
						case '2': res = (coun * 2 + int(ray.getDirection())) % 4;
							switch (res) {
							case 0:break;
							case 1:break;
							case 2:break;
							case 3:break;
							default:break;
							}
							ray.setDirection('2'); break;
						case '3': ray.setDirection('3'); break;
						default: break;
					}


					switch (res) {
					case 0: ray.setDirection('0'); break;
					case 1: ray.setDirection('1'); break;
					case 2: ray.setDirection('2'); break;
					case 3: ray.setDirection('3'); break;
					default:break;
					}
					cout << "rD " << ray.getDirection() << endl;
				}
				rx = ray.getX();
				ry = ray.getY();
			}

			if (rx == 2) {
				if (ray.getIsHit()) {
					gameField[ry][0].setHitHere('H');
					gameField[ry][0].setIsHitHere(true);
				}
				else if (ray.getIsRefracted()) {
					gameField[ry][0].setHitHere('R');
					gameField[ry][0].setIsHitHere(true);
				}
				setShootingInfo(rx - 1, ry);
			}
			else if (rx == arrLength + 3) {
				if (ray.getIsHit()) {
					gameField[ry][arrLength + 5].setHitHere('H');
					gameField[ry][arrLength + 5].setIsHitHere(true);
				}
				else if (ray.getIsRefracted()) {
					gameField[ry][arrLength + 5].setHitHere('R');
					gameField[ry][arrLength + 5].setIsHitHere(true);
				}
				setShootingInfo(arrLength + 4, ry);
			}
			else if (ry == 2) {
				if (ray.getIsHit()) {
					gameField[0][rx].setHitHere('H');
					gameField[0][rx].setIsHitHere(true);
				}
				else if (ray.getIsRefracted()) {
					gameField[0][rx].setHitHere('R');
					gameField[0][rx].setIsHitHere(true);
				}
				setShootingInfo(rx, ry - 1);
			}
			else if (ry == arrLength + 3) {
				if (ray.getIsHit()) {
					gameField[arrLength + 5][rx].setHitHere('H');
					gameField[arrLength + 5][rx].setIsHitHere(true);
				}
				else if (ray.getIsRefracted()) {
					gameField[arrLength + 5][rx].setHitHere('R');
					gameField[arrLength + 5][rx].setIsHitHere(true);
				}
				setShootingInfo(rx, arrLength + 4);
			}
		}
		else cout << "You can't shoot, you're not on the border\n";

	}
	writeFieldInFields();
	console.drawMap(gameField, arrLength, isStarted, maxAtoms, counterOfCurrentChoices, showHelp);

}

void Game::setShootingInfo(int x, int y) {
	if (shootCounter >= 10) gameField[y][x].setNumberOfHitHere2('0' + (shootCounter / 10));
	gameField[y][x].setNumberOfHitHere1('0' + (shootCounter % 10));
}

Cell** Game::getGameField() { return gameField; };
Cell*** Game::getFields() { return fields; };

void Game::writeFieldInFields() {
	if (fieldsSize == presentStage) {
		increaseFieldsSize();
	}
	for (int j = 0; j < arrLength + 6; j++) {
		for (int k = 0; k < arrLength + 6; k++) {
			fields[presentStage][j][k] = gameField[j][k];
		}
	}
	lastStage = presentStage;
	presentStage++;
}

void Game::increaseFieldsSize() {
	fieldsSize += 10;

	Cell*** fields2 = new Cell * *[fieldsSize];
	for (int i = 0; i < fieldsSize; i++) {
		fields2[i] = new Cell * [arrLength + 6];
		for (int j = 0; j < arrLength + 6; j++) {
			fields2[i][j] = new Cell[arrLength + 6];
		}
	}
	// copy information from fields to fields2
	for (int i = 0; i < fieldsSize - 10; i++) {
		for (int j = 0; j < arrLength + 6; j++) {
			for (int k = 0; k < arrLength + 6; k++) {
				fields2[i][j][k] = fields[i][j][k];
			}
		}
	}

	for (int i = 0; i < fieldsSize - 10; i++) {
		for (int j = 0; j < arrLength + 6; ++j) {
			delete[] fields[i][j];
		}
		delete[] fields[i];
	}
	delete[] fields;

	fields = new Cell * *[fieldsSize];
	for (int i = 0; i < fieldsSize; i++) {
		fields[i] = new Cell * [arrLength + 6];
		for (int j = 0; j < arrLength + 6; j++) {
			fields[i][j] = new Cell[arrLength + 6];
		}
	}
	// copy information from fields2 to fields
	for (int i = 0; i < fieldsSize - 10; i++) {
		for (int j = 0; j < arrLength + 6; j++) {
			for (int k = 0; k < arrLength + 6; k++) {
				fields[i][j][k] = fields2[i][j][k];
			}
		}
	}

	for (int i = 0; i < fieldsSize; ++i) {
		for (int j = 0; j < arrLength + 6; ++j) {
			delete[] fields2[i][j];
		}
		delete fields2[i];
	}
	delete[] fields2;
}

void Game::redo() {

}

void Game::undo() {
	if (lastStage >= 1) {
		lastStage--;
		int tempPlayerChoices = 0;
		for (int j = 0; j < arrLength + 6; j++) {
			for (int k = 0; k < arrLength + 6; k++) {
				if (fields[lastStage][j][k].getIsPlayerHere()) {
					player.setOldX(player.getX()); player.setOldY(player.getY());
					player.setX(k); player.setY(j);
				}
				if (fields[lastStage][j][k].getAtomIsHereByPlayer()) {
					cout << fields[lastStage][j][k].getAtomIsHereByPlayer() << " is " << j << " " << k << endl;
					tempPlayerChoices++;
				}
				gameField[j][k] = fields[lastStage][j][k];
			}
		}
		counterOfChoices = tempPlayerChoices;
		presentStage--;
		console.drawMap(gameField, arrLength, isStarted, maxAtoms, counterOfCurrentChoices, showHelp);
	}
	else cout << "Undo cannot be performed\n";

}

void Game::start() {
	menu.showAuthor();
	char turn = '0';
	bool firstStart = true;
	while (turn != 'Z') {
		if (firstStart) {
			cout << "Write m for the game menu\n";
			arrLength = 5;
			startGame();
			firstStart = false;
		}

		cin.get(turn);

		if (isStarted == false) {
			if (turn > 48 && turn < 52) {
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
		}
		else if (turn != '\n' && isStarted) keySystem(int(turn));
	}
}

void Game::setDefault() {
	presentStage = 0;
	lastStage = 0;
	isStarted = true;
	isPaused = false;
	isQuit = false;
	counterOfChoices = 0;
	counterOfCurrentChoices = 0;
	shootCounter = 0;
	player = Player();
}

void Game::startGame() {
	setDefault();

	gameField = new Cell * [arrLength + 6];
	for (int i = 0; i < arrLength + 6; i++) {
		gameField[i] = new Cell[arrLength + 6];

		for (int j = 0; j < arrLength + 6; j++) {
			gameField[i][j].setX(j);
			gameField[i][j].setY(i);

			if ((i == 0 || i == arrLength + 5) || (j == 0 || j == arrLength + 5)) {
				gameField[i][j].setIsHitHere(true);
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
	}

	randomAtoms();

	fieldsSize = arrLength * 2;
	fields = new Cell * *[fieldsSize];
	for (int i = 0; i < fieldsSize; i++) {
		fields[i] = new Cell * [arrLength + 6];
		for (int j = 0; j < arrLength + 6; j++) {
			fields[i][j] = new Cell[arrLength + 6];
		}
	}
	writeFieldInFields();

	console.drawMap(gameField, arrLength, isStarted, maxAtoms, counterOfCurrentChoices, showHelp);

}

void Game::movement(int key) {
	int px = player.getX();
	int py = player.getY();
	player.setOldX(px); player.setOldY(py);

	switch (key) {
	case 87:
	case 119: if (py <= arrLength + 3 && py > 2) { player.setY(player.getY() - 1); } break; // W || w

	case 83:
	case 115: if (py < arrLength + 3 && py >= 2) { player.setY(player.getY() + 1); } break; // S || s

	case 65:
	case 97: if (px <= arrLength + 3 && px > 2) { player.setX(player.getX() - 1); } break; // A || a

	case 68:
	case 100: if (px < arrLength + 3 && px >= 2) { player.setX(player.getX() + 1); } break; // D || d
	}
	px = player.getX();
	py = player.getY();

	gameField[player.getOldY()][player.getOldX()].setIsPlayerHere(false);
	gameField[py][px].setIsPlayerHere(true);

	writeFieldInFields();

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

		if (key == 117 || key == 85) { // u | U
			undo();
		}
		else if (key == 114 || key == 82) { // r | R
			redo();
		}
		else if (key == 32) { // spacja
			shootSystem();
		}
		else if (key == 109) {// m
			menu.gameMenu();
		}
		else if (key == 111) { // o
			setAtomByPlayer();
		}
		else if (key == 72) { // H
			showHelp = true;
			console.drawMap(gameField, arrLength, isStarted, maxAtoms, counterOfCurrentChoices, showHelp);

			clock_t endwait;
			endwait = clock() + 1000;
			while (clock() < endwait) {
			}
			showHelp = false;
			cout << "\n\n\n\n\n\n\n\n\n\n\n\n";
			console.drawMap(gameField, arrLength, isStarted, maxAtoms, counterOfCurrentChoices, showHelp);
		}
		else if (key == 113 || key == 81) { // q | Q 
			isPaused = true;
			isQuit = true;
			endGame();
			menu.printMenu();
		}
		else if (key == 120) { // x
			counterOfChoices = maxAtoms;
			isRestart = true;
			endGame();
			startGame();
		}
		else if (key == 107 || key == 112) { // k || p
			if (key == 112) isPaused = true; // p
			endGame();
			if (counterOfChoices == maxAtoms) menu.printMenu();
		}

		else if (key == 90) {}//Z
		else {
			cout << "Wrong symbol" << endl;
		}
	}
}

void Game::setAtomByPlayer() {
	int px = player.getX();
	int py = player.getY();
	if (gameField[py][px].getIsBorderHere() == false) {
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
	else cout << "You can't put a mark here, because it's a wall\n";
}

void Game::scanPlace(int x, int y) {
	int neighborSize = 3;
	int startRow = x - 1;
	int startCol = y - 1;

	for (int i = 0; i < neighborSize; ++i) {
		for (int j = 0; j < neighborSize; ++j) {
			int newRow = startRow + i;
			int newCol = startCol + j;
			if (newRow >= 0 && newRow < (arrLength + 3) && newCol >= 0 && newCol < (arrLength + 3)) {
				gameField[newRow][newCol].setIsAtomArea(true);
				gameField[newRow][newCol].setCounterOfAtomsArea(gameField[newRow][newCol].getCounterOfAtomsArea() + 1);
			}
		}
	}
}

void Game::randomAtoms() {
	srand(time(NULL));
	int rand1 = rand() % arrLength + 3, rand2 = rand() % arrLength + 3;

	switch (arrLength)
	{
	case 5: maxAtoms = 3; break;
	case 8: maxAtoms = 5; break;
	case 10: maxAtoms = 8; break;
	default: break;
	}

	for (int i = 0; i < maxAtoms; i++) {
		if (gameField[rand1][rand2].getAtomHere() == false) {
			gameField[rand1][rand2].setAtomHere(true);
			scanPlace(rand1, rand2);
		}
		else {
			while (gameField[rand1][rand2].getAtomHere() == true) {
				rand1 = rand() % arrLength + 3;
				rand2 = rand() % arrLength + 3;
			}
			gameField[rand1][rand2].setAtomHere(true);
			scanPlace(rand1, rand2);

		}
	}
}

void Game::endGame() {
	if ((counterOfChoices == maxAtoms) || isPaused) {
		isStarted = false;
		if (!isQuit)	console.drawMap(gameField, arrLength, isStarted, maxAtoms, counterOfCurrentChoices, showHelp);
		for (int i = 0; i < arrLength + 6; ++i) {
			delete[] gameField[i];
		}
		delete[] gameField;

		for (int i = 0; i < fieldsSize; i++) {
			for (int j = 0; j < arrLength + 6; ++j) {
				delete[] fields[i][j];
			}
			delete[] fields[i];
		}
		delete[] fields;
	}
	else {
		cout << "You have " << maxAtoms - counterOfChoices << " more choice(s)\n";
	}

}