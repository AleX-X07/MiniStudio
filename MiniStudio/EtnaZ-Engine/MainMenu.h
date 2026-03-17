#pragma once
#include "GameState.h"
#include "GameObject.h"
#include "Textures.h"

class Button;
class Game;

class MainMenu : public GameState
{
private:
	GameObject* background;
	Button* play;
	Button* quit;
	bool created;

public:
	MainMenu() = default;
	MainMenu(RenderWindow* window, std::vector<GameState*>* states);
	~MainMenu();

	static void Instance(RenderWindow* window, std::vector<GameState*>*& states);

	void setButton();

	virtual void manageState() override;
	virtual void update(float& dt) override;
	virtual void render() override;
};

