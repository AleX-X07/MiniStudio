#pragma once
#include "GameObject.h"

class Tile : public GameObject{
public:
	//Variable
	int tileId;
	sf::IntRect tileRect;

public:
	//Constructor/Destructor
	Tile(int id, float x, float y, float tileSize, sf::Texture* _rect );
	~Tile();

	//Method set
	void setTileRect(sf::IntRect _rect);



};

