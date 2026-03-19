#pragma once
#include <SFML/Graphics.hpp>
#include <vector>

#include "Globals.h"

class Textures {
public:
    enum class texturesIndices {
        Platform,
        // Button
        buttonPlay,
        buttonQuit,
        buttonMenu,
        buttonResume,
        // Background
        backgroundMenu,
        // Animation
		depotSlime,
        // Normal
        // Right
        idleRight,
        walkRight,
        runRight,
        jumpRight,
        // Left
        idleLeft,
        walkLeft,
        runLeft,
        jumpLeft,
        // Heavy
        // Right
        idleRightHeavy,
        walkRightHeavy,
        jumpRightHeavy,
        // Left
        idleLeftHeavy,
        walkLeftHeavy,
        jumpLeftHeavy,
        // Light
        // Right
        idleRightLight,
        walkRightLight,
        jumpRightLight,
        // Left
        idleLeftLight,
        walkLeftLight,
        jumpLeftLight,
        // Dead
        deadRight,
        deadLeft,

        seed,
        orb,
        crate,
        door
        title,
    };

    enum class fontsIndices{
    };

private:
    Textures();

public:
    ~Textures() = default;

    sf::Texture& getTexture(texturesIndices index);
    sf::Font& getFont(fontsIndices index);

    void loadAllTexture();
    void loadAllFont();
    void loadTexture(texturesIndices _index, const char* filename);
    void loadFont(fontsIndices _index, const char* filename);

    static Textures* getMyTextures();

private:
    static Textures* TextureManager;

    std::vector<sf::Texture> tabTextures;
    std::vector<sf::Font> tabFonts;
};