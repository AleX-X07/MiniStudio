#pragma once
#include <vector>
#include <iostream>

#include "Globals.h"
#include "Input.h"

class GameState
{
protected:
	RenderWindow* window;
	std::vector<Texture*> textures;
	std::vector<GameState*>* states;
	Input input;

public:
	GameState() = default;
	GameState(RenderWindow* window, std::vector<GameState*>* states);
	virtual ~GameState() = default;

	static void nextState(std::vector<GameState*>* states);

	void setInput(Input &input);

	virtual void manageState() = 0;
	virtual void update(float& dt) = 0;
	virtual void render() = 0;
};


