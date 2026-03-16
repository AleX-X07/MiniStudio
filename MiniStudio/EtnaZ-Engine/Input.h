#pragma once
#include "Globals.h"

class Input
{
private:
	bool keyPressed;
	Keyboard::Key key;

	bool mousePressed;
	Mouse::Button mouse;
	Vector2i mousePos;

public:
	Input();
	~Input() = default;

	void setEvent(const Event event);
	void reset();

	bool isKeyPressed(Keyboard::Key key);
	bool isMousePressed(Mouse::Button button);
	Vector2i getMousePos();
};

