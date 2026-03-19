#include "Parallax.h"

Parallax::Parallax() {

}

Parallax::~Parallax() {

}

void Parallax::addLayer(Textures::texturesIndices textureIndex, float speed)
{
    ParallaxLayer layer;
    layer.textureIndex = textureIndex;
    layer.speed = -speed;
    layers.push_back(layer);
}

void Parallax::render(sf::RenderWindow& window, const Camera& camera, const Player* player)
{
    sf::Vector2u winSize = window.getSize();
    sf::Vector2f camCenter;

    camera.getCameraPos(camCenter);
    float cameraX = camCenter.x - winSize.x / 2;

    for (auto& layer : layers) {
        sf::Texture& tex = Textures::getMyTextures()->getTexture(layer.textureIndex);
        sf::Sprite sprite(tex);
        sf::Vector2u texSize = tex.getSize();
        tex.setRepeated(true);

        float offsetX = std::fmod(player->pos.x * layer.speed, (float)texSize.x);
        if (offsetX > 0.f) {
            offsetX -= (float)texSize.x;
        }

        float posY = (float)winSize.y - (float)texSize.y;
        for (float x = offsetX; x < (float)winSize.x; x += (float)texSize.x) {
            sprite.setPosition({ x, posY });
            window.draw(sprite);
        }
    }
};

void Parallax::loadZone(zone zoneToLoad)
{
    layers.clear();
    buildLayers(zoneToLoad);
}

void Parallax::buildLayers(zone zoneToLoad)
{
    switch (zoneToLoad) {
    case zone::zone1:
        addLayer(Textures::texturesIndices::zone3Layer0, 0.2f);
        addLayer(Textures::texturesIndices::particle, 0.6f);
        //addLayer(Textures::texturesIndices::zone1Layer0, 0.2f);
        //addLayer(Textures::texturesIndices::particle, 0.6f);
        break;
    case zone::zone2:
        addLayer(Textures::texturesIndices::zone2Layer0, 0.2f);
        addLayer(Textures::texturesIndices::particle, 0.6f);
        break;
    case zone::zone3:

        break;
    case zone::zone4:
        addLayer(Textures::texturesIndices::zone4Layer0, 0.2f);
        addLayer(Textures::texturesIndices::particle, 0.6f);
        break;
    }
}
