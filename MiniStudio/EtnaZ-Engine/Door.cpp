#include "Door.h"

Door::Door(float x, float y, float w, float h) : GameObject(x, y, w, h){
	open = false;
}

Door::~Door() {
}

bool Door::isOpen() {
	return open;
}

void Door::openDoor() {
	open = true;
	setVisibilityFalse();
}

void Door::render(sf::RenderWindow* window) {
	if (!open) {
		GameObject::render(window);
	}
}