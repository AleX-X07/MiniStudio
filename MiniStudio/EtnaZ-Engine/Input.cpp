#include "Input.h"

Input::Input() : keyPressed(false), mousePressed(false), mousePos({ 0,0 }) {

}


void Input::setEvent(const Event event) {
    if (auto* k = event.getIf<Event::KeyPressed>()) {
        keyPressed = true;
        key = k->code;
    }
    else if (auto* m = event.getIf<Event::MouseButtonPressed>()) {
        mousePressed = true;
        mouse = m->button;
        mousePos = m->position;
    }
}

void Input::reset() {
    keyPressed = false;
    mousePressed = false;
}


bool Input::isKeyPressed(Keyboard::Key _key) {
    return keyPressed && key == _key;
}

bool Input::isMousePressed(Mouse::Button _button) {
    return mousePressed && mouse == _button;
}

Vector2i Input::getMousePos() {
    return mousePos;
}