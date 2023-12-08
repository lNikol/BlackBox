#pragma once
#include "Menu.h"
#include "Player.h"
#include "Console.h"
#include "Cell.h"

class Game {
private:
	int counterOfCurrentChoices = 0; // ilosc poprawnie wyznaczonych atomow
	int counterOfChoices = 0;
	int maxAtoms;
	bool isStarted = false;
	bool showHelp = false;
	Cell** gameField;
public:
	int arrLength = 5; // default information
	Menu menu;
	Player player;
	Console console;


	void randomAtoms();
	void movement(int);
	void keySystem(int);
	void shootSystem();
	void render();
	void setAtomByPlayer();
	void start();
	void startGame();
	void endGame();
	Cell** getGameField();
};