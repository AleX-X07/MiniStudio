#include "MainMenu.h"
#include "Game.h"

MainMenu::MainMenu(RenderWindow* window, vector<GameState*>* _states) : GameState(window, _states) {

}

void MainMenu::Instance(RenderWindow* window, vector<GameState*>*& states) {
	GameState* mainMenu = new MainMenu(window, states);
	states->push_back(mainMenu);
}

void MainMenu::manageState() {
	if (Keyboard::isKeyPressed(Keyboard::Key::D)) {
		GameState::nextState(states);
		Game::Instance(window, states);
	}
}

void MainMenu::update(float& dt) {
	

}

void MainMenu::render() {
	cout << "Menu" << endl;
}