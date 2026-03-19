#pragma once
#include "Globals.h"
#include "GameObject.h"
#include "HUD.h"

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
	void camHUD(sf::RenderWindow* window);

	void getCameraPos(Vector2f& _pos) const;

};
