#include "Player.h"
#include "GameEngine.h"

Player::Player()
{
	speed = 300.0f;
	position = Vector2f(0.f, 0.f);
}

void Player::setFillColor(Color color)
{
	shape.setFillColor(color);
}

void Player::setSize(Vector2f size)
{
	shape.setSize(size);
}

void Player::setPosition(Vector2f pos)
{
	position = pos;
	shape.setPosition(pos);
}

void Player::render(RenderWindow* window)
{
	if (window) {
		window->draw(shape);
	}
}

void Player::update(float& dt) {
	if (Keyboard::isKeyPressed(Keyboard::Key::Left)) {
		position.x -= speed * dt;
		shape.setPosition(position);
	}
	if (Keyboard::isKeyPressed(Keyboard::Key::Right)) {
		position.x += speed * dt;
		shape.setPosition(position);
	}
}