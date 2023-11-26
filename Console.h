#pragma once
#include "Game.h"
class Console {
	public:
		void showAuthor();
		void drawTopBorder(int);
		void drawBorderContent(int);
		void drawBottomBorder(int);
		void showPlayer(Game&);
};