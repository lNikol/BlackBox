#include <iostream>
#include "Game.h"
using namespace std;

Game::Game(int length):arr{ 1,2,3,4 } {
	arrLength = length;
	gameField = new bool* [arrLength + 2];
	for (int i = 0; i < arrLength + 2; i++) {
		gameField[i] = new bool[arrLength + 2];
	}
	gameCoords = new int* [arrLength + 2];
	for (int i = 0; i < arrLength + 2; i++) {
		gameCoords[i] = new int[arrLength + 2];
	}
}
/*
void Game::shootSystem(int maxLength, Game& game) {
	if (game.player.getX() == 0 && game.player.getY() == 0) cout << "lewy_dol\n";
	else if (game.player.getX() == (maxLength + 2) && game.player.getY() == 0) cout << "prawy_dolny\n";
	else if (game.player.getX() == 0 && game.player.getY() == (maxLength + 2)) cout << "lew_gor\n";
	else if (game.player.getX() == (maxLength + 2) && game.player.getY() == (maxLength + 2)) cout << "prawy_gor\n";
}
*/

void Game::movement(int key, Game& game) {
	switch (key) {
	case 87: game.player.setY(game.player.getY() + 1);
	case 83: game.player.setY(game.player.getY() - 1);
	case 65: game.player.setX(game.player.getX() - 1);
	case 68: game.player.setX(game.player.getX() + 1);

	}
}

void Game::movementSystem(int key, Game& game) {
	//game.arrLength - size of map 5x5, 7x7, 10x10
	int px = game.player.getX();
	int py = game.player.getY();


	// game.arrLength + 1 (np. 5+1=6) bo, 1,2,3,4,5 - pole gry, 0 i 6 to krancy karty

	switch (key) {
	case 87: if (py < game.arrLength + 1 && py >= 0) { game.player.setY(game.player.getY() + 1); } break; //w
	case 83: if (py <= game.arrLength + 1 && py > 0) { game.player.setY(game.player.getY() - 1); } break; //s
	case 65: if (px <= game.arrLength + 1 && px > 0) { game.player.setX(game.player.getX() - 1); } break; //a
	case 68: if (px < game.arrLength + 1 && px >= 0) { game.player.setX(game.player.getX() + 1); } break; //d


	default: break;

	}
}

void Game::render(Game& game) {

}