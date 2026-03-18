#include "GameEngine.h"

GameEngine::GameEngine() {
	window = new sf::RenderWindow(sf::VideoMode({ win_width, win_height }), "EtnaZ-Engine", sf::Style::Default, sf::State::Fullscreen);
	dt = 0;
	states = new std::vector<GameState*>;
	input = Input();
	clock.restart();

	currentInputKey = nullptr;
	currentInputMouse = nullptr;
}

GameEngine::~GameEngine() {
	delete window;
	window = nullptr;
}

void GameEngine::updateEvent() {
	input.reset();
	while (const std::optional event = window->pollEvent()) {
		if (event->is<sf::Event::Closed>()) {
			window->close();
		}
		input.setEvent(event.value());
	}
}

void GameEngine::updateDt() {
	sf::Time elapsed = clock.getElapsedTime();
	clock.restart();
	dt = elapsed.asSeconds();
}

void GameEngine::update() {
	if (!states->empty()) {
		states->back()->setInput(input);
		states->back()->manageState();
		states->back()->update(dt);
	}
}

void GameEngine::render() {
	if (!states->empty()) {
		states->back()->render();
	}
}

void GameEngine::run() {

	Textures::getMyTextures();

	MainMenu::Instance(window, states);

	while (window->isOpen()) {
		updateEvent();
		updateDt();
		update();
		window->clear();
		render();
		window->display();
	}
}