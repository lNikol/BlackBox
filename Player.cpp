#include <iostream>
#include "Player.h"
using namespace std;

Player::Player() {
		x = 0;
		y = 0;
}
void Player::setX(int xt) { x = xt; }
void Player::setY(int yt) { y = yt; }

void Player::moveX(int xt) { x += xt; }
void Player::moveY(int yt) { y += yt; }


int Player::getX() { return x; }
int Player::getY() { return y; }


