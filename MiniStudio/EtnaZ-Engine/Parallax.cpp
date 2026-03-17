#include "Parallax.h"
#include "Camera.h"


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

void Parallax::render(sf::RenderWindow& window, const Camera& camera)
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

        float offsetX = std::fmod(cameraX * layer.speed, (float)texSize.x);
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