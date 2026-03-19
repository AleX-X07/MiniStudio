#pragma once
#include "GameObject.h"


class Ventilation : public GameObject
{
	private:

		float windForce = 500.f;

		// massThreshold

	public:
		Ventilation(float x, float y, float w, float h);
		~Ventilation();

		float getWindForce();
		// get massThreshold
		
		void render(RenderWindow* window) override;

		


};

