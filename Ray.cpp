#include "Ray.h"

void Ray::setX(int xt) { x = xt; }
void Ray::setY(int yt) { y = yt; }

int Ray::getX() { return x; }
int Ray::getY() { return y; }


void Ray::setOldX(int oldXt) { oldX = oldXt; }
void Ray::setOldY(int oldYt) { oldY = oldYt; }

int Ray::getOldX() { return oldX; }
int Ray::getOldY() { return oldY; }



void Ray::setIsRefracted(bool fref) { isRefracted = fref; }
bool Ray::getIsRefracted() { return isRefracted; }

void Ray::increaseCounterOfRefraction() { counterOfRefraction++; }
int Ray::getCounterOfRefraction() { return counterOfRefraction; }