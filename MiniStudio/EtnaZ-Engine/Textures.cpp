#include "Textures.h"

Textures* Textures::TextureManager = nullptr;

Textures::Textures() {
    loadAllTexture();
    loadAllFont();
}

Textures* Textures::getMyTextures() {
    if (TextureManager == nullptr) {
        TextureManager = new Textures();
    }
    return TextureManager;
}

void Textures::loadAllTexture() {
    loadTexture(Textures::texturesIndices::testSprite, "assets/testSprite.png");
}

void Textures::loadAllFont() {

}

void Textures::loadTexture(texturesIndices _index, const char* fileName) {
    sf::Texture texture(fileName);

    auto index = (int)_index;
    if (index >= tabTextures.size())
    {
        tabTextures.resize(index + 1);
    }

    tabTextures[index] = texture;
}

void Textures::loadFont(fontsIndices _index, const char* fileName) {
    sf::Font font(fileName);

    auto index = (int)_index;
    if (index >= tabFonts.size())
    {
        tabFonts.resize(index + 1);
    }

    tabFonts[index] = font;
}

sf::Texture& Textures::getTexture(texturesIndices index) {
    return tabTextures[(int)index];
}

sf::Font& Textures::getFont(fontsIndices index) {
    return tabFonts[(int)index];
}