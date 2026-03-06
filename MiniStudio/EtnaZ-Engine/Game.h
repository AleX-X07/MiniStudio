#pragma once
#include "GameState.h"

class MainMenu;

class Game : public GameState
{
private:

public:
	Game() = default;
	Game(RenderWindow * window, vector<GameState*>* states);
	~Game() = default;
		
	static void Instance(RenderWindow* window, vector<GameState*>*& states);

	virtual void manageState() override;
	virtual void update(float& dt) override;
	virtual void render() override;
};

