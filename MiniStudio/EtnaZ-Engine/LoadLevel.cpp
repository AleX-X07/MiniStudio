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

	for (auto& seed : Seeds) {
		delete seed;
		seed = nullptr;
	}

	for (auto& orb : Orbs) {
		delete orb;
		orb = nullptr;
	}

	for (auto& pressurePlate : Pressureplates) {
		delete pressurePlate;
		pressurePlate = nullptr;
	}

	for (auto& door : Doors) {
		delete door;
		door = nullptr;
	}	

	for (auto& spike : Spikes) {
		delete spike;
		spike = nullptr;
	}

	for (auto& crate : Crates) {
		delete crate;
		crate = nullptr;
	}

	for (auto& ventilation : Ventilations) {
		delete ventilation;
		ventilation = nullptr;
	}


	/*for (auto& slime : Slimes) {
		delete slime;
		slime = nullptr;
	}*/
}

bool LoadLevel::loadLevel(){
	std::ifstream file("Room_1.txt");
	tileSet.loadFromFile("tileset.png");

	std::string line;
	std::string section;

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
		if (line == "SEED") {
			section = "SEED";
			continue;
		}
		if (line == "ORB") {
			section = "ORB";
			continue;
		}
		if (line == "SLIME") {
			section = "SLIME";
			continue;
		}
		if (line == "PRESSURE_PLATE") {
			section = "PRESSURE_PLATE";
			continue;
		}
		if (line == "DOOR") {
			section = "DOOR";
			continue;
		}
		if (line == "SPIKE") {
			section = "SPIKE";
			continue;
		}
		if (line == "CRATE") {
			section = "CRATE";
			continue;
		}
		if (line == "VENTILATION") {
			section = "VENTILATION";
			continue;
		}

		


		std::istringstream iss(line);

		if (section == "PLATFORM") {
			float x, y, w, h;
			iss >> x >> y >> w >> h;
			GameObject* myPlatform = new GameObject(x, y, w, h);
			Platform.push_back(myPlatform);
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
				while (row >> tileId) {
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
		else if (section == "SEED") {
			float x, y, w, h;
			iss >> x >> y >> w >> h;
			Seed* mySeed = new Seed(x, y, w, h);
			Seeds.push_back(mySeed);
		}
		else if (section == "ORB") {
			float x, y, w, h;
			iss >> x >> y >> w >> h;
			Orb* myOrb = new Orb(x, y, w, h);
			Orbs.push_back(myOrb);
		}
		else if (section == "SLIME") {
			float x, y, w, h;
			iss >> x >> y >> w >> h;
			//Slimes.push_back(new Slime(x, y, w, h));
		}
		else if (section == "PRESSURE_PLATE") {
			//
		}
		else if (section == "DOOR") {
			float x, y, w, h;
			iss >> x >> y >> w >> h;
			Doors.push_back(new Door(x, y, w, h));
		}
		else if (section == "SPIKE") {
			float x, y, w, h;
			iss >> x >> y >> w >> h;
			Spikes.push_back(new Spike(x, y, w, h));
		}
		else if (section == "CRATE") {
			float x, y, w, h;
			iss >> x >> y >> w >> h;
			Crates.push_back(new Crate(x, y, w, h));
		}
		else if (section == "VENTILATION") {
			float x, y, w, h;
			iss >> x >> y >> w >> h;
			Ventilations.push_back(new Ventilation(x, y, w, h));
		}
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

	for (auto& pressureplate : Pressureplates) {
		pressureplate->render(window);
	}

	for (auto& door : Doors) {
		door->render(window);
	}

	for (auto& spike : Spikes) {
		spike->render(window);
	}

	for (auto& crate : Crates) {
		crate->render(window);
	}

	for (auto& ventilation : Ventilations) {
		ventilation->render(window);
	}
	 
}
