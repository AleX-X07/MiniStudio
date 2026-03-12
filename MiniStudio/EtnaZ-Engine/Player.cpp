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
	if (window) 
    {
		window->draw(shape);
	}
}

void Player::update(float& dt)
{
    if (Keyboard::isKeyPressed(Keyboard::Key::Left))
    {
        position.x -= speed * dt;
        shape.setPosition(position);
    }
    if (Keyboard::isKeyPressed(Keyboard::Key::Right))
    {
        position.x += speed * dt;
        shape.setPosition(position);
    }
    if (Keyboard::isKeyPressed(Keyboard::Key::Up))
    {
        jump();
		shape.setPosition(position);
	}
    if (!onGround)
    {
        velocityY += gravity * dt;
        if (velocityY > 600.0f) velocityY = 600.0f;

        position.y += velocityY * dt;
        position.x += velocityX * dt;
        velocityX = 0;
        shape.setPosition(position);
    }
}

void Player::moveLeft(float& dt) 
{
	velocityX = -speed;
}

void Player::moveRight(float& dt) 
{
	velocityX = speed;
}

void Player::jump() 
{
	if (onGround) 
	{
		velocityY = jumpForce;
		onGround = false;
	}
}