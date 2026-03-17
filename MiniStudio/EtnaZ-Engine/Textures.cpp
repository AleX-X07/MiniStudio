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
    loadTexture(Textures::texturesIndices::testSprite, "assets/myAnimation.png");
    loadTexture(Textures::texturesIndices::buttonPlay, "assets/button_play.png");
    loadTexture(Textures::texturesIndices::buttonQuit, "assets/button_quit.png");
    loadTexture(Textures::texturesIndices::backgroundMenu, "assets/fond_du_menu.png");
    loadTexture(Textures::texturesIndices::layer0, "assets/sewer_back3.png");
    loadTexture(Textures::texturesIndices::layer1, "assets/parallaxtest.png");
}

void Textures::loadAllFont() {

}

void Textures::loadTexture(texturesIndices _index, const char* fileName) {
    sf::Texture texture = sf::Texture();
    auto toto = texture.loadFromFile(fileName);

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