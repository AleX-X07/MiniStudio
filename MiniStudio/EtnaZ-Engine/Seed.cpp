#include "Seed.h"

Seed::Seed(float x, float y, float w, float h) : GameObject(x, y, w, h) {
	collected = false;
}

Seed::~Seed() {
}


bool Seed::isCollected() {
	return collected;
}

void Seed::collect() {
	collected = true;
	setVisibilityFalse();
}

void Seed::render(sf::RenderWindow* window) {
	if (!collected) {
		GameObject::render(window);
	}
}
