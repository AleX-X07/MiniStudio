#pragma once
#include "Globals.h"
#include "GameObject.h"
#include "Animation.h"
#include "SlimePiece.h"

class Player : public GameObject
{
private :
	float speed = 300.f;
	float jumpForce = -500.f; 
	float gravity = 980.f;
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
	std::vector<SlimePiece*> slimePiece;

public :
	bool onGround = false;

	Player() = default;
	Player(float x, float y);
	~Player() = default;

	void clampInScreen();
	void jump();

	void skillsLeaveSlime(Input& input);
	void takeSlime(Input& input);

	void setAnimation(Animation* myAnimation);

	virtual void render(RenderWindow* window) override;
	virtual void update(float& dt, Input& input) override;
	virtual void resolveCollision(GameObject& gameObject) override;
};

