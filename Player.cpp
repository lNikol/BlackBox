#include <iostream>
#include "Player.h"
using namespace std;


void Player::setOldX(int oldXt) { oldX = oldXt; }
void Player::setOldY(int oldYt) { oldY = oldYt; }

int Player::getOldX() { return oldX; }
int Player::getOldY() { return oldY; }


void Player::moveX(int xt) { setX(getX() + xt); }
void Player::moveY(int yt) { setY(getY() + yt); }
