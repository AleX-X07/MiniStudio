#pragma once
#include "Globals.h"
#include "GameObject.h"

class Camera
{
private:
	sf::View myView;
	sf::Vector2f pos;
	sf::Vector2f center;
	sf::Vector2f targetPos;
	float lag;

public:
	Camera() = default;
	Camera(float lag);
	~Camera() = default;

	void updateCamera(GameObject* myObject);
	void setCamera(sf::RenderWindow* window);
};
