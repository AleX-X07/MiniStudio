#pragma once
#include "GameState.h"
#include "Button.h"


class Game;

class MainMenu : public GameState
{
private:
	Button* buttonPlay;
	Button* buttonQuit;

public:
	MainMenu() = default;
	MainMenu(RenderWindow* window, vector<GameState*>* states);
	~MainMenu();

	static void Instance(RenderWindow* window, vector<GameState*>*& states);

	virtual void manageState() override;
	virtual void update(float& dt) override;
	virtual void render() override;
};

