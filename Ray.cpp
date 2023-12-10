#include "Ray.h"

void Ray::setOldX(int oldXt) { oldX = oldXt; }
int Ray::getOldX() { return oldX; }

void Ray::setOldY(int oldYt) { oldY = oldYt; }
int Ray::getOldY() { return oldY; }

void Ray::setDirection(unsigned char d) { direction = d; }
char Ray::getDirection() { return direction; }

void Ray::setStartDirection(unsigned char d) { startDirection = d; }
char Ray::getStartDirection() { return startDirection; }

void Ray::setIsHit(bool s) { isHit = s; }
bool Ray::getIsHit() { return isHit; }

void Ray::setIsRefracted(bool fref) { isRefracted = fref; }
bool Ray::getIsRefracted() { return isRefracted; }

void Ray::increaseCounterOfRefraction() { counterOfRefraction++; }
int Ray::getCounterOfRefraction() { return counterOfRefraction; }
