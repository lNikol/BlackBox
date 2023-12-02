#include <iostream>
#include "Player.h"
using namespace std;

Player::Player() {
		x = 2;
		y = 2;
		oldX = 2;
		oldY = 2;
}
void Player::setX(int xt) { x = xt; }
void Player::setY(int yt) { y = yt; }
void Player::setOldX(int oldXt) { oldX = oldXt; }
void Player::setOldY(int oldYt) { oldY = oldYt; }

void Player::moveX(int xt) { x += xt; }
void Player::moveY(int yt) { y += yt; }


int Player::getX() { return x; }
int Player::getY() { return y; }


int Player::getOldX() { return oldX; }
int Player::getOldY() { return oldY; }

