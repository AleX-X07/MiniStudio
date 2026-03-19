#include "Spike.h"
#include "Player.h"

Spike::Spike(float x, float y, float w, float h) : GameObject(x, y, w, h) {
}

Spike::~Spike() {
}

void Spike::render(RenderWindow* window) {
	GameObject::render(window);
}
