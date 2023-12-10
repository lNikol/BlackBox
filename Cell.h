#pragma once
#include "Main.h"
class Cell : public Main {
private:
	bool isAtomHere = false;
	bool atomIsHereByPlayer = false;
	char atomHereByPlayer = 'o';

	int counterOfAtomsArea = 0;
	bool isAtomArea = false;
	bool isRayHere = false;

	bool isPlayerHere = false;
	bool isBorderHere = false;
	unsigned char borderHere;

	bool isHitHere = false;
	bool isNumberHere = false;
	unsigned char hitHere = ' ';
	unsigned char numberOfHitHere1 = ' ';
	unsigned char numberOfHitHere2 = ' ';

	bool isSpaceHere = false;
public:
	Cell(int fx = 0, int fy = 0) :Main(fx, fy) {};
	
	void setAtomHere(bool);
	bool getAtomHere();

	void setAtomIsHereByPlayer(bool);
	bool getAtomIsHereByPlayer();

	void setIsPlayerHere(bool);
	bool getIsPlayerHere();

	void setIsBorderHere(bool);
	bool getIsBorderHere();

	void setBorderHere(unsigned char);
	char getBorderHere();

	void setNumberOfHitHere1(unsigned char);
	char getNumberOfHitHere1();
	
	void setNumberOfHitHere2(unsigned char);
	char getNumberOfHitHere2();


	void setHitHere(unsigned char);
	char getHitHere();

	void setIsHitHere(bool);
	bool getIsHitHere();

	void setIsSpaceHere(bool);
	bool getIsSpaceHere();

	void setCounterOfAtomsArea(int);
	int getCounterOfAtomsArea();

	void setIsAtomArea(bool);
	bool getIsAtomArea();

	void setIsRayHere(bool);
	bool getIsRayHere();
};