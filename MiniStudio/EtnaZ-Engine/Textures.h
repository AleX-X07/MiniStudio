#pragma once
#include <SFML/Graphics.hpp>
#include <vector>

#include "Globals.h"

class Textures {
public:
    enum class texturesIndices{
        Platform,
        testSprite,
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