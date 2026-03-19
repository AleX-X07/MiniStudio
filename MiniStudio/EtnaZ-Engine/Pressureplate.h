#pragma once
#include "GameObject.h"
#include "Door.h"

class Pressureplate : public GameObject
{

private:
	bool activated;

	// massThreshold


public:	
	Pressureplate(float x, float y, float w, float h);
	~Pressureplate();

	bool isActivated();
	void activate();

	void render(RenderWindow* window) override;

};

