#include "Cell.h"

void Cell::setAtomHere(bool isAtom) {
	isAtomHere = isAtom;
};
bool Cell::getAtomHere() { return isAtomHere; }

void Cell::setAtomIsHereByPlayer(bool isAtom) {
	atomIsHereByPlayer = isAtom;
};
bool Cell::getAtomIsHereByPlayer() { return atomIsHereByPlayer; }


void Cell::setIsPlayerHere(bool fisPlayerHere) {
	isPlayerHere = fisPlayerHere;
}
bool Cell::getIsPlayerHere() { return isPlayerHere; };

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


void Cell::setIsSpaceHere(bool space) { isSpaceHere = space; };
bool Cell::getIsSpaceHere() { return isSpaceHere; };