#pragma once
class Cell {
private:
	int x = 0, y = 0;
	bool isAtomHere = false;
	bool isPlayerHere = false;
	bool isBorderHere = false;
	unsigned char borderHere;
	bool isAnswerHere = false;
	unsigned char answerHere;
	bool isSpaceHere = false;
public:
	void setAtom(bool);

	void setIsPlayerHere(bool);
	bool getIsPlayerHere();

	void setBorderHere(unsigned char);
	char getBorderHere();

	void setIsBorderHere(bool);
	bool getIsBorderHere();

	void setX(int);
	void setY(int);
	int getX();
	int getY();

	void setAnswerHere(unsigned char);
	void setIsAnswerHere(bool);
	bool getIsAnswerHere();
	char getAnswerHere();

	void setIsSpaceHere(bool);
	bool getIsSpaceHere();

};