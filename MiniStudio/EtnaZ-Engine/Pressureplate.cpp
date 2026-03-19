#include "Pressureplate.h"

Pressureplate::Pressureplate(float x, float y, float w, float h) : GameObject(x, y, w, h) {
	activated = false;
}

Pressureplate::~Pressureplate() {
}

bool Pressureplate::isActivated() {
	return activated;
}

void Pressureplate::activate() {


	// conditions to activate
	activated = true;
}

void Pressureplate::render(sf::RenderWindow* window) {
	if (!activated) {
		GameObject::render(window);
	}
}

