#pragma once
#include "Menu.h"
#include "Player.h"
#include "Console.h"
#include "Cell.h"

class Game {
private:
	int counterOfCurrentChoices = 0; // ilosc poprawnie wyznaczonych atomow
	int counterOfChoices = 0; // ilosc wyznaczonych atomow
	int shootCounter = 0;
	int maxAtoms;

	int presentStage = 0;
	int lastStage = 0;

	bool showHelp = false;

	bool isStarted = false;
	bool isPaused = false;
	bool isQuit = false;
	bool isRestart = false;
	
	Cell** gameField;
	int fieldsSize;
	Cell*** fields;
public:
	// arrLength - size of map 5x5, 7x7, 10x10
	int arrLength = 5;
	Menu menu;
	Player player;
	Console console;

	void start();
	void startGame();
	void endGame();

	void setDefault();

	void randomAtoms();
	void scanPlace(int, int);
	void setAtomByPlayer();
	void shootSystem();
	void setShootingInfo(int, int);

	void keySystem(int);
	void movement(int);

	Cell** getGameField();
	Cell*** getFields();

	void writeFieldInFields();
	void increaseFieldsSize();
	void setOldField(); 

	void undo();
	void redo();
};