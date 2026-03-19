#pragma once
#include "Globals.h"
#include "GameObject.h"
#include "Animation.h"
#include "SlimePiece.h"
#include "Orb.h"


class Player : public GameObject
{
private :
	float speed = 300.f;
	float dash = 300.0f;
	float dashCooldown = 3.0f;
	float dashTimer = 0.0f;
	bool canDash = true;
	float gravity = 980.f;
	bool isDashing = false;
	float dashProgress = 0.0f;
	float dashStartX = 0.0f;
	float dashTargetX = 0.0f;
	float dashTotalTime = 0.5f;
	

	float jumpForce = -800.f;
	float velocityX = 0.f;
	float velocityY = 0.f;

	Animation* myAnimation;

	float weightLoss = 0.3; 

	enum class SlimeStates {
		micro,
		light,
		normal,
		heavy,
	};

	SlimeStates currentStates;

public:
	std::vector<SlimePiece*> slimePieceLeave;
	std::vector<SlimePiece*> slimePiece;
	int seedNb = 0;
	int orbNb = 0;

	float spawnX = 0.f;
	float spawnY = 0.f;

	bool canDoubleJump = false;
	bool canDivision = false;

public :
	bool onGround = false;
	float Cooldown;
	Player() = default;
	Player(float x, float y);
	~Player() = default;

	void clampInScreen();
	void jump();

	void skillsLeaveSlime(Input& input);
	void takeSlime(Input& input);
	void collectSeed();
	int getSeedNb();

	void collectOrb();

	void respawn();

	void applyWind(float windForce, float dt);


	void setAnimation(Animation* myAnimation);

	virtual void render(sf::RenderWindow* window) override;
	virtual void update(float& dt, Input& input) override;
	virtual void resolveCollision(GameObject& gameObject) override;
};


