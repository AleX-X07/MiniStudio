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
    loadTexture(Textures::texturesIndices::buttonPlay, "assets/button_play.png");
    loadTexture(Textures::texturesIndices::buttonQuit, "assets/button_quit.png");
    loadTexture(Textures::texturesIndices::backgroundMenu, "assets/fond_du_menu.png");
    //Animation player
    // Right
    loadTexture(Textures::texturesIndices::idleRight, "assets/animation_idl.png");
    loadTexture(Textures::texturesIndices::walkRight, "assets/animation_marcher.png");
    loadTexture(Textures::texturesIndices::runRight, "assets/animation_courir.png");
    loadTexture(Textures::texturesIndices::jumpRight, "assets/animation_saut.png");
    loadTexture(Textures::texturesIndices::deadRight, "assets/animation_mort.png");
    // Left
    loadTexture(Textures::texturesIndices::idleLeft, "assets/animation_idl_left.png");
    loadTexture(Textures::texturesIndices::walkLeft, "assets/animation_marcher_left.png");
    loadTexture(Textures::texturesIndices::runLeft, "assets/animation_courir_left.png");
    loadTexture(Textures::texturesIndices::jumpLeft, "assets/animation_saut_left.png");
    loadTexture(Textures::texturesIndices::deadLeft, "assets/animation_mort_left.png");

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