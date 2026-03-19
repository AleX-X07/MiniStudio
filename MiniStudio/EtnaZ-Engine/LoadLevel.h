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
#include "SlimePiece.h"

class LoadLevel{

private:
	sf::Texture tileSet;
	int tileCol;
	int tileRow;

public:
	std::vector<GameObject*> Platform;
	std::vector<Tile*> tiles;
	std::vector<Seed*> Seeds;
	std::vector<Orb*> Orbs;
	std::vector<Pressureplate*> Pressureplates;
	std::vector<Door*> Doors;
	std::vector<Spike*> Spikes;
	std::vector<Crate*> Crates;
	std::vector<Ventilation*> Ventilations;
	std::vector<SlimePiece*> Slime;


	LoadLevel();
	~LoadLevel();

	bool loadLevel();

	void render(sf::RenderWindow* window);

};

