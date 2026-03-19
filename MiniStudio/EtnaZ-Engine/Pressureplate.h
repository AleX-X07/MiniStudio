#pragma once
#include <iostream>
#include "GameObject.h"
#include "Player.h"
#include "Crate.h"
#include "Door.h"



class Pressureplate : public GameObject
{

private:
	bool activated;


public:

	enum class typePuzzle {
		player,
		block,
		slime
	};


	typePuzzle currentType;
	Door* linkedDoor = nullptr;

public:
	Pressureplate(float x, float y, float w, float h);
	~Pressureplate();

	bool isActivated();
	void activate(Player* player, std::vector<Crate*>& crates);

	void render(sf::RenderWindow* window) override;

};

