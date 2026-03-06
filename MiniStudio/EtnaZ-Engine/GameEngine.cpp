#include "GameEngine.h"

GameEngine::GameEngine() {
	window = new RenderWindow(VideoMode({ win_width, win_heigt }), "EtnaZ-Engine");
	dt = 0;
	states = new vector<GameState*>;
	input = new Input();
	clock.restart();

	currentInputKey = nullptr;
	currentInputMouse = nullptr;
}

GameEngine::~GameEngine() {
	delete window;
	window = nullptr;
}

void GameEngine::updateEvent() {

	/*currentInputKey = nullptr;
	currentInputMouse = nullptr;*/

	/*while (const optional event = window->pollEvent()) {
		if (event->is<Event::Closed>()) {
			window->close();
		}

		if (currentInputKey = event->getIf<sf::Event::KeyPressed>()) {
			input->setInputKey(currentInputKey);
		}
		if (currentInputMouse = event->getIf<sf::Event::MouseButtonPressed>()) {
			input->setInputMouse(currentInputMouse);
		}
	}

	if (input->currentInputKey) {
		if (input->currentInputKey->scancode == Keyboard::Scancode::D) {
			cout << "rohjapjth";
		}
	}*/

}

void GameEngine::updateDt() {
	Time elapsed = clock.getElapsedTime();
	clock.restart();
	dt = elapsed.asSeconds();
}

void GameEngine::update() {
	if (!states->empty()) {
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

	MainMenu::Instance(window, states);

	while (window->isOpen()) {
		updateEvent();
		updateDt();
		update();
		render();
		window->clear();
		window->display();
	}
}