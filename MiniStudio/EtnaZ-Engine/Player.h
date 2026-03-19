#pragma once
#include "Globals.h"
#include "GameObject.h"
#include "Animation.h"
#include "Orb.h"
using namespace std;


class Player : public GameObject
{
private :
	float speed = 300.f;
	float jumpForce = -800.f;
	float gravity = 980.f;
	float velocityX = 0.f;
	float velocityY = 0.f;

	int seedNb = 0;
	int orbNb = 0;

	float spawnX = 0.f;
	float spawnY = 0.f;

	bool canDash = false;
	bool canDoubleJump = false;
	bool canDivision = false;

	Animation* myAnimation;	

public :
	bool onGround = false;

	Player() = default;
	Player(float x, float y);
	~Player() = default;

	void clampInScreen();
	void jump();

	void collectSeed();
	int getSeedNb();

	void collectOrb();

	void respawn();

	void applyWind(float windForce, float dt);


	void setAnimation(Animation* myAnimation);

	virtual void render(RenderWindow* window) override;
	virtual void update(float& dt, Input& input) override;
	virtual void resolveCollision(GameObject& gameObject) override;
};


