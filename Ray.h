#pragma once
class Ray {
private:
	int x, y;
	int oldX, oldY;

	bool isRefracted = false; //zalamany czy nie
	int counterOfRefraction = 0;
public:

	void setX(int);
	void setY(int);
	int getX();
	int getY();

	void setOldX(int);
	void setOldY(int);
	int getOldX();
	int getOldY(); 
	
	void setIsRefracted(bool);
	bool getIsRefracted();

	void increaseCounterOfRefraction();
	int getCounterOfRefraction();

};