#pragma once
#include "Camera.h"
#include "Player.h"
#include "Textures.h"
#include <vector>

class Camera;

struct ParallaxLayer {
    Textures::texturesIndices textureIndex;
    float speed;
};

class Parallax {
public:
    enum class zone {
        zone0,
        zone1,
        zone2,
        zone3,
        zone4
        //ok
    };

    void loadZone(zone zoneToLoad);

private:
    void buildLayers(zone zoneToLoad);
    std::vector<ParallaxLayer> layers;

public:
    Parallax();
    ~Parallax();

    void addLayer(Textures::texturesIndices textureIndex, float speed);
    void render(sf::RenderWindow& window, const Camera& camera, const Player* player);
};