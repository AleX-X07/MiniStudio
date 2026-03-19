#include "Crate.h"

Crate::Crate(float x, float y, float w, float h) : GameObject(x, y, w, h) {
}

Crate::~Crate() {
}

void Crate::update(float& dt, Input& input) {
	// Apply gravity
}

void Crate::render(sf::RenderWindow* window) {
	GameObject::render(window);
}
