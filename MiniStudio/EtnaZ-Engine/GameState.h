#pragma once
#include <vector>
#include <iostream>

#include "Globals.h"
#include "Input.h"

using namespace std;

class GameState
{
protected:
	RenderWindow* window;
	vector<Texture*> textures;
	vector<GameState*>* states;
	Input input;

public:
	GameState() = default;
	GameState(RenderWindow* window, vector<GameState*>* states);
	virtual ~GameState() = default;

	void nextState(vector<GameState*>* states);
	void setInput(Input &input);

	virtual void manageState() = 0;
	virtual void update(float& dt) = 0;
	virtual void render() = 0;
};

