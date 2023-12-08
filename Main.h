#pragma once
class Main {
private:
	int x, y;
public:
	Main(int fx, int fy) :x(fx), y(fy) {};
	void setX(int);
	void setY(int);
	int getX();
	int getY();
};