#pragma once
#include "GameState.h"
#include "Player.h"
#include "Camera.h"
#include "LoadLevel.h"
#include "Textures.h"
#include "SlimePiece.h"

class MainMenu;
class PauseMenu;

class Game : public GameState
{ 
private:
	LoadLevel* myLevel;
	Camera* camera;
	Player* player;
	std::vector<GameObject*> gameObject;
	std::vector<GameObject*> gameObjectCollider;
	bool gOBuild;

public:
	Game() = default;
	Game(sf::RenderWindow * window, std::vector<GameState*>* states);
	~Game();
		
	static void Instance(sf::RenderWindow* window, std::vector<GameState*>*& states);

	void setEntity();
	void updateCollision();

	virtual void manageState() override;
	virtual void update(float& dt) override;
	virtual void render() override;
};

