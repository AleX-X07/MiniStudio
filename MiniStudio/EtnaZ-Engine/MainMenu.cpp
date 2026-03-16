#include "MainMenu.h"
#include "Game.h"
#include "Button.h"

MainMenu::MainMenu(RenderWindow* window, vector<GameState*>* _states) : GameState(window, _states) {
	background = new GameObject(200,0,1529,1080);
	background->setTexture(&Textures::getMyTextures()->getTexture(Textures::texturesIndices::backgroundMenu));

	created = false;
}

void MainMenu::Instance(RenderWindow* window, vector<GameState*>*& states) {
	GameState* mainMenu = new MainMenu(window, states);
	states->push_back(mainMenu);
}

void MainMenu::setButton(){
	Button* play = new Button(800,375, 400, 150, states, window);
	Button* quit = new Button(1000, 495, 350, 100, states, window);

	play->setTexture((&Textures::getMyTextures()->getTexture(Textures::texturesIndices::buttonPlay)));
	quit->setTexture(&Textures::getMyTextures()->getTexture(Textures::texturesIndices::buttonQuit));

	myButton.push_back(play);
	myButton.push_back(quit);
}

void MainMenu::manageState() {
	
}

void MainMenu::update(float& dt) {
	if (!created) {
		setButton();
		created = true;
	}
	for (auto& mB : myButton) {
		mB->update(dt, input);
	}
}

void MainMenu::render() {
	background->render(window);
	for (auto& mB : myButton) {
		mB->render(window);
	}
}