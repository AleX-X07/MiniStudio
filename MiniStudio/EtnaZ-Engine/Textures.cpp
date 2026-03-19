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
	loadTexture(Textures::texturesIndices::particle, "assets/particle.png");
    loadTexture(Textures::texturesIndices::zone1Layer0, "assets/background1.png");
    loadTexture(Textures::texturesIndices::zone1Layer1, "assets/assets1.png");
    loadTexture(Textures::texturesIndices::zone2Layer1, "assets/assets2.png");
    loadTexture(Textures::texturesIndices::zone2Layer0, "assets/background2.png");
    loadTexture(Textures::texturesIndices::zone3Layer0, "assets/background3.png");
    loadTexture(Textures::texturesIndices::zone4Layer0, "assets/background4.png");
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