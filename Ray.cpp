#include "Ray.h"

void Ray::setOldX(int oldXt) { oldX = oldXt; }
int Ray::getOldX() { return oldX; }

void Ray::setOldY(int oldYt) { oldY = oldYt; }
int Ray::getOldY() { return oldY; }

void Ray::setDirection(char d) { direction = d; }
char Ray::getDirection() { return direction; }

void Ray::setIsHit(bool s) { isHit = s; }
bool Ray::getIsHit() { return isHit; }

void Ray::setIsRefracted(bool fref) { isRefracted = fref; }
bool Ray::getIsRefracted() { return isRefracted; }

void Ray::increaseCounterOfRefraction() { counterOfRefraction++; }
int Ray::getCounterOfRefraction() { return counterOfRefraction; }