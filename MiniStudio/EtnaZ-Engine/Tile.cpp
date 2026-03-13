#include "Tile.h"



Tile::Tile(int id, float x, float y, float tileSize, sf::Texture* _rect) : GameObject(x, y, tileSize, tileSize) {
	tileId = id;
	tex = _rect;
	rect.setTexture(tex);
}


Tile::~Tile() {
	tex = nullptr;
}


void Tile::setTileRect(sf::IntRect _rect) {
	tileRect = _rect;
	rect.setTextureRect(tileRect);

}



