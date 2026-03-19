#include "MainMenu.h"
#include "Game.h"
#include "Button.h"

MainMenu::MainMenu(sf::RenderWindow* window, std::vector<GameState*>* _states) : GameState(window, _states) {
	background = new GameObject(200,0,1529,1080);
	background->setTexture(&Textures::getMyTextures()->getTexture(Textures::texturesIndices::backgroundMenu));
	title = new GameObject(509*1.25,0, 509*1.25, 360*1.25);
	title->setTexture(&Textures::getMyTextures()->getTexture(Textures::texturesIndices::title));
	music.openFromFile("assets/sound/dark-ambiance.ogg");
	music.setLooping(true);
	music.setVolume(50.f);
	music.play();
	setButton();
}

MainMenu::~MainMenu() {
	delete background;
	background = nullptr;
	
	delete play;
	play = nullptr;

	delete quit;
	quit = nullptr;

	delete title;
	title = nullptr;
}

void MainMenu::Instance(sf::RenderWindow* window, std::vector<GameState*>*& states) {
	GameState* mainMenu = new MainMenu(window, states);
	states->push_back(mainMenu);
}

void MainMenu::setButton(){
	play = new Button(800,375, 400, 150, states, window);
	quit = new Button(1000, 495, 350, 100, states, window);

	play->setTexture((&Textures::getMyTextures()->getTexture(Textures::texturesIndices::buttonPlay)));
	quit->setTexture(&Textures::getMyTextures()->getTexture(Textures::texturesIndices::buttonQuit));

}

void MainMenu::manageState() {
	if (play->isClicked(input)) {
		music.stop();
		GameState::nextState(states);
		Game::Instance(window, states);
	}
	else if (quit->isClicked(input)) {
		window->close();
	}
}

void MainMenu::update(float& dt) {
	
}

void MainMenu::render() {
	background->render(window);
	title->render(window);
	play->render(window);
	quit->render(window);
}