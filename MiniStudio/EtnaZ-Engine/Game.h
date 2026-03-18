#pragma once
#include "GameState.h"
#include "Player.h"
#include "Camera.h"
#include "LoadLevel.h"
#include "Textures.h"

class MainMenu;

class Game : public GameState
{ 
private:
	LoadLevel* myLevel;
	Camera* camera;
	Player* player;
	vector<GameObject*> gameObject;
	vector<GameObject*> gameObjectCollider;
	bool gOBuild;

public:
	Game() = default;
	Game(sf::RenderWindow * window, vector<GameState*>* states);
	~Game();
		
	static void Instance(sf::RenderWindow* window, vector<GameState*>*& states);

	void setEntity();
	void updateCollision();

	virtual void manageState() override;
	virtual void update(float& dt) override;
	virtual void render() override;
};

