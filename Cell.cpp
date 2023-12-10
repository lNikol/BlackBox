#include "Cell.h"

void Cell::setAtomHere(bool isAtom) { isAtomHere = isAtom; }
bool Cell::getAtomHere() { return isAtomHere; }

void Cell::setAtomIsHereByPlayer(bool isAtom) { atomIsHereByPlayer = isAtom; }
bool Cell::getAtomIsHereByPlayer() { return atomIsHereByPlayer; }

void Cell::setIsPlayerHere(bool fisPlayerHere) { isPlayerHere = fisPlayerHere; }
bool Cell::getIsPlayerHere() { return isPlayerHere; }

void Cell::setIsBorderHere(bool border) { isBorderHere = border; }
bool Cell::getIsBorderHere() { return isBorderHere; }

void Cell::setBorderHere(unsigned char border) { borderHere = border; }
char Cell::getBorderHere() { return borderHere; }

void Cell::setNumberOfHitHere1(unsigned char ans) { numberOfHitHere1 = ans; }
char Cell::getNumberOfHitHere1() { return numberOfHitHere1; }

void Cell::setNumberOfHitHere2(unsigned char ans) { numberOfHitHere2 = ans; }
char Cell::getNumberOfHitHere2() { return numberOfHitHere2; }

void Cell::setHitHere(unsigned char ans) { hitHere = ans; }
char Cell::getHitHere() { return hitHere; }

void Cell::setIsHitHere(bool isAns) { isHitHere = isAns; }
bool Cell::getIsHitHere() { return isHitHere; }

void Cell::setIsSpaceHere(bool space) { isSpaceHere = space; }
bool Cell::getIsSpaceHere() { return isSpaceHere; }

void Cell::setCounterOfAtomsArea(int c) { counterOfAtomsArea = c; }
int Cell::getCounterOfAtomsArea() { return counterOfAtomsArea; }

void Cell::setIsAtomArea(bool a) { isAtomArea = a; }
bool Cell::getIsAtomArea() { return isAtomArea; }

void Cell::setIsRayHere(bool r) { isRayHere = r; }
bool Cell::getIsRayHere() { return isRayHere; }