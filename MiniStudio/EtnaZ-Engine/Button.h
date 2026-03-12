#pragma once
#include "GameState.h"
#include "Textures.h"
#include <SFML/Graphics/Text.hpp>


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

class TextButton
{
private :
	sf::Text* text;
	sf::Font* font;
public:
	TextButton();
	~TextButton();

	void setFillColor(Color color);
	void setPosition(Vector2f pos);
	void setCharacterSize(unsigned int size);
	void setFont(sf::Font& _font);
	void setString(const std::string& str);

	void render(RenderWindow* window);
	void update(float& dt);
};