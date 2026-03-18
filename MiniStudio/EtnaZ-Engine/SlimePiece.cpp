#include "SlimePiece.h"

SlimePiece::SlimePiece(float x, float y, float w, float h) : GameObject(x,y,w,h), gravity((980)), velocityX(0), velocityY(0){
}

void SlimePiece::update(float& dt, Input& input) {
	if (!onGround) {
		velocityY += gravity * dt;
		if (velocityY > 600.0f) velocityY = 600.0f;

		pos.y += velocityY * dt;
		pos.x += velocityX * dt;
		velocityX = 0;
	}
	setPos(pos);	
	GameObject::update(dt, input);
}

void SlimePiece::render(RenderWindow* window) {
	GameObject::render(window);
}

void SlimePiece::resolveCollision(GameObject& gameObject) {
	float overlapLeft = (pos.x + size.x) - gameObject.pos.x;
	float overlapright = (gameObject.pos.x + gameObject.size.x) - pos.x;
	float overlaptop = (pos.y + size.y) - gameObject.pos.y;
	float overlapbottom = (gameObject.pos.y + gameObject.size.y) - pos.y;

	bool fromleft = std::abs(overlapLeft) < std::abs(overlapright);
	bool fromtop = std::abs(overlaptop) < std::abs(overlapbottom);

	float minoverlapx = fromleft ? overlapLeft : overlapright;
	float minoverlapy = fromtop ? overlaptop : overlapbottom;

	if (std::abs(minoverlapx) < std::abs(minoverlapy)) {
		pos.x += fromleft ? -minoverlapx : minoverlapx;
		velocityX = 0;
	}
	else {
		if (fromtop) {
			pos.y -= minoverlapy;
			velocityY = 0;
			onGround = true;
		}
		else {
			pos.y += minoverlapy;
			velocityY = 0;
		}
	}
	setPos(pos);
}


