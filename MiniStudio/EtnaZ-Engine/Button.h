#pragma once
#include "GameState.h"

class Button
{
private :
	RectangleShape shape;
	
public :
	Button();
	~Button() = default;

	FloatRect getGlobalBounds() const {
		return shape.getGlobalBounds();
	}

	void setFillColor(Color color);
	void setSize(Vector2f size);
	void setPosition(Vector2f pos);

	void render(RenderWindow* window);
	void update(float& dt);
};

//class Text
//{
//private :
//	Font font;
//	Text text;
//
//public:
//	Text();
//	~Text() = default;
//
//	void setFillColor(Color color);
//	void setSize(Vector2f size);
//	void setPosition(Vector2f pos);
//	void setCharacterSize(Vector2f pos);
//
//	void render(RenderWindow* window);
//	void update(float& dt);
//};