/*
Nikolai Lavrinov
201302
ACiR4
Black Box
*/


#include <iostream>
#include "Console.h"
#include "Game.h"
using namespace std;


int main()
{
	int arrLength = 0;
	Console console;
	console.showAuthor();
	console.drawTopBorder(8);
	console.drawBorderContent(8);
	console.drawBottomBorder(8);
	Game game (arrLength);
	game.menu.printMenu();
}
