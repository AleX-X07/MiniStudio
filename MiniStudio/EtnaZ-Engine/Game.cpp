#include "Game.h"
#include "MainMenu.h"
#include "Player.h"


Game::Game(RenderWindow* window, vector<GameState*>* _states) : GameState(window, _states) {
	player = new Player(900,750);

	player->setColor({255,0,0,255});
	player->setSize(Vector2f(50.f, 50.f));

	camera = new Camera(0.005);

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

void Game::update(float& dt) {
	if (player) {
		player->update(dt, input);
		camera->updateCamera(player);
	}
}

void Game::render() {
	
	camera->setCamera(window);
	
	if (player) {
		player->render(window);
	}
}

Game::~Game() {
	delete player;
	player = nullptr;
}