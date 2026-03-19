#pragma once
#include "GameObject.h"


class Seed : public GameObject
{
	private:

		bool collected;

public:

	Seed(float x, float y, float w, float h);
	~Seed();


	bool isCollected();
	void collect();

	void render(RenderWindow* window) override;

};

