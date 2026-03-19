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
	float jumpForce = -900;
	float gravity = 980.f;
	float velocityX = 0.f;
	float velocityY = 0.f;

	Animation* myAnimation;

	float weightLoss = 0.3; 

	int nbrDepotSlime;

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

	int seedNb = 0;
	int orbNb = 0;

	float spawnX = 0.f;
	float spawnY = 0.f;

	bool canDash = false;
	bool canDoubleJump = false;

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


