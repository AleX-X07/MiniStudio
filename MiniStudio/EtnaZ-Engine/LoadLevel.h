#pragma once
#include <vector>
#include <iostream>
#include "Globals.h"
#include "GameObject.h"
#include "Textures.h"
#include "Tile.h"

class LoadLevel{

private:
	sf::Texture tileSet;
	

public:
	std::vector<GameObject*> Platform;
	std::vector<Tile*> tiles;

	LoadLevel();
	~LoadLevel();

	bool loadLevel();

	void render(sf::RenderWindow* window);

};

