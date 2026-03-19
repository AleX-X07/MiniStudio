#pragma once
#include <SFML/Audio/Music.hpp>

#include "GameState.h"
#include "GameObject.h"
#include "Textures.h"

class Button;
class Game;

class MainMenu : public GameState
{
private:
	GameObject* background;
	GameObject* title;
	Button* play;
	Button* quit;
	
	sf::Music music;

public:
	MainMenu() = default;
	MainMenu(sf::RenderWindow* window, std::vector<GameState*>* states);
	virtual ~MainMenu() override;

	static void Instance(sf::RenderWindow* window, std::vector<GameState*>*& states);

	void setButton();

	virtual void manageState() override;
	virtual void update(float& dt) override;
	virtual void render() override;
};

