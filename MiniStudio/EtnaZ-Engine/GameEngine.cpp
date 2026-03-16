#include "GameEngine.h"

GameEngine::GameEngine() {
	window = new RenderWindow(VideoMode({ win_width, win_height }), "EtnaZ-Engine");
	dt = 0;
	states = new vector<GameState*>;
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
	while (const optional event = window->pollEvent()) {
		if (event->is<Event::Closed>()) {
			window->close();
		}
		input.setEvent(event.value());
		if (input.quit) {
			window->close();
		}
	}
}

void GameEngine::updateDt() {
	Time elapsed = clock.getElapsedTime();
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

	Textures::getMyTextures()->loadAllTexture();

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