#include "LoadLevel.h"
#include <sstream>
#include <string>
#include <fstream>

std::ifstream infile("thefile.txt");

LoadLevel::LoadLevel()
{
}

LoadLevel::~LoadLevel()
{
}

bool LoadLevel::loadLevel(){
	std::ifstream file("niveau.txt");

	string line;
	string section;

	while(getline(file, line)) {

		if (line == "PLATFORM") {
			section = "PLATFORM";
			continue;
		}
		if (line == "PLAYER") {
			section = "PLAYER";
			continue;
		}
		if (line == "OBJECT") {
			section = "OBJECT";
			continue;
		}

		istringstream iss(line);

		if (section == "PLATFORM") {
			float x, y, w, h;
			iss >> x >> y >> w >> h;
			GameObject* myPlaftform = new GameObject(x, y, w, h);
			myPlaftform->setTexture(&Textures::getMyTextures()->getTexture(Textures::texturesIndices::Platform));
			Platform.push_back(myPlaftform);

		}
		else if (section == "OBJECT") {
			float x, y, w, h;
			iss >> x >> y >> w >> h;
		}
			
			
	}




	return false;
}

void LoadLevel::render(sf::RenderWindow& window)
{
}
