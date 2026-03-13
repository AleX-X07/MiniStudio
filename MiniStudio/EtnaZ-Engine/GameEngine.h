#pragma once
#include <iostream>

#include "Globals.h"
#include "Input.h"

#include "GameState.h"
#include "MainMenu.h"
#include "Textures.h"

using namespace std;

class GameEngine
{
private:
	RenderWindow* window;
	float dt;
	vector<GameState*>* states;
	Input* input;
	Clock clock;

	const Event::KeyPressed* currentInputKey;
	const Event::MouseButtonPressed* currentInputMouse;

public:
	GameEngine();
	~GameEngine();

	void updateEvent();
	void updateDt();
	void update();
	void render();
	void run();
};

