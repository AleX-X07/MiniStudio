#pragma once
#include <vector>
#include <iostream>
#include "Globals.h"
#include "GameObject.h"
#include "Textures.h"
#include "Tile.h"

using namespace std;

class LoadLevel{

private:
	sf::Texture tileSet;
	

public:
	vector<GameObject*>Platform;
	vector<Tile*>tiles;

	LoadLevel();
	~LoadLevel();

	bool loadLevel();

	void render(sf::RenderWindow& window);

};

