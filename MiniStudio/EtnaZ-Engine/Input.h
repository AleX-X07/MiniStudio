#pragma once
#include "SFMl/Graphics.hpp"

class Input
{
private:
	bool keyPressed;
	sf::Keyboard::Key key;

	bool mousePressed;
	sf::Mouse::Button mouse;
	sf::Vector2i mousePos;

public:
	bool quit;

public:
	Input();
	~Input() = default;

	void setEvent(sf::Event event);
	void reset();

	bool isKeyPressed(sf::Keyboard::Key key);
	bool isMousePressed(sf::Mouse::Button button);
	sf::Vector2i getMousePos();
};

