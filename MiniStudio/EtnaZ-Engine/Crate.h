#pragma once
#include "GameObject.h"



class Crate : public GameObject
{
private:
	float velocityX = 0.f;
	float velocityY = 0.f;
	float gravity = 980.f;
	bool  onGround = false;

	// condition to push massThreshold

public:
	Crate(float x, float y, float w, float h);
	~Crate();

	void update(float& dt, Input& input) override;

	// can push

	void render(sf::RenderWindow* window) override;
	

};

