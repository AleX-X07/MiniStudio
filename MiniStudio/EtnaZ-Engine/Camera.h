#pragma once
#include "Globals.h"
#include "GameObject.h"

class Camera
{
private:
	View myView;
	Vector2f pos;
	Vector2f center;
	Vector2f targetPos;
	float lag;

public:
	Camera() = default;
	Camera(float lag, float zoom);
	~Camera() = default;

	void updateCamera(GameObject* myObject);
	void setCamera(RenderWindow* window);
};
