#include "Crate.h"

Crate::Crate(float x, float y, float w, float h) : GameObject(x, y, w, h) {
}

Crate::~Crate() {
}

void Crate::update(float& dt, Input& input) {
	velocityY += gravity * dt;
	if (velocityY > 600.f) velocityY = 600.f;

	velocityX *= 0.85f;
	if (std::abs(velocityX) < 1.f) velocityX = 0.f;

	pos.x += velocityX * dt;
	pos.y += velocityY * dt;
	setPos(pos);
}

void Crate::push(float directionX, float force) {
	velocityX = directionX * force;
}

void Crate::resolveCollision(GameObject& gameObject) {
	float overlapLeft = (pos.x + size.x) - gameObject.pos.x;
	float overlapRight = (gameObject.pos.x + gameObject.size.x) - pos.x;
	float overlapTop = (pos.y + size.y) - gameObject.pos.y;
	float overlapBottom = (gameObject.pos.y + gameObject.size.y) - pos.y;

	bool fromLeft = std::abs(overlapLeft) < std::abs(overlapRight);
	bool fromTop = std::abs(overlapTop) < std::abs(overlapBottom);

	float minX = fromLeft ? overlapLeft : overlapRight;
	float minY = fromTop ? overlapTop : overlapBottom;

	if (std::abs(minX) < std::abs(minY)) {
		pos.x += fromLeft ? -minX : minX;
		velocityX = 0.f;
	}
	else {
		if (fromTop) {
			pos.y -= minY;
			velocityY = 0.f;
			onGround = true;
		}
		else {
			pos.y += minY;
			velocityY = 0.f;
		}
	}
	setPos(pos);
}

void Crate::render(sf::RenderWindow* window) {
	GameObject::render(window);
}
