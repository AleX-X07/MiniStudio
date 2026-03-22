#include "Game.h"

#include "MainMenu.h"
#include "PauseMenu.h"
#include "Player.h"
#include "LoadLevel.h"
#include "Parallax.h"

Game::Game(sf::RenderWindow* window, std::vector<GameState*>* _states) : GameState(window, _states), gOBuild(false) {
	setEntity();
	music.openFromFile("assets/sound/water-drop.ogg");
	music.setLooping(true);
	music.setVolume(100.f);
	music.play();
}

void Game::Instance(sf::RenderWindow* window, std::vector<GameState*>*& states) {
	GameState* mainMenu = new Game(window, states);
	states->push_back(mainMenu);
}

void Game::manageState() {
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape)) {
		music.pause();
		GameState::pause(states);
		PauseMenu::Instance(window, states, camera);
	}
	if (player->currentStates == Player::SlimeStates::death) {
		music.pause();
		GameState::pause(states);
		GameOver::Instance(window, states, camera);
	}
}

void Game::setEntity() {
	if (!gOBuild) {

		myLevel = new LoadLevel();
		myLevel->loadLevel();

		// Assets
		GameObject* assets1 = new GameObject(0, 0, win_width, win_height);
		assets1->setTexture((&Textures::getMyTextures()->getTexture(Textures::texturesIndices::zone1Layer1)));
		gameObject.push_back(assets1);

		GameObject* assets2 = new GameObject(1920, 0, win_width, win_height);
		assets2->setTexture((&Textures::getMyTextures()->getTexture(Textures::texturesIndices::zone2Layer1)));
		gameObject.push_back(assets2);

		GameObject* assets3 = new GameObject(1920, 0, win_width, win_height);
		assets3->setTexture((&Textures::getMyTextures()->getTexture(Textures::texturesIndices::zone3Layer1)));
		gameObject.push_back(assets3);

		//Player
		player = new Player(myLevel->spawnX, myLevel->spawnY, 100, 100);
		Animation* myAnmation = new Animation(4, 1, 0.15f, 1024, 256);
		player->setAnimation(myAnmation);


		//Parallax
		parallax = new Parallax();
		//parallax->addLayer(Textures::texturesIndices::Layer2?, 1.0f);

		/*SlimePiece* mySP = new SlimePiece(1200,700,50,50);
		mySP->setTexture(&Textures::getMyTextures()->getTexture(Textures::texturesIndices::depotSlime));;
		player->slimePiece.push_back(mySP);*/

		//Camera
		camera = new Camera(0.01);

		gOBuild = true;
	}
}

void Game::updateCollision() {
	if (!player) return;

	player->onGround = false;
	for (auto& psP : player->slimePiece) {
		psP->onGround = false;
	}
	for (auto& psP : player->slimePieceLeave) {
		psP->onGround = false;
	}

	for (auto& platform : myLevel->Platform) {
		if (player->isColliding(*platform)) {
			player->resolveCollision(*platform);
		}

		for (auto& psP : player->slimePiece) {
			if (psP != nullptr) {
				if (psP->isColliding(*platform)) {
					psP->resolveCollision(*platform);
				}
			}
		}

		for (auto& psP : player->slimePieceLeave) {
			if (psP != nullptr) {
				if (psP->isColliding(*platform)) {
					psP->resolveCollision(*platform);
				}
			}
		}

		for (auto& crate : myLevel->Crates) {
			if (crate->isColliding(*platform)) {
				float overlapLeft = (crate->pos.x + crate->size.x) - platform->pos.x;
				float overlapRight = (platform->pos.x + platform->size.x) - crate->pos.x;
				float overlapTop = (crate->pos.y + crate->size.y) - platform->pos.y;
				float overlapBottom = (platform->pos.y + platform->size.y) - crate->pos.y;

				bool fromLeft = std::abs(overlapLeft) < std::abs(overlapRight);
				bool fromTop = std::abs(overlapTop) < std::abs(overlapBottom);

				float minX = fromLeft ? overlapLeft : overlapRight;
				float minY = fromTop ? overlapTop : overlapBottom;

				if (std::abs(minX) < std::abs(minY)) {
					crate->pos.x += fromLeft ? -minX : minX;
				}
				else {
					if (fromTop) {
						crate->pos.y -= minY;
						crate->onGround = true;
					}
					else {
						crate->pos.y += minY;
					}
				}
				crate->setPos(crate->pos);
			}
		}
	}

	for (auto& seed : myLevel->Seeds) {
		if (seed->isCollected()) continue;
		if (player->isColliding(*seed)) {
			seed->collect();
			player->collectSeed();
		}
	}

	for (auto& orb : myLevel->Orbs) {
		if (orb->isCollected()) continue;
		if (player->isColliding(*orb)) {
			orb->collect();
			player->collectOrb();
		}
	}

	for (int i = myLevel->Slime.size() - 1; i >= 0; i--) {
		if (player->isColliding(*myLevel->Slime[i])) {
			player->slimePiece.push_back(myLevel->Slime[i]);
			myLevel->Slime.erase(myLevel->Slime.begin() + i);
		}
	}

	for (auto& spike : myLevel->Spikes) {
		if (player->isColliding(*spike)) {
			player->takeDamage();
			player->respawn();
		}
	}

	for (auto& crate : myLevel->Crates) {
		if (player->isColliding(*crate)) {
			player->resolveCollision(*crate);
			if (player->currentStates == Player::SlimeStates::heavy) {
				float playerCenterX = player->pos.x + player->size.x * 0.5f;
				float crateCenterX = crate->pos.x + crate->size.x * 0.5f;
				float direction = (playerCenterX < crateCenterX) ? 1.f : -1.f;
				crate->push(direction, 250.f);
			}
		}
	}

	for (auto& ventilation : myLevel->Ventilations) {
		if (player->isColliding(*ventilation)) {
			player->applyWind(ventilation->getWindForce(), 0.016f);
		}
	}

	for (auto& pp : myLevel->Pressureplates) {
		if (player->isColliding(*pp)) {
			player->resolveCollision(*pp);
		}

		for (auto& psP : player->slimePiece) {
			if (psP != nullptr) {
				if (psP->isColliding(*pp)) {
					psP->resolveCollision(*pp);
				}
			}
		}

		for (auto& psP : player->slimePieceLeave) {
			if (psP != nullptr) {
				if (psP->isColliding(*pp)) {
					psP->resolveCollision(*pp);
				}
			}
		}

		for (auto& crate : myLevel->Crates) {
			if (crate->isColliding(*pp)) {
				crate->resolveCollision(*pp);
			}
		}
	}

	for (auto& psP : player->slimePiece) {
		if (psP != nullptr) {
			if (player->isColliding(*psP)) {
				player->resolveCollision(*psP);
			}
		}
	}
}

void Game::onResume() {
	music.play();
}

void Game::update(float& dt) {
	if (player) {
		player->update(dt, input);

		if (player->pos.x < 1920 && player->pos.y < 1080) {
			parallax->loadZone(Parallax::zone::zone1);
		}
		else if (player->pos.x > 1920 && player->pos.y < 1080) {
			parallax->loadZone(Parallax::zone::zone2);
		}
		else if (player->pos.x > 1920 && player->pos.y > 1080) {
			parallax->loadZone(Parallax::zone::zone3);
		}
		else {
			parallax->loadZone(Parallax::zone::zone4);
		}
	}
	camera->updateCamera(player);
	updateCollision();


	for (auto& crate : myLevel->Crates) {
		crate->update(dt, input);
	}

	for (auto& pp : myLevel->Pressureplates) {
		pp->activate(player, myLevel->Crates);
	}

	bool allActivated = true;
	for (auto& pp : myLevel->Pressureplates) {
		if (!pp->isActivated()) {
			allActivated = false;
			break;
		}
	}

	if (allActivated) {
		for (auto& door : myLevel->Doors) {
			if (!door->isOpen()) {
				door->openDoor();
			}
		}
	}
}

void Game::render() {
	window->setView(window->getDefaultView());
	if (parallax) {
		parallax->render(*window, *camera, player);
	}

	camera->setCamera(window);

	for (auto gO : gameObject) {
		gO->render(window);
	}

	for (auto gOC : gameObjectCollider) {
		gOC->render(window);
	}

	myLevel->render(window);

	if (player) {
		player->render(window);
	}

}

Game::~Game() {
	delete player;
	player = nullptr;

	delete myLevel;
	myLevel = nullptr;

	delete parallax;
	parallax = nullptr;

	delete camera;
	camera = nullptr;

	gameObject.clear();
	gameObjectCollider.clear();
}