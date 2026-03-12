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



TextButton::TextButton()
	: font(nullptr)
{
	
	
}

void TextButton::setFillColor(Color color)
{
	text->setFillColor(color);
}

void TextButton::setPosition(Vector2f pos)
{
	text->setPosition(pos);
}

void TextButton::setCharacterSize(unsigned int size)
{
	text->setCharacterSize(size);
}

void TextButton::setFont(sf::Font& _font)
{
    font = &_font;
    if (font) {
        text->setFont(*font);
        std::cout << "Police assignée au TextButton" << std::endl;
    } else {
        std::cout << "ERREUR: Police nulle dans setFont()" << std::endl;
    }
}

void TextButton::setString(const std::string& str)
{
	text->setString(str);
}

void TextButton::render(RenderWindow* window)
{
	if (window) {
		window->draw(*text);
	}
}

void TextButton::update(float& dt) {

}

TextButton::~TextButton()
{
	delete text;
}