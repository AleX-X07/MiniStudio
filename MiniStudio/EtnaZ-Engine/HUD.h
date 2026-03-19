#pragma once
class HUD {
private:

public:
	HUD();
	~HUD() = default;

	void update(float& dt);
	void render(sf::RenderWindow* window);
};

