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
	Camera(float lag);
	~Camera() = default;

	void updateCamera(GameObject* myObject);
	void setCamera(RenderWindow* window);
	void getCameraPos(Vector2f& _pos) const;
};
