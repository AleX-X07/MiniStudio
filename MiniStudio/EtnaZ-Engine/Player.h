#pragma once
#include "Globals.h"
#include "GameObject.h"
#include "Animation.h"

class Player : public GameObject
{
private :
	float speed = 300.f;
	float jumpForce = -500.f; 
	float gravity = 980.f;
	float velocityX = 0.f;
	float velocityY = 0.f;

	float health = 100.f;

	Animation* myAnimation;	

public :
	bool onGround = false;

	Player() = default;
	Player(float x, float y);
	~Player() = default;

	void clampInScreen();
	void jump();


	void setAnimation(Animation* myAnimation);

	virtual void render(RenderWindow* window) override;
	virtual void update(float& dt, Input& input) override;
	virtual void resolveCollision(GameObject& gameObject) override;
};

