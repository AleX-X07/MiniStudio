#include "Player.h"
#include "Textures.h"

Player::Player(float x, float y, float w, float h) : GameObject(x,y,w,h) {
	speed = 300.0f;
	dashDistance = 300.0f;
	myAnimation = nullptr;

	dashCooldown = 3.0f;
	dashTimer = 0.0f;
	canDash = true;
	spawnX = x;
	spawnY = y;

}

Player::~Player() {
	delete myAnimation;
	myAnimation = nullptr;

	slimePiece.clear();

	for (auto& sPL : slimePieceLeave) {
		delete sPL;
		sPL = nullptr;
	}
	slimePieceLeave.clear();
}

void Player::clampInScreen() {
	pos.x = std::max(0.f, std::min(pos.x, (float)(level_size_width - size.x)));
	pos.y = std::max(0.f, std::min(pos.y, (float)(level_size_heigt - size.y)));
	setPos(pos);
}

void Player::jump() {
	if (jumpCount < maxJumpCount) {
		velocityY = jumpForce;
		onGround = false;
		jumpCount++;
	}
}

void Player::run() {
	if (runBool) {
		speed *= 1.5;
	}
	else {
		speed /= 1.5;
	}
}

void Player::takeDamage() {
	if (currentStates == SlimeStates::light) {
		currentStates = SlimeStates::death;
	}
	else if (currentStates == SlimeStates::normal) {
		setSize({float(getSize().x * 0.8), float(getSize().y * 0.8)});
	}
	else if (currentStates == SlimeStates::heavy) {
		setSize({ float(getSize().x * 0.95), float(getSize().y * 0.95) });
	}
}

void Player::dash(float& dt) {
	if (!canDash) {
		dashTimer -= dt;
		if (dashTimer <= 0.0f) {
			canDash = true;
			dashTimer = 0.0f;
		}
	}
	if (isDashing) {
		dashProgress += dt;
		if (dashProgress >= dashTotalTime) {
			isDashing = false;
		}
		else {
			float t = dashProgress / dashTotalTime;
			pos.x = pos.x + (dashTarget - pos.x) * t;
		}
		setPos(pos);
	}
}

void Player::skillsLeaveSlime(Input& input) {
	if (input.isKeyPressed(sf::Keyboard::Key::A)) {
		if (slimePieceLeave.size() <= nbrDepotSlime) {
			float multipliterSlilme = 1 - weightLoss;

			SlimePiece* block = new SlimePiece(getPos().x, getPos().y, 50, 50);
			block->setTexture(&Textures::getMyTextures()->getTexture(Textures::texturesIndices::depotSlime));;

			sf::Vector2f sBlock = { float(getSize().x * weightLoss), float(getSize().y * weightLoss) };
			block->setSize(sBlock);

			sf::Vector2f nSizeSlime = { float(getSize().x * multipliterSlilme), float(getSize().y * multipliterSlilme) };
			setSize(nSizeSlime);

			slimePieceLeave.push_back((block));

			weightLoss *= 0.9;
		}
	}
}

void Player::takeSlime(Input& input) {

	if (!slimePieceLeave.empty()) {
		for (int X = 0; X < slimePieceLeave.size(); X++) {
			if (input.isKeyPressed((sf::Keyboard::Key::W))) {
				if (isColliding(*slimePieceLeave[X])) {
					const auto It = slimePieceLeave.begin() + X;
					sf::Vector2f multiSlime = { float(slimePieceLeave[X]->getSize().x * 0.9), float(slimePieceLeave[X]->getSize().y * 0.9) };
					sf::Vector2f nSize = { getSize().x + multiSlime.x, getSize().y + multiSlime.y };
					setSize(nSize);
					weightLoss = 0.3;
					slimePieceLeave.erase(It);

				}
			}
		}
	}

	if (!slimePiece.empty()) {
		for (int X = 0; X < slimePiece.size(); X++) {
			if (input.isKeyPressed((sf::Keyboard::Key::W))) {
				if (isColliding(*slimePiece[X])) {
					takeDamage();
					const auto It = slimePiece.begin() + X;
					sf::Vector2f multiSlime = { float(slimePiece[X]->getSize().x * 0.9), float(slimePiece[X]->getSize().y * 0.9) };
					sf::Vector2f nSize = { getSize().x + multiSlime.x, getSize().y + multiSlime.y };
					setSize(nSize);
					weightLoss = 0.3;
					slimePiece.erase(It);
				}
			}
		}
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
	myAnimation=_myAnimation;
}


void Player::render(sf::RenderWindow * window) {
	myAnimation->render(*window,this);

	rect.setTexture(&myAnimation->texture);
	rect.setTextureRect(myAnimation->myStateRect);

	for (auto& sP : slimePieceLeave) {
		sP->render(window);
	}

	window->draw(rect);

}

void Player::update(float& dt, Input& input) {
	dash(dt);
	if (currentStates != SlimeStates::death) {
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Q)) {
			pos.x -= speed * dt;
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S) && canDash) {
				isDashing = true;
				dashProgress = 0.0f;
				dashTarget = pos.x - dashDistance;
				canDash = false;
				dashTimer = dashCooldown;
			}
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)) {
			pos.x += speed * dt;
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S) && canDash) {
				isDashing = true;
				dashProgress = 0.0f;
				dashTarget = pos.x + dashDistance;
				canDash = false;
				dashTimer = dashCooldown;
			}
		}
		/*if (input.isKeyPressed(sf::Keyboard::Key::Space)) {
			jump();
		}*/
		if (input.isKeyPressed(sf::Keyboard::Key::LControl)) {
			runBool = !runBool;
			run();
		}
		skillsLeaveSlime(input);
		takeSlime(input);

		bool spacePressed = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space);
		if (spacePressed && !spaceWasPressed) {
			jump();
		}
		spaceWasPressed = spacePressed;
		if (!onGround) {
			velocityY += gravity * dt;
			if (velocityY > 600.0f) velocityY = 600.0f;

			pos.y += velocityY * dt;
			pos.x += velocityX * dt;
			velocityX = 0;
		}

		if (!onGround && jumpCount == 0) {
			jumpCount = 1;
		}

		clampInScreen();
		setPos(pos);
		myAnimation->update(dt, input, this);

		for (auto& sP : slimePiece) {
			sP->update(dt, input);
		}
		for (auto& sP : slimePieceLeave) {
			sP->update(dt, input);
		}

		if (currentStates != SlimeStates::death) {
			if (getSize().x < defautlSize.x * 0.75 && getSize().y < defautlSize.y * 0.75) {
				currentStates = SlimeStates::light;
				nbrDepotSlime = 0;
			}
			else if ((getSize().x > defautlSize.x * 0.8 && getSize().y > defautlSize.y * 0.8) && (getSize().x < defautlSize.x * 1.1 && getSize().y < defautlSize.y * 1.1)) {
				currentStates = SlimeStates::normal;
				nbrDepotSlime = 1;
			}
			else if (getSize().x > defautlSize.x * 1.1 && getSize().y > defautlSize.y * 1.1) {
				currentStates = SlimeStates::heavy;
				nbrDepotSlime = 2;
			}
		}

		if (getSize().x > defautlSize.x * 1.15 && getSize().y > defautlSize.y * 1.15) {
			setSize({ float(defautlSize.x * 1.15), float(defautlSize.y * 1.15) });
		}
		if (getSize().x < defautlSize.x * 0.75 && getSize().y < defautlSize.y * 0.75) {
			setSize({ float(defautlSize.x * 0.75), float(defautlSize.y * 0.75) });
		}
	}
}

void Player::resolveCollision(GameObject& gameObject) {
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

	if (onGround) {
		jumpCount = 0;
	}
}

