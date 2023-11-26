#pragma once
#include "Menu.h"
#include "Player.h"

class Game {
	private:
		int arr[4];
		bool** gameField;
		int** gameCoords;

	public:
		int arrLength;
		Game(int);
		Menu menu;
		Player player;
		void movement(int, Game&);
		void movementSystem(int, Game&);
		void render(Game&);
};