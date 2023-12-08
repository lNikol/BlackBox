#pragma once

class Atom {
private:
	int x, y;
	bool isShowed = false;
public:

	void setX(int);
	void setY(int);
	int getX();
	int getY();

	void setIsShowed(bool);
	bool getIsShowed();

};