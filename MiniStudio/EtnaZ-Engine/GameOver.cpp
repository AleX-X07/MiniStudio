#include "GameOver.h"

GameOver::GameOver(sf::RenderWindow* window, std::vector<GameState*>* states, Camera* _camera) : GameState(window, states){
	camera = _camera;
	backgroundTransparent = new GameObject(0, 0, 1920, 1080);
	backgroundTransparent->setColor({ 0,0,0,150 });
	background = new GameObject(0, 0, 1527, 1080);
	background->setTexture(&Textures::getMyTextures()->getTexture(Textures::texturesIndices::backgroundGameOver));
	setButton();
}

GameOver::~GameOver() {

}

void GameOver::Instance(sf::RenderWindow* window, std::vector<GameState*>*& states, Camera* camera) {
	GameState* gameOver = new GameOver(window, states, camera);
	states->push_back(gameOver);
}

void GameOver::setButton() {
	menu = new Button(220, 650, 380, 120, states, window);
	quit = new Button(260, 825, 335, 100, states, window);

	menu->setTexture((&Textures::getMyTextures()->getTexture(Textures::texturesIndices::buttonMenu)));
	quit->setTexture(&Textures::getMyTextures()->getTexture(Textures::texturesIndices::buttonQuit));
}

void GameOver::manageState() {
	if (menu->isClicked(input)) {
		GameState::resume();
		GameState::nextState(states);
		MainMenu::Instance(window, states);
	}
	if (quit->isClicked(input)) {
		window->close();
	}
}

void GameOver::update(float& dt) {

}

void GameOver::render() {
	camera->camHUD(window);
	backgroundTransparent->render(window);
	background->render(window);
	menu->render(window);
	quit->render(window);
}




