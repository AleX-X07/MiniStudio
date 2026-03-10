#pragma once
#include <SFML/Graphics.hpp>
#include <vector>

#include "Globals.h"

class Textures
{
private:
    std::vector<sf::Texture> tabTextures;
    std::vector<sf::Font> tabFonts;

public:
    enum class texturesIndices
    {
        Platform,
    };

    enum class fontsIndices
    {
    };

    Textures();
    ~Textures() = default;

    sf::Texture& getTexture(texturesIndices index);
    sf::Font& getFont(fontsIndices index);

private:
    void loadAllTexture();
    void loadAllFont();
    void loadTexture(texturesIndices _index, const char* filename);
    void loadFont(fontsIndices _index, const char* filename);
};