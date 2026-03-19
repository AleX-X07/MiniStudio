#include "Game.h"
#include "MainMenu.h"
#include "Player.h"
#include "LoadLevel.h"

Game::Game(RenderWindow* window, vector<GameState*>* _states) : GameState(window, _states), gOBuild(false) {

}

void Game::Instance(RenderWindow* window, vector<GameState*>*& states) {
	GameState* mainMenu = new Game(window, states);
	states->push_back(mainMenu);
}

void Game::manageState() {
	if (Keyboard::isKeyPressed(Keyboard::Key::Escape)) {
		GameState::nextState(states);
		MainMenu::Instance(window, states);
	}
}

void Game::setEntity() {
	if (!gOBuild) {

		myLevel = new LoadLevel();
		myLevel->loadLevel();

		// Background white
		GameObject* backWhite = new GameObject(0, 0, win_width, win_height);
		backWhite->setColor(Color::White);
		gameObject.push_back(backWhite);

		//Player
		player = new Player(900, 750);
		Animation* myAnimation = new Animation(Textures::getMyTextures()->getTexture(Textures::texturesIndices::testSprite), 5, 1, 0.09f, 512, 104);
		player->setAnimation(myAnimation);
		player->setSize({ 100,100 });

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
	
	setEntity();
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