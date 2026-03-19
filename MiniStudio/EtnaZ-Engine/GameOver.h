#pragma once
#include "GameState.h"
#include "Button.h"

class GameOver : public GameState {
private:
	GameObject* backgroundTransparent;
	GameObject* background;
	Button* menu;
	Button* quit;
	Camera* camera;
public:
	GameOver() = default;
	GameOver(sf::RenderWindow* window, std::vector<GameState*>* states, Camera* camera);
	~GameOver();

	static void Instance(sf::RenderWindow* window, std::vector<GameState*>*& states, Camera* camera);

	void setButton();

	virtual void manageState() override;
	virtual void update(float& dt) override;
	virtual void render() override;
};

