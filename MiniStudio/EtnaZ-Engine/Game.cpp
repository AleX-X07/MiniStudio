#include "Game.h"
#include "MainMenu.h"

Game::Game(RenderWindow* window, vector<GameState*>* _states) : GameState(window, _states) {

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

}

void Game::render() {
	cout << "Game" << endl;
}