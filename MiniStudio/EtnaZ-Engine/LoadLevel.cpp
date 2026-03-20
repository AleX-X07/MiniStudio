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
	Platform.clear();

	for (auto& tile : tiles) {
		delete tile;
		tile = nullptr;
	}
	tiles.clear();

	for (auto& seed : Seeds) {
		delete seed;
		seed = nullptr;
	}
	Seeds.clear();

	for (auto& orb : Orbs) {
		delete orb;
		orb = nullptr;
	}
	Orbs.clear();

	for (auto& pressurePlate : Pressureplates) {
		delete pressurePlate;
		pressurePlate = nullptr;
	}
	Pressureplates.clear();


	for (auto& door : Doors) {
		delete door;
		door = nullptr;
	}	
	Doors.clear();

	for (auto& spike : Spikes) {
		delete spike;
		spike = nullptr;
	}
	Spikes.clear();

	for (auto& crate : Crates) {
		delete crate;
		crate = nullptr;
	}
	Crates.clear();

	for (auto& ventilation : Ventilations) {
		delete ventilation;
		ventilation = nullptr;
	}
	Ventilations.clear();

	for (auto& slime : Slime) {
		delete slime;
		slime = nullptr;
	}
	Slime.clear();
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
				std::istringstream row(line);
				int tileId = 0;
				int column = 0;
				while (row >> tileId) {
					if (tileId != 0) {
						if (tilesetColumns != 0) {
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
			SlimePiece* mySP = new SlimePiece(x, y, w, h);
			Slime.push_back(mySP);

		}
		else if (section == "PRESSURE_PLATE") {
			float x, y, w, h;
			std::string typeStr;
			iss >> x >> y >> w >> h >> typeStr;
			Pressureplate* myPp = new Pressureplate(x, y, w, h);

			if (typeStr == "block") { 
				myPp->currentType = Pressureplate::typePuzzle::block; 
			}
			else if (typeStr == "slime") {
				myPp->currentType = Pressureplate::typePuzzle::slime;
			}
			else {
				myPp->currentType = Pressureplate::typePuzzle::player;
			}
			Pressureplates.push_back(myPp);
		}
		else if (section == "DOOR") {
			float x, y, w, h;
			std::string typeStr;
			iss >> x >> y >> w >> h >> typeStr;

			Door* myDoor = new Door(x, y, w, h);

			if (typeStr == "block") {
				myDoor->currentType = Door::doorType::block;
			}
			else if (typeStr == "slime") {
				myDoor->currentType = Door::doorType::slime;
			}
			else {
				myDoor->currentType = Door::doorType::player;
			}

			Doors.push_back(myDoor);
		}
		else if (section == "SPIKE") {
			float x, y, w, h;
			iss >> x >> y >> w >> h;
			Spike* mySpike = new Spike(x, y, w, h);
			Spikes.push_back(mySpike);
		}
		else if (section == "CRATE") {
			float x, y, w, h;
			iss >> x >> y >> w >> h;
			Crate* myCrate = new Crate(x, y, w, h);
			Crates.push_back(myCrate);
		}
		else if (section == "VENTILATION") {
			float x, y, w, h;
			iss >> x >> y >> w >> h;
			Ventilation* myVent = new Ventilation(x, y, w, h);
			Ventilations.push_back(myVent);
		}
	}

	for (auto& pp : Pressureplates) {
		for (auto& door : Doors) {

			bool match = false;
			if (pp->currentType == Pressureplate::typePuzzle::player && door->currentType == Door::doorType::player) {
				match = true;
			}
			if (pp->currentType == Pressureplate::typePuzzle::block && door->currentType == Door::doorType::block) {
				match = true;
			}
			if (pp->currentType == Pressureplate::typePuzzle::slime && door->currentType == Door::doorType::slime) {
				match = true;
			}

			if (match && pp->linkedDoor == nullptr) {
				pp->linkedDoor = door;
				break;
			}
		}
	}

	return true;
}

void LoadLevel::render(sf::RenderWindow* window){

	for (auto& tile : tiles) {
		tile->render(window);
	}

	for (auto& seed : Seeds) {
		seed->setTexture(&Textures::getMyTextures()->getTexture(Textures::texturesIndices::seed));
		seed->render(window);
	}

	for (auto& orb : Orbs) {
		orb->setTexture(&Textures::getMyTextures()->getTexture(Textures::texturesIndices::orb));
		orb->render(window);
	}

	for (auto& door : Doors) {
		door->setTexture(&Textures::getMyTextures()->getTexture(Textures::texturesIndices::door));
		door->render(window);
	}

	for (auto& crate : Crates) {
		crate->setTexture(&Textures::getMyTextures()->getTexture(Textures::texturesIndices::crate));
		crate->render(window);
	}
}
