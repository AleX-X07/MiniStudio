#pragma once
#include "Camera.h"
#include "Textures.h"
#include <vector>

class Camera;

struct ParallaxLayer {
    Textures::texturesIndices textureIndex;
    float speed;
};

class Parallax {
private:
    std::vector<ParallaxLayer> layers;

public:
    Parallax();
    ~Parallax();

    void addLayer(Textures::texturesIndices textureIndex, float speed);
    void render(sf::RenderWindow& window, const Camera& camera);
};