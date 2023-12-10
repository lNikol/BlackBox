#pragma once
#include "Main.h"
class Player : public Main {
private:
	int oldX, oldY;
public:
	Player(int fx = 3, int fy = 3, int fOldX = 3, int fOldY = 3): Main(fx,fy), oldX(fOldX), oldY(fOldY) {};
	
	void setOldX(int);
	int getOldX();

	void setOldY(int);
	int getOldY();
	
	void moveX(int);
	void moveY(int);
};