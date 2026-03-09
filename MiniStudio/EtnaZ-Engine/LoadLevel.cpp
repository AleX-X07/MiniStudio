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

	while(getline(file, line)) {
		//istringstream iss(line);

		
		


	}




	return false;
}

void LoadLevel::render(sf::RenderWindow& window)
{
}
