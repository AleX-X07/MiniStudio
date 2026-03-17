#include "Game.h"
#include "MainMenu.h"
#include "Player.h"


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

		// Background white
		GameObject* backWhite = new GameObject(0, 0, win_width, win_height);
		backWhite->setColor(Color::White);
		gameObject.push_back(backWhite);

		// Test platform
		GameObject* platform = new GameObject(0, 980, 1920, 100);
		platform->setColor(Color::Green);
		gameObjectCollider.push_back(platform);

		// Test block
		GameObject* block = new GameObject(500, 880, 100, 100);
		block->setColor((Color::Black));
		gameObjectCollider.push_back(block);

		//Player
		player = new Player(900, 750);
		player->setColor(Color::Red);

		//Camera
		camera = new Camera(0.01);

		//Parallax
		parallax = new Parallax();
		parallax->addLayer(Textures::texturesIndices::Layer0, 0.5f);
		parallax->addLayer(Textures::texturesIndices::Layer1, 0.8f);
		//parallax->addLayer(Textures::texturesIndices::Layer2?, 1.0f);

		gOBuild = true;
	}
}

void Game::updateCollision() {
	if (!player) return;
	player->onGround = false;
	for (auto& gameObject : gameObjectCollider) {
		if (player->isColliding(*gameObject) && gameObject != player) {
			std::cout << "Collision detected!" << std::endl;
			player->resolveCollision(*gameObject);
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
	window->setView(window->getDefaultView());
	if (parallax) {
		parallax->render(*window, *camera);
	}
	
	camera->setCamera(window);

	for (auto gO : gameObject) {
		gO->render(window);
	}

	for (auto gOC : gameObjectCollider) {
		gOC->render(window);
	}

	if (player) {
		player->render(window);
	}
}

Game::~Game() {
	delete player;
	player = nullptr;
	delete parallax;
	parallax = nullptr;
}