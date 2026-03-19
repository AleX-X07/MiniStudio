#pragma once
#include <SFML/Graphics.hpp>
#include <vector>

#include "Globals.h"

class Textures {
public:
    enum class texturesIndices {
        Platform,
        testSprite,
        buttonPlay,
        buttonQuit,
        backgroundMenu,
        particle,
        zone1Layer0,
        zone1Layer1,
        zone2Layer0,
        zone2Layer1,
		zone3Layer0,
		zone3Layer1,
		zone4Layer0,
		zone4Layer1
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