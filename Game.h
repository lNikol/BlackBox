#pragma once
#include "Menu.h"
#include "Player.h"
#include "Console.h"
#include "Cell.h"
class Game {
	private:
		bool isStarted = false;
		Cell** gameField;
	public:
		int arrLength;
		Menu menu;
		Player player;
		Console console;

		void movement(int);
		void movementSystem(int);
		void shootSystem();
		void render();
		void start();
		void startGame();
		void endGame();
		Cell** getGameField();
};