#include "Input.h"

void Input::setInputKey(const Event::KeyPressed* input) {
	currentInputKey = input;
}

void Input::setInputMouse(const Event::MouseButtonPressed* input) {
	currentInputMouse = input;
}