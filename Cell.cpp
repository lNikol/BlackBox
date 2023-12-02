#include "Cell.h"


void Cell::setAtom(bool isAtom) {
	isAtomHere = isAtom;
};
void Cell::setPlayer(bool fisPlayerHere) {
	isPlayerHere = fisPlayerHere;
}
void Cell::setX(int fx) { x = fx; };
void Cell::setY(int fy) { y = fy; };



void Cell::setAnswerHere(unsigned char ans) { answerHere = ans; }
void Cell::setIsAnswerHere(bool isAns) { isAnswerHere = isAns; }

char Cell::getAnswerHere() { return answerHere; }
bool Cell::getIsAnswerHere() { return isAnswerHere; }

int Cell::getX() { return x; };
int Cell::getY() { return y; };


bool Cell::getIsBorderHere() { return isBorderHere; };
char Cell::getBorderHere() { return borderHere; };

void Cell::setIsBorderHere(bool border) { isBorderHere = border; };
void Cell::setBorderHere(unsigned char border) { borderHere = border; };
bool Cell::getPlayerHere() { return isPlayerHere; };
