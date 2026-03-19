#pragma once
#include <iostream>
#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"

#include "Globals.h"
#include "Input.h"

#include "GameState.h"
#include "MainMenu.h"
#include "Textures.h"

class GameEngine
{
private:
	sf::RenderWindow* window;
	float dt;
	std::vector<GameState*>* states;
	Input input;
	sf::Clock clock;

	const sf::Event::KeyPressed* currentInputKey;
	const sf::Event::MouseButtonPressed* currentInputMouse;
public:
	static std::vector<GameState*> statesPause;

public:
	GameEngine();
	~GameEngine();

	void updateEvent();
	void updateDt();
	void update();
	void render();
	void run();
};

