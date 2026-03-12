#pragma once
#include <SFML/Graphics.hpp>

#include "Input.h"

class Player;
class GameObject;

enum class CharacterState {
    IDLE,
    LEFT,
    RIGHT,
};

class Animation
{
private:
    // Variable
    CharacterState currentState;
    CharacterState previousState;

    int currentFrame;
    int maxFrames;

    float animationTimer;
    float frameDuration;

    int spriteWidth;
    int spriteHeight;

public:
    sf::IntRect myStateRect;
    const char* pathSpriteSheet;
    int animationRow;
public:
    // Constructor/Destructor
    Animation();
    Animation(const char* pathSpriteSheet, int maxFrames, float frameDuration, int spriteWidth, int spriteHeight);
    ~Animation();

    //Get/Set
    CharacterState getCurrentState();
    void setCurrentState(CharacterState state);

    // Method
    void updatePNJ(float dt);
    void update(float dt);
    void render(sf::RenderWindow& window);
};
