#pragma once

class Player {
private:
	int x, y;

public:
	Player();
	void setX(int);
	void setY(int);
	void moveX(int);
	void moveY(int);

	int getX();
	int getY();
};