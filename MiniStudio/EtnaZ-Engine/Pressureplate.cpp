#include "Pressureplate.h"

Pressureplate::Pressureplate(float x, float y, float w, float h) : GameObject(x, y, w, h) {
	activated = false;
}

Pressureplate::~Pressureplate() {
}

bool Pressureplate::isActivated() {
	return activated;
}

void Pressureplate::activate(Player* player, std::vector<Crate*>& crates) {
	if (currentType == Pressureplate::typePuzzle::player){
		if (player->currentStates == Player::SlimeStates::heavy) {
			activated = true;
		}		
	}
	if (currentType == Pressureplate::typePuzzle::block) {
		for (auto& block : crates) {
			if (block->isColliding(*this)) {
				activated = true;
			}
		}
	}
	if (currentType == Pressureplate::typePuzzle::slime) {
		for (auto& slime : player->slimePiece) {
			if (slime->isColliding(*this)) {
				std::cout << "eheheh";
				activated = true;
			}
		}
	}
}

void Pressureplate::render(sf::RenderWindow* window) {
	if (!activated) {
		GameObject::render(window);
	}
}

