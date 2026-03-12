#pragma once
#include "Globals.h"
#include "GameObject.h"


class Player : public GameObject
{
private :
	float speed;

public :
	Player() = default;
	Player(float x, float y);
	~Player() = default;

	void clampInScreen();

	virtual void render(RenderWindow* window) override;
	virtual void update(float& dt, Input& input) override;
};

