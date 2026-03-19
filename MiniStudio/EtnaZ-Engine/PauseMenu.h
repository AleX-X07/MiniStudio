#pragma once
#include "GameState.h"
#include "Button.h"

class PauseMenu : public GameState{
private:
	GameObject* background;
	Button* resume;
	Button* menu;
	Button* quit;

	sf::Vector2f center;

protected:
	Camera* camera;

public:
	PauseMenu() = default;
	PauseMenu(sf::RenderWindow* window, std::vector<GameState*>* states, Camera* camera);
	~PauseMenu();

	static void Instance(sf::RenderWindow* window, std::vector<GameState*>*& states, Camera* camera);

	void setButton();

	virtual void manageState() override;
	virtual void update(float& dt) override;
	virtual void render() override;
};