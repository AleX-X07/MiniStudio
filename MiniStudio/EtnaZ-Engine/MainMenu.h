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
	std::vector<GameObject*> myButton;
	bool created;

public:
	MainMenu() = default;
	MainMenu(RenderWindow* window, std::vector<GameState*>* states);
	~MainMenu() = default;

	static void Instance(RenderWindow* window, std::vector<GameState*>*& states);

	void setButton();

	virtual void manageState() override;
	virtual void update(float& dt) override;
	virtual void render() override;
};

