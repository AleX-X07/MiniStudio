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


public:
	bool runBool;
	enum class SlimeStates {
		light,
		normal,
		heavy,
		death,
	};

	std::vector<SlimePiece*> slimePieceLeave;
	std::vector<SlimePiece*> slimePiece;
	SlimeStates currentStates;

public :
	bool onGround = false;

	Player() = default;
	Player(float x, float y, float w, float h);
	~Player() = default;

	void clampInScreen();
	void jump();
	void run();
	void takeDamage();

	void skillsLeaveSlime(Input& input);
	void takeSlime(Input& input);

	void setAnimation(Animation* myAnimation);

	virtual void render(sf::RenderWindow* window) override;
	virtual void update(float& dt, Input& input) override;
	virtual void resolveCollision(GameObject& gameObject) override;
};

