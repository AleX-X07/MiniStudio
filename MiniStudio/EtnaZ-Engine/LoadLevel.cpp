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

		if (line == "PLATFORM") {
			section = "PLATFORM";
			continue;
		}
		if (line == "TILES") {
			section = "TILES";
			continue;
		}
		if (line == "SEEDS") {
			section = "SEEDS";
			continue;
		}
		if (line == "ORBS") {
			section = "ORBS";
			continue;
		}


		istringstream iss(line);

		if (section == "PLATFORM") {
			float x, y, w, h;
			iss >> x >> y >> w >> h;
			GameObject* myPlaftform = new GameObject(x, y, w, h);
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
						if (!(tilesetColumns == 0)) {
							tileCol = (tileId - 1) % tilesetColumns;
							tileRow = (tileId - 1) / tilesetColumns;
						}
						else {
							tileCol = (tileId - 1);
							tileRow = (tileId - 1);
						}
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
		/*else if (section == "SEEDS") {
			float x, y, w, h;
			iss >> x >> y >> w >> h;
			Seed* mySeed = new Seed(x, y, w, h);
			Seeds.push_back(mySeed);
		}
		else if (section == "ORBS") {
			float x, y, w, h;
			iss >> x >> y >> w >> h;
			Orb* myOrb = new Orb(x, y, w, h);
			Orbs.push_back(myOrb);
		}*/
			
	}

	return true;
}

void LoadLevel::render(sf::RenderWindow* window)
{
	for (auto& platform : Platform) {
		platform->render(window);
	}

	for (auto& tile : tiles) {
		tile->render(window);
	}

	for (auto& seed : Seeds) {
		seed->render(window);
	}

	for (auto& orb : Orbs) {
		orb->render(window);
	}
}
