#pragma once

class Player {
private:
	int x, y;
	int oldX, oldY;

public:
	Player();
	void setX(int);
	void setY(int);
	void setOldX(int);
	void setOldY(int);
	void moveX(int);
	void moveY(int);

	int getX();
	int getY();
	int getOldX();
	int getOldY();
};