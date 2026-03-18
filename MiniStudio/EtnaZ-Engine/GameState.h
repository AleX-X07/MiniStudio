#pragma once
#include <vector>
#include <iostream>

#include "Globals.h"
#include "Input.h"

class GameState
{
protected:
	sf::RenderWindow* window;
	std::vector<sf::Texture*> textures;
	std::vector<GameState*>* states;
	Input input;

public:
	GameState() = default;
	GameState(sf::RenderWindow* window, std::vector<GameState*>* states);
	virtual ~GameState() = default;

	void nextState(std::vector<GameState*>* states);

	void setInput(Input &input);

	virtual void manageState() = 0;
	virtual void update(float& dt) = 0;
	virtual void render() = 0;
};


