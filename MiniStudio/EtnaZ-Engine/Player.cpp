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

void Player::skillsLeaveSlime(Input& input) {
	if (input.isKeyPressed(sf::Keyboard::Key::A)) {
		if (slimePieceLeave.size() <= 2) {
			float multipliterSlilme = 1 - weightLoss;

			SlimePiece* block = new SlimePiece(getPos().x, getPos().y, 50, 50);
			block->setColor((sf::Color::Blue));

			sf::Vector2f sBlock = { float(getSize().x * weightLoss), float(getSize().y * weightLoss) };
			block->setSize(sBlock);

			sf::Vector2f nSizeSlime = { float(getSize().x * multipliterSlilme), float(getSize().y * multipliterSlilme) };
			setSize(nSizeSlime);

			slimePieceLeave.push_back((block));

			/*if (slimePiece.size() == 0) {
				currentStates = Player::SlimeStates::normal;
			}
			else if (slimePiece.size() == 1) {
				currentStates = Player::SlimeStates::light;
			}
			else if (slimePiece.size() == 2) {
				currentStates = Player::SlimeStates::micro;
			}*/
			weightLoss *= 0.9;
		}
	}
}

void Player::takeSlime(Input& input){

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


void Player::render(sf::RenderWindow * window) {
	myAnimation->render(*window);

	rect.setTexture(&myAnimation->texture);
	rect.setTextureRect(myAnimation->myStateRect);

	for (auto& sP : slimePiece) {
		sP->render(window);
	}
	for (auto& sP : slimePieceLeave) {
		sP->render(window);
	}

	window->draw(rect);

}

void Player::update(float& dt, Input & input) {
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Q)) {
		pos.x -= speed * dt;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)) {
		pos.x += speed * dt;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space)) {
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
	skillsLeaveSlime(input);
	takeSlime(input);
	myAnimation->update(dt);
	for (auto& sP : slimePiece) {
		sP->update(dt, input);
	}
	for (auto& sP : slimePieceLeave) {
		sP->update(dt, input);
	}
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

