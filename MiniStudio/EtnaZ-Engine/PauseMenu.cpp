#include "PauseMenu.h"

PauseMenu::PauseMenu(sf::RenderWindow* window, std::vector<GameState*>* states, Camera* _camera) : GameState(window, states){
	camera = _camera;
	background = new GameObject(0,0,win_width,win_height);
	background->setColor({0,0,0,150});
	//background->setColor(sf::Color::Red);
	setButton();
}

PauseMenu::~PauseMenu(){

}

void PauseMenu::Instance(sf::RenderWindow* window, std::vector<GameState*>*& states, Camera* camera) {
	GameState* pauseMenu = new PauseMenu(window, states, camera);
	states->push_back(pauseMenu);
}

void PauseMenu::setButton() {
	resume = new Button(760, 375, 400, 150, states, window);
	menu = new Button(780, 525,380,120,states, window);
	quit = new Button(800, 650, 335, 100, states, window);

	resume->setTexture((&Textures::getMyTextures()->getTexture(Textures::texturesIndices::buttonResume)));
	menu->setTexture((&Textures::getMyTextures()->getTexture(Textures::texturesIndices::buttonMenu)));
	quit->setTexture(&Textures::getMyTextures()->getTexture(Textures::texturesIndices::buttonQuit));
}

void PauseMenu::manageState() {
	if (resume->isClicked(input)) {
		GameState::resume();
	}
	if (menu->isClicked(input)) {
		GameState::resume();
		GameState::nextState(states);
		MainMenu::Instance(window, states);
	}
	if (quit->isClicked(input)) {
		window->close();
	}
}

void PauseMenu::update(float& dt) {

}

void PauseMenu::render() {
	camera->camHUD(window);
	background->render(window);
	resume->render(window);
	menu->render(window);
	quit->render(window);
}



