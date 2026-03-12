#include "LoadLevel.h"
#include <sstream>
#include <string>
#include <fstream>

LoadLevel::LoadLevel()
{
}

LoadLevel::~LoadLevel()
{
	for (auto& platform : Platform) {
		delete platform;
		platform = nullptr;
	}

	for (auto& tile : tiles) {
		delete tile;
		tile = nullptr;
	}
}

bool LoadLevel::loadLevel(){
	std::ifstream file("niveau.txt");
	tileSet.loadFromFile("tileset.png");

	string line;
	string section;

	while(getline(file, line)) {

		if (line.empty()) {
			continue;
		}

		if (line == "PLATFORM") {
			section = "PLATFORM";
			continue;
		}
		if (line == "TILES") {
			section = "TILES";
			continue;
		}

		istringstream iss(line);

		if (section == "PLATFORM") {
			float x, y, w, h;
			iss >> x >> y >> w >> h;
			GameObject* myPlaftform = new GameObject(x, y, w, h);
			//myPlaftform->setTexture(&Textures::getMyTextures()->getTexture(Textures::texturesIndices::Platform));
			Platform.push_back(myPlaftform);

		}
		else if (section == "TILES") {

			int mapWidth, mapHeight, tileSize;
			iss >> mapWidth >> mapHeight >> tileSize;

			int tilesetColumns = tileSet.getSize().x / tileSize;
			int currentRow = 0;

			while (getline(file, line)) {

				istringstream row(line);
				int tileId = 0;
				int column = 0;

				while(row >> tileId) {
					if (tileId != 0) {
						int tileCol = (tileId - 1) % tilesetColumns;
						int tileRow = (tileId - 1) / tilesetColumns;

						sf::IntRect tileRect({ tileCol * tileSize, tileRow * tileSize }, { tileSize, tileSize });
						Tile* tile = new Tile(tileId, column * tileSize, currentRow * tileSize, tileSize, &tileSet);
						tile->setTileRect(tileRect);
						tiles.push_back(tile);
					}
					column++;
				}
				currentRow++;

			}
		}
			
	}


	return true;
}

void LoadLevel::render(sf::RenderWindow& window)
{
	for (auto& platform : Platform) {
		platform->render(&window);
	}

	for (auto& tile : tiles) {
		tile->render(&window);
	}
}
