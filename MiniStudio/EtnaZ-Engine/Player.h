#pragma once
#include "GameState.h"
class Player
{
private :

public :
	RectangleShape shape;
	Vector2f position;

	float speed = 300.f;
	float jumpForce = -500.f;
	float gravity = 980.f;
	float velocityX = 0.f;
	float velocityY = 0.f;

	bool onGround = false;

	Player();
	~Player() = default;

	void setFillColor(Color color);
	void setSize(Vector2f size);
	void setPosition(Vector2f pos);

	void render(RenderWindow* window);
	void update(float& dt);
	void moveLeft(float& dt);
	void moveRight(float& dt);
	void jump();
};

