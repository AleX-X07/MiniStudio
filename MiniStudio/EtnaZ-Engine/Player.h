#pragma once
#include "GameState.h"
#include "Globals.h"
#include "GameObject.h"

class Player : public GameObject
{
private:
	float speed = 300.f;
	float jumpForce = -500.f;
	float gravity = 980.f;
	float velocityX = 0.f;
	float velocityY = 0.f;

	bool onGround = false;

public :
	Player() = default;
	Player(float x, float y);
	~Player() = default;

	void clampInScreen();
	void setFillColor(Color color);
	void setSize(Vector2f size);
	void setPosition(Vector2f pos);

	virtual void render(RenderWindow* window) override;
	virtual void update(float& dt, Input& input) override;
	virtual void resolveCollision(GameObject& gameObject) override;
	void moveLeft(float& dt);
	void moveRight(float& dt);
	void jump();
};

