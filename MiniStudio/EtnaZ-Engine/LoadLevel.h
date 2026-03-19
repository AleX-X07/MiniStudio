#pragma once
#include <vector>
#include <iostream>
#include "Globals.h"
#include "GameObject.h"
#include "Textures.h"
#include "Tile.h"
#include "Seed.h"
#include "Orb.h"
#include "PressurePlate.h"
#include "Door.h"
#include "Spike.h"
#include "Crate.h"
#include "Ventilation.h"

class LoadLevel{

private:
	sf::Texture tileSet;
	int tileCol;
	int tileRow;

public:
	vector<GameObject*> Platform;
	vector<Tile*> tiles;
	vector<Seed*> Seeds;
	vector<Orb*> Orbs;
	vector<Pressureplate*> Pressureplates;
	vector<Door*> Doors;
	vector<Spike*> Spikes;
	vector<Crate*> Crates;
	vector<Ventilation*> Ventilations;


	LoadLevel();
	~LoadLevel();

	bool loadLevel();

	void render(sf::RenderWindow* window);

};

