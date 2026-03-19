#include "Orb.h"

Orb::Orb(float x, float y, float w, float h) : GameObject(x, y, w, h) {

}

bool Orb::isCollected() {
	return collected;
}

void Orb::collect() {
	collected = true;
	setVisibilityFalse();
}

void Orb::render(RenderWindow* window) {
	if (!collected) {
		GameObject::render(window);
	}
}