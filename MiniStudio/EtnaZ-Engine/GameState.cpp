#include "GameState.h"

#include "GameEngine.h"

GameState::GameState(sf::RenderWindow* window, std::vector<GameState*>* _states) : window(window), states(_states) {

}

void GameState::nextState(std::vector<GameState*>* states) {
	if (!states->empty()) {
		states->pop_back();
	}
}

void GameState::pause(std::vector<GameState*>* states) {
	if (!states->empty()) {
		GameEngine::statesPause.push_back(states->back());
		states->pop_back();
	}
}

void GameState::resume(){
	if (!states->empty()) {
		states->pop_back();
		states->push_back(GameEngine::statesPause.back());
		states->back()->onResume();
		GameEngine::statesPause.pop_back();
	}
}

void GameState::setInput(Input &_input) {
	input = _input;
}

void GameState::onResume(){

}
