#pragma once
#include "GameObject.h"


class Spike : public GameObject
{

public:	
	Spike(float x, float y, float w, float h);
	~Spike();

	void render(sf::RenderWindow* window) override;


};

