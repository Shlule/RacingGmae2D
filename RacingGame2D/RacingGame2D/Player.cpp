#include "Player.h"

Player::Player(float widthP, float heightP, Vector2 posP) : width{ widthP }, height{ heightP }, pos{ posP } {
	collisionBox = Rectangle{ pos.x, pos.y, width, height };
	center = { pos.x + width / 2, pos.y };
}
void Player::setSpeed(Vector2 speedP) {
	speed = speedP;
}
void Player::setPos(Vector2 posP) {
	pos = posP;
}

void Player::draw() {
	DrawRectangle(pos.x, pos.y, width, height, WHITE);
}

void Player::update() {

	pos.x += speed.x;
	pos.y += speed.y;
	collisionBox.x = pos.x;
	collisionBox.y = pos.y;
	center.x += speed.x;
	center.y += speed.y;
}

void Player::reverseSpeed(int CaseP) {

	switch (CaseP) {
	case 1:
		speed.x = -speed.x;
		break;

	case 2:
		speed.y = -speed.y;
		break;
	}

}
