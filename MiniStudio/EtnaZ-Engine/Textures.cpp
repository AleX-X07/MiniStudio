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
    // Menu/Pause
    loadTexture(Textures::texturesIndices::backgroundMenu, "assets/fond_du_menu.png");
    loadTexture(Textures::texturesIndices::buttonPlay, "assets/button/button_play.png");
    loadTexture(Textures::texturesIndices::buttonQuit, "assets/button/button_quit.png");
    loadTexture(Textures::texturesIndices::buttonMenu, "assets/button/button_menu.png");
    loadTexture(Textures::texturesIndices::buttonResume, "assets/button/button_resume.png");
    // Animation player
	// DepotSlime
    loadTexture(Textures::texturesIndices::depotSlime, "assets/depot_slime.png");
	// Normal
    // Right
    loadTexture(Textures::texturesIndices::idleRight, "assets/Animation/Normal/animation_idl.png");
    loadTexture(Textures::texturesIndices::walkRight, "assets/Animation/Normal/animation_marcher.png");
    loadTexture(Textures::texturesIndices::runRight, "assets/Animation/Normal/animation_courir.png");
    loadTexture(Textures::texturesIndices::jumpRight, "assets/Animation/Normal/animation_saut.png");
    loadTexture(Textures::texturesIndices::deadRight, "assets/Animation/Normal/animation_mort.png");
    // Left
    loadTexture(Textures::texturesIndices::idleLeft, "assets/Animation/Normal/animation_idl_left.png");
    loadTexture(Textures::texturesIndices::walkLeft, "assets/Animation/Normal/animation_marcher_left.png");
    loadTexture(Textures::texturesIndices::runLeft, "assets/Animation/Normal/animation_courir_left.png");
    loadTexture(Textures::texturesIndices::jumpLeft, "assets/Animation/Normal/animation_saut_left.png");
    loadTexture(Textures::texturesIndices::deadLeft, "assets/Animation/Normal/animation_mort_left.png");
    //Heavy
    // Right
    loadTexture(Textures::texturesIndices::idleRightHeavy, "assets/Animation/Heavy/animation_idl_enorme.png");
    loadTexture(Textures::texturesIndices::walkRightHeavy, "assets/Animation/Heavy/animation_marche_enorme.png");
    loadTexture(Textures::texturesIndices::jumpRightHeavy, "assets/Animation/Heavy/animation_jump_enorme.png");
    // Left
    loadTexture(Textures::texturesIndices::idleLeftHeavy, "assets/Animation/Heavy/animation_idl_enorme_left.png");
    loadTexture(Textures::texturesIndices::walkLeftHeavy, "assets/Animation/Heavy/animation_marche_enorme_left.png");
    loadTexture(Textures::texturesIndices::jumpLeftHeavy, "assets/Animation/Heavy/animation_jump_enorme_left.png");
    // Light
    // Right
    loadTexture(Textures::texturesIndices::idleRightLight, "assets/Animation/Light/animation_idle_petit.png");
    loadTexture(Textures::texturesIndices::walkRightLight, "assets/Animation/Light/animation_marche_petit.png");
    loadTexture(Textures::texturesIndices::jumpRightLight, "assets/Animation/Light/animation_jump_petit.png");
    // Left
    loadTexture(Textures::texturesIndices::idleLeftLight, "assets/Animation/Light/animation_idle_petit_left.png");
    loadTexture(Textures::texturesIndices::walkLeftLight, "assets/Animation/Light/animation_marche_petit_left.png");
    loadTexture(Textures::texturesIndices::jumpLeftLight, "assets/Animation/Light/animation_jump_petit_left.png");
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