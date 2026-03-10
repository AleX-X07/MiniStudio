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
			string path;
			iss >> x >> y >> w >> h >> path;
			Platform.push_back(new GameObject(x, y, w, h));

			//platform.pushback(new Platforme (...);
		}
		else if (section == "OBJECT") {
			float x, y, w, h;
			string path;
			iss >> x >> y >> w >> h >> path;
			//platform.pushback(new Platforme (...);
		}
			
			
	}




	return false;
}

void LoadLevel::render(sf::RenderWindow& window)
{
}
