#pragma once
#include "GameObject.h"

class Orb : public GameObject
{
private:

	bool collected;

public:

	Orb(float x, float y, float w, float h);

	bool isCollected();
	void collect();

	void render(RenderWindow* window) override;


};

