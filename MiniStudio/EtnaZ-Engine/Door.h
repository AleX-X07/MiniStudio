#pragma once
#include "GameObject.h"


class Door : public GameObject
{
private:
	bool open;

public:
	enum class doorType {
		player,
		block,
		slime
	};

	doorType currentType;
public:
	Door(float x, float y, float w, float h);
	~Door();

	bool isOpen();
	void openDoor();

	void render(sf::RenderWindow* window) override;
};
