#pragma once
#include "Player.h"
#include "Cell.h"
class Console {
	public:
		void drawMap(Cell**, int);
		void drawTopBorder(int);
		void drawBorderContent(int);
		void drawBottomBorder(int);
		void showPlayer(Player&);
};