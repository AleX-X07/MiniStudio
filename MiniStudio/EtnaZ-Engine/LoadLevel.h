#pragma once
#include <vector>
#include <iostream>
#include "Globals.h"
#include "GameObject.h"
#include "Textures.h"

using namespace std;

class LoadLevel{

private:
	vector<GameObject*>Platform;
	vector<GameObject*>Object;

public:

	LoadLevel();
	~LoadLevel();

	bool loadLevel();

	void render(sf::RenderWindow& window);

};

