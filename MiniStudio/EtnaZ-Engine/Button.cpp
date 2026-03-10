#include "Button.h"

Button::Button()
{
}

void Button::setFillColor(Color color)
{
	shape.setFillColor(color);
}

void Button::setSize(Vector2f size)
{
	shape.setSize(size);
}

void Button::setPosition(Vector2f pos)
{
	shape.setPosition(pos);
}

void Button::render(RenderWindow* window)
{
	if (window) {
		window->draw(shape);
	}
}

void Button::update(float& dt) {

}



//Text::Text()
//{
//}
//
//void Text::setFillColor(Color color)
//{
//	text.setFillColor(color);
//}
//
//void Text::setSize(Vector2f size)
//{
//	text.setSize(size);
//}
//
//void Text::setPosition(Vector2f pos)
//{
//	text.setPosition(pos);
//}
//
//void Text::setCharacterSize(Vector2f pos)
//{
//	text(font).setCharacterSize(pos);
//}
//
//void Text::render(RenderWindow* window)
//{
//	if (window) {
//		window->draw(text);
//	}
//}
//
//void Text::update(float& dt) {
//
//}