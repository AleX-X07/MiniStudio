#pragma once
#include "GameState.h"
class Player
{
private :
	RectangleShape shape;
	float speed;
	Vector2f position;

public :
	Player();
	~Player() = default;

	void setFillColor(Color color);
	void setSize(Vector2f size);
	void setPosition(Vector2f pos);

	void render(RenderWindow* window);
	void update(float& dt);
};

