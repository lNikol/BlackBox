#pragma once
#include "Cell.h"
class Console {
	public:
		void drawMap(Cell**, int, bool, int, int&, bool);
		void showPlayer(int, int, int);
		void showSymbol(int, int, char);
};