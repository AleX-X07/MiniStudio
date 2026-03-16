#include "Button.h"

Button::Button(float x, float y, float w, float h, std::vector<GameState*>* _states, sf::RenderWindow* _window) : GameObject(x,y,w,h), window(_window), states(_states) {

}

bool Button::isClicked(Input& input) {
	if (input.isMousePressed(sf::Mouse::Button::Left)) {
		mousePos = input.getMousePos();
		if (mousePos.x >= pos.x &&
			mousePos.x <= pos.x + size.x &&
			mousePos.y >= pos.y &&
			mousePos.y <= pos.y + size.y) {
			return true;
		}
	}
	return false;
}

void Button::buttonPlay(Input& input){ 
	if (isClicked(input)) {
		GameState::nextState(states);
		Game::Instance(window, states);
	}
}

void Button::buttonQuit(Input& input) {
	if (isClicked(input)) {
		input.quit = true;
	}
}

void Button::update(float& dt, Input& input) {
	buttonPlay(input);
}

void Button::render(sf::RenderWindow* window) {
	GameObject::render(window);
}
