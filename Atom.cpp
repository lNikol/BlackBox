#include "Atom.h"

void Atom::setX(int xt) { x = xt; }
void Atom::setY(int yt) { y = yt; }

int Atom::getX() { return x; }
int Atom::getY() { return y; }


void Atom::setIsShowed(bool fshow) { isShowed = fshow; }
bool Atom::getIsShowed() { return isShowed; }