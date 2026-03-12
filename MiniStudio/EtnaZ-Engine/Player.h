#pragma once
#include "Globals.h"
#include "GameObject.h"
#include "Animation.h"

class Player : public GameObject
{
private :
	float speed;
	Animation* myAnimation;

public :
	Player() = default;
	Player(float x, float y);
	~Player() = default;

	void clampInScreen();

	void setAnimation(Animation* myAnimation);

	virtual void render(RenderWindow* window) override;
	virtual void update(float& dt, Input& input) override;
};

