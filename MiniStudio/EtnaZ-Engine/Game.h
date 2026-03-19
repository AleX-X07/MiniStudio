#pragma once
#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"
#include "GameState.h"
#include "Player.h"
#include "Camera.h"
#include "LoadLevel.h"
#include "Textures.h"
#include "SlimePiece.h"
#include "Parallax.h"
#include "GameOver.h"

class MainMenu;
class PauseMenu;

class Game : public GameState
{ 
private:
	LoadLevel* myLevel;
	
	Camera* camera;
	Player* player;
	Parallax* parallax;
	std::vector<GameObject*> gameObject;
	std::vector<GameObject*> gameObjectCollider;

	bool gOBuild;

	sf::Music music;

public:
	Game() = default;
	Game(sf::RenderWindow * window, std::vector<GameState*>* states);
	virtual ~Game() override;
		
	static void Instance(sf::RenderWindow* window, std::vector<GameState*>*& states);

	void setEntity();
	void updateCollision();

	virtual void onResume() override;
	virtual void manageState() override;
	virtual void update(float& dt) override;
	virtual void render() override;
};

