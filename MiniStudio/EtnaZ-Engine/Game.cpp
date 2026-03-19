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

		// Test platform
		GameObject* platform = new GameObject(0, 980, 1920, 100);
		platform->setColor(sf::Color::Green);
		gameObjectCollider.push_back(platform);

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

	for (auto& gameObject : gameObjectCollider) {
		player->onGround = false;
		if (player->isColliding(*gameObject) && gameObject != player) {
			player->resolveCollision(*gameObject);
		}
		for (auto& psP : player->slimePiece) {
			if (!(psP == nullptr)) {
				psP->onGround = false;
				if (psP->isColliding(*gameObject)) { 
					psP->resolveCollision(*gameObject);
				}
			}
		}
		for (auto& psP : player->slimePieceLeave) {
			if (!(psP == nullptr)) {
				psP->onGround = false;
				if (psP->isColliding(*gameObject)) {
					psP->resolveCollision(*gameObject);
				}
			}
		}
	}

	for (auto& platform : myLevel->Platform) {
		if (player->isColliding(*platform)) {
			player->resolveCollision(*platform);
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
