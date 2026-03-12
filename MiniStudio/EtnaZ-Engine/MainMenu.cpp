#include "MainMenu.h"
#include "Game.h"
#include "Button.h"


MainMenu::MainMenu(RenderWindow* window, vector<GameState*>* _states) : GameState(window, _states) {
	sf::Font& font = Textures::getMyTextures()->getFont(Textures::fontsIndices::FontTest);
	
	buttonPlay = new Button();

	buttonPlay->setFillColor({ 100,0,50,255 });
	buttonPlay->setSize(Vector2f(400, 80));
	buttonPlay->setPosition(Vector2f(775, 200));

	buttonQuit = new Button();

	buttonQuit->setFillColor({ 200,180,90,255 });
	buttonQuit->setSize(Vector2f(400, 80));
	buttonQuit->setPosition(Vector2f(775, 450));

	textPlay = new TextButton();

	textPlay->setFillColor(Color::White);
	textPlay->setCharacterSize(unsigned int(35));
	textPlay->setPosition(Vector2f(775, 200));
	textPlay->setFont(font);
	textPlay->setString("Play");

	textQuit = new TextButton();

	textQuit->setFillColor(Color::White);
	textQuit->setCharacterSize(unsigned int(35));
	textQuit->setPosition(Vector2f(775, 450));
	textQuit->setFont(font);
	textQuit->setString("Quit");
}

void MainMenu::Instance(RenderWindow* window, vector<GameState*>*& states) {
	GameState* mainMenu = new MainMenu(window, states);
	states->push_back(mainMenu);
}

void MainMenu::manageState() {
	if (Mouse::isButtonPressed(Mouse::Button::Left)) {
		Vector2i mousePos = Mouse::getPosition(*window);
		Vector2f mousePosF(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y));
		if (buttonPlay && buttonPlay->getGlobalBounds().contains(mousePosF)) {
			cout << "Play" << endl;
			GameState::nextState(states);
			Game::Instance(window, states);
			cout << "Game" << endl;
		}
		if (buttonQuit && buttonQuit->getGlobalBounds().contains(mousePosF)) {
			cout << "Quit" << endl;
			window->close();
		}
	}
}

void MainMenu::update(float& dt) {
	if (buttonPlay) {
		buttonPlay->update(dt);
	}

	if (buttonQuit) {
		buttonQuit->update(dt);
	}
}

void MainMenu::render() {
	if (buttonPlay) {
		buttonPlay->render(window);
	}

	if (buttonQuit) {
		buttonQuit->render(window);
	}

	if (textPlay) {
		textPlay->render(window);
	}

	if (textQuit) {
		textQuit->render(window);
	}
}

MainMenu::~MainMenu(){
	delete buttonPlay;
	delete buttonQuit;
	delete textPlay;
	delete textQuit;
}