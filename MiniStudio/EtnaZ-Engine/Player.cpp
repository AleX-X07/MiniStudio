#include "Player.h"

Player::Player(float x, float y) : GameObject(x,y)
{
	speed = 300.0f;
}

void Player::clampInScreen() {
	pos.x = std::max(0.f, std::min(pos.x, (float)(level_size_width - size.x)));
	pos.y = std::max(0.f, std::min(pos.y, (float)(level_size_heigt - size.y)));
	setPos(pos);
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
	clampInScreen();
	setPos(pos);
}