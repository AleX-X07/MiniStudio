#include "Game.h"
#include "MainMenu.h"
#include "PauseMenu.h"
#include "Player.h"
#include "LoadLevel.h"

Game::Game(sf::RenderWindow* window, std::vector<GameState*>* _states) : GameState(window, _states), gOBuild(false) {
	setEntity();
}

void Game::Instance(sf::RenderWindow* window, std::vector<GameState*>*& states) {
	GameState* mainMenu = new Game(window, states);
	states->push_back(mainMenu);
}

void Game::manageState() {
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape)) {
		GameState::pause(states);
		PauseMenu::Instance(window, states, camera);
	}
} 

void Game::setEntity() {
	if (!gOBuild) {

		myLevel = new LoadLevel();
		myLevel->loadLevel();

		// Background white
		GameObject* backWhite = new GameObject(0, 0, win_width, win_height);
		backWhite->setColor(sf::Color::White);
		gameObject.push_back(backWhite);

		//Player
		player = new Player(750, 750,100,100);
		Animation* myAnmation = new Animation(4,1,0.15f,1024,256);
		player->setAnimation(myAnmation);

		SlimePiece* mySP = new SlimePiece(1200,930,50,50);
		mySP->setTexture(&Textures::getMyTextures()->getTexture(Textures::texturesIndices::depotSlime));;
		player->slimePiece.push_back(mySP);

		//Camera
		camera = new Camera(0.01);

		gOBuild = true;
	}
}

void Game::updateCollision() {
	if (!player) return;
	player->onGround = false;

	for (auto& platform : myLevel->Platform) {
		if (player->isColliding(*platform)) {
			player->resolveCollision(*platform);
		}
		for (auto& psP : player->slimePiece) {
			if (!(psP == nullptr)) {
				psP->onGround = false;
				if (psP->isColliding(*platform)) { 
					psP->resolveCollision(*platform);
				}
			}
		}
		for (auto& psP : player->slimePieceLeave) {
			if (!(psP == nullptr)) {
				psP->onGround = false;
				if (psP->isColliding(*platform)) {
					psP->resolveCollision(*platform);
				}
			}
		}
	}
	for (auto& Seed : myLevel->Seeds) {
		if (Seed->isCollected()) continue;
		if (player->isColliding(*Seed)) {
			Seed->collect();
			player->collectSeed();
		}
	}

	for (auto& Orb : myLevel->Orbs) {
		if (Orb->isCollected()) continue;
		if (player->isColliding(*Orb)) {
			Orb->collect();
			player->collectOrb();			
		}
	}

	for (auto& pressurePlate : myLevel->Pressureplates) {
		if (pressurePlate->isActivated()) continue;
		if (player->isColliding(*pressurePlate)) {
			pressurePlate->activate();
		}
	}

	for (auto& door : myLevel->Doors) {
		if (door->isOpen()) continue;
		if (player->isColliding(*door)) {
			// condition to open the door
			door->openDoor();
		}
	}

	for (auto& spike : myLevel->Spikes) {
		if (player->isColliding(*spike)) {
			player->respawn();
		}
	}

	for (auto& crate : myLevel->Crates) {
		if (player->isColliding(*crate)) {
			player->resolveCollision(*crate);
			// condition to push the crate
		}
	}

	for (auto& ventilation : myLevel->Ventilations) {
		if (player->isColliding(*ventilation)) {
			// condition to apply wind force
			player->applyWind(500.f, 0.016f);
		}
	}

}

void Game::update(float& dt) {
	
	if (player) {
		player->update(dt, input);
	}
	camera->updateCamera(player);
	updateCollision();
}

void Game::render() {

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
}
