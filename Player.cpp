#include "Player.h"
using namespace std;

void Player::setOldX(int oldXt) { oldX = oldXt; }
int Player::getOldX() { return oldX; }

void Player::setOldY(int oldYt) { oldY = oldYt; }
int Player::getOldY() { return oldY; }

void Player::moveX(int xt) { setX(getX() + xt); }
void Player::moveY(int yt) { setY(getY() + yt); }
