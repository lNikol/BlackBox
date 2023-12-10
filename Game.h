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
	bool isStarted = false;
	bool showHelp = false;
	bool isPaused = false;
	bool isQuit = false;
	bool isRestart = false;
	Cell** gameField;
	int fieldsSize;
	Cell*** fields;
public:
	int arrLength = 5;
	Menu menu;
	Player player;
	Console console;
	
	void randomAtoms();
	void movement(int);
	void keySystem(int);
	void shootSystem();
	void setAtomByPlayer();

	void setDefault();

	void start();
	void startGame();
	void endGame();
	Cell** getGameField();
	Cell*** getFields();
	void writeFieldInFields();
	void increaseFieldsSize();
	void undo();
	void redo();

	void setShootingInfo(int, int);

	void scanPlace(int, int);
	void setOldField();
};