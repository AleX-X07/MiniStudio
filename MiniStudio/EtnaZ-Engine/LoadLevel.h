#pragma once
#include <vector>
#include <iostream>
#include "Globals.h"



using namespace std;

class LoadLevel
{

private:
	//vector platform * platform
	//vector objects * object
	

public:

	LoadLevel();
	~LoadLevel();

	bool loadLevel();

	void render(sf::RenderWindow& window);

};

