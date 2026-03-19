#pragma once
#include "GameObject.h"


class Ventilation : public GameObject
{
	private:

		float windForce = 500.f;


	public:
		Ventilation(float x, float y, float w, float h);
		~Ventilation();

		float getWindForce();
		
		void render(sf::RenderWindow* window);

		


};

