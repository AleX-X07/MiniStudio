#pragma once
#include "GameObject.h"



class Crate : public GameObject
{
private:
	float gravity = 980.f;

public:
	float velocityX = 0.f;
	float velocityY = 0.f;
	bool  onGround = false;

public:
	Crate(float x, float y, float w, float h);
	~Crate();

	void update(float& dt, Input& input) override;

	void push(float directionX, float force);

	void resolveCollision(GameObject& gameObject) override;

	void render(sf::RenderWindow* window) override;


};

