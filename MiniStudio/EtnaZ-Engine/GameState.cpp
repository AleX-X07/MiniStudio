#include "GameState.h"

GameState::GameState(sf::RenderWindow* window, std::vector<GameState*>* _states) : window(window), states(_states) {

}

void GameState::nextState(std::vector<GameState*>* states) {
	if (!states->empty()) {
		states->pop_back();
	}
}

void GameState::setInput(Input &_input) {
	input = _input;
}
