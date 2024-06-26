﻿#pragma once
#include "Main.h"

class Ray : public Main {
private:
	int oldX, oldY;
	bool isRefracted = false; //zalamany czy nie
	bool isHit = false;
	int counterOfRefraction = 0;
	unsigned char startDirection = ' ';
	unsigned char direction = ' '; // w - do gory, s - do dolu, d - w prawo, a - w lewo
public:
	Ray(int fx = 0, int fy = 0, int fOldX = 0, int fOldY = 0) : Main(fx, fy), oldX(fOldX), oldY(fOldY) {};

	void setOldX(int);
	int getOldX();

	void setOldY(int);
	int getOldY();
	
	void setDirection(unsigned char);
	char getDirection();

	void setStartDirection(unsigned char);
	char getStartDirection();

	void setIsRefracted(bool);
	bool getIsRefracted();

	void setIsHit(bool);
	bool getIsHit();

	void increaseCounterOfRefraction();
	int getCounterOfRefraction();
};