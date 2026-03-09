#pragma once
#include "GameState.h"
#include "Player.h"


class MainMenu;

class Game : public GameState
{
private:
	Player* player;
public:
	Game() = default;
	Game(RenderWindow * window, vector<GameState*>* states);
	~Game();
		
	static void Instance(RenderWindow* window, vector<GameState*>*& states);

	virtual void manageState() override;
	virtual void update(float& dt) override;
	virtual void render() override;
};

