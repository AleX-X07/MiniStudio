#pragma once
#include <SFML/Graphics.hpp>

#include "MainMenu.h"
#include "Game.h"
#include "GameState.h"
#include "GameObject.h"

class Button : public GameObject {

private:
	bool clicked;
	sf::Vector2i mousePos;
	std::vector<GameState*>* states;
	sf::RenderWindow* window;

public:
	Button() = default;
	Button(float x, float y, float w, float h, std::vector<GameState*>* states, sf::RenderWindow* window);
	virtual ~Button() override = default;

	virtual void update(float& dt, Input& input) override;
	virtual void render(sf::RenderWindow* window) override;

	bool isClicked(Input& input);
};

