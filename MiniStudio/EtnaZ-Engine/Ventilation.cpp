#include "Ventilation.h"

Ventilation::Ventilation(float x, float y, float w, float h) : GameObject(x, y, w, h) {
}

Ventilation::~Ventilation() {
}

float Ventilation::getWindForce() {
	return windForce;
}

void Ventilation::render(RenderWindow* window) {
	GameObject::render(window);
}
