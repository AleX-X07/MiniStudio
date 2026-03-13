#include "Game.h"
#include "MainMenu.h"
#include "GameObject.h"


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

		//Player
		player = new Player(900, 750);
		player->setColor(Color::Red);

		//Camera
		camera = new Camera(0.01);

		gOBuild = true;
	}
}

void Game::updateCollision() 
{
	if (!player) return;

	for (auto& gameObject : gameObject)
	{
		if (gameObject->visibility && player->isColliding(*gameObject) && gameObject != player) 
		{
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
	
	camera->setCamera(window);

	for (auto gO : gameObject) {
		gO->render(window);
	}

	if (player) {
		player->render(window);
	}
}

Game::~Game() {
	delete player;
	player = nullptr;
}