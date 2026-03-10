#include "Player.h"

Player::Player(float x, float y) : GameObject(x,y)
{
	speed = 300.0f;
}

void Player::render(RenderWindow* window)
{
	if (window) {
		window->draw(rect);
	}
}

void Player::update(float& dt, Input& input) {
	if (Keyboard::isKeyPressed(Keyboard::Key::Left)) {
		pos.x -= speed * dt;
	}
	if (Keyboard::isKeyPressed(Keyboard::Key::Right)) {
		pos.x += speed * dt;
	}
	setPos(pos);
}