#include "Button.h"

Button::Button()
{
	
}

Button::~Button()
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





TextButton::TextButton()
{

}

void TextButton::setFillColor(Color color)
{
	if (text) {
		text->setFillColor(color);
	}
}

void TextButton::setPosition(Vector2f pos)
{
	if (text) {
		text->setPosition(pos);
	}
}

void TextButton::setCharacterSize(unsigned int size)
{
	if (text) {
		text->setCharacterSize(size);
	}
}

void TextButton::setFont(sf::Font& _font)
{
    font = &_font;
    if (font && text) {
        text->setFont(*font);
        std::cout << "Police assignée au TextButton" << std::endl;
    } else {
        std::cout << "erreur: Police nulle dans setFont()" << std::endl;
    }
}

void TextButton::setString(const std::string& str)
{
	if (text) {
		text->setString(str);
	}
}

void TextButton::render(RenderWindow* window)
{
	if (window && text) {
		window->draw(*text);
	}
}

void TextButton::update(float& dt) {

}

