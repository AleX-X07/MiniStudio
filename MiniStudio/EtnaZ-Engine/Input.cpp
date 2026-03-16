#include "Input.h"

#include "SFML/Window/Event.hpp"

Input::Input() : keyPressed(false), mousePressed(false), mousePos({ 0,0 }), quit(false) {

}


void Input::setEvent(sf::Event event) {
    if (auto* k = event.getIf<sf::Event::KeyPressed>()) {
        keyPressed = true;
        key = k->code;
    }
    else if (auto* m = event.getIf<sf::Event::MouseButtonPressed>()) {
        mousePressed = true;
        mouse = m->button;
        mousePos = m->position;
    }
}

void Input::reset() {
    keyPressed = false;
    mousePressed = false;
}


bool Input::isKeyPressed(sf::Keyboard::Key _key) {
    return keyPressed && key == _key;
}

bool Input::isMousePressed(sf::Mouse::Button _button) {
    return mousePressed && mouse == _button;
}

sf::Vector2i Input::getMousePos() {
    return mousePos;
}