#include "Player.h"


Player::Player(float x, float y) : GameObject(x,y)
{
	speed = 300.0f;
	myAnimation = nullptr;
	spawnX = x;
	spawnY = y;

}

void Player::clampInScreen() {
	pos.x = std::max(0.f, std::min(pos.x, (float)(level_size_width - size.x)));
	pos.y = std::max(0.f, std::min(pos.y, (float)(level_size_heigt - size.y)));
	setPos(pos);
}

void Player::jump() {
	if (onGround) {
		velocityY = jumpForce;
		onGround = false;
	}
}

void Player::collectSeed() {
	seedNb++;
}

int Player::getSeedNb() {
	return seedNb;
}

void Player::collectOrb() {
	orbNb++;

	if (orbNb == 1) {
		canDash = true;
	}
	if (orbNb == 2) {
		canDoubleJump = true;
	}
	if (orbNb == 3) {
		canDivision = true;
	}
}

void Player::respawn() {
	pos.x = spawnX;
	pos.y = spawnY;
	velocityX = 0;
	velocityY = 0;
	onGround = false;
	setPos(pos);
}

void Player::applyWind(float windForce, float dt) {
	//helpppp
}

void Player::setAnimation(Animation * _myAnimation) {
	myAnimation = _myAnimation;
}


void Player::render(RenderWindow * window) {
	myAnimation->render(*window);

	rect.setTexture(&myAnimation->texture);
	rect.setTextureRect(myAnimation->myStateRect);

	window->draw(rect);
}

void Player::update(float& dt, Input & input) {
	if (Keyboard::isKeyPressed(Keyboard::Key::Q)) {
		pos.x -= speed * dt;
	}
	if (Keyboard::isKeyPressed(Keyboard::Key::D)) {
		pos.x += speed * dt;
	}
	if (Keyboard::isKeyPressed(Keyboard::Key::Space)) {
		jump();
	}
	if (!onGround) {
		velocityY += gravity * dt;
		if (velocityY > 600.0f) velocityY = 600.0f;

		pos.y += velocityY * dt;
		pos.x += velocityX * dt;
		velocityX = 0;
	}
	clampInScreen();
	setPos(pos);
	myAnimation->update(dt);
}

void Player::resolveCollision(GameObject & gameObject) {
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

