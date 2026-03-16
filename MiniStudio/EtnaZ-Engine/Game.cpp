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

		// Test platform
		GameObject* platform = new GameObject(0, 980, 1920, 100);
		platform->setColor(Color::Green);
		gameObjectCollider.push_back(platform);

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

	for (auto& gameObject : gameObjectCollider) {
		player->onGround = false;
		if (player->isColliding(*gameObject) && gameObject != player) {
			player->resolveCollision(*gameObject);
		}
	}

	for (auto& platform : myLevel->Platform) {
		player->onGround = false;
		if (player->isColliding(*platform) && platform != player) {
			player->resolveCollision(*platform);
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