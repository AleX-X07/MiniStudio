#pragma once
#include <SFML/Graphics.hpp>

#include "Input.h"

class Player;
class GameObject;

enum class CharacterState {
    IDLERIGHT,
    IDLELEFT,
    LEFT,
    RIGHT,
    RUNRIGHT,
    RUNLEFT,
    JUMPRIGHT,
    JUMPLEFT,
    DEATH,
};

class Animation
{
private:
    // Variable
    CharacterState currentState;
    CharacterState previousState;

    int currentFrame;
    int maxFrames;
    int nbrAnimation;

    float defautlDuration;
    float animationTimer;
    float frameDuration;

    int spriteWidth;
    int spriteHeight;

public:
    sf::IntRect myStateRect;
    int animationRow;
    sf::Texture texture;

public:
    // Constructor/Destructor
    Animation() = default;
    Animation(int maxFrames, int nbrAnimation, float frameDuration, int spriteWidth, int spriteHeight);
    ~Animation();

    //Get/Set
    CharacterState getCurrentState();
    void setCurrentState(CharacterState state);

    // Method
    void updatePNJ(float dt);
    void update(float dt, Input& input, Player* Owner);
    void render(sf::RenderWindow& window, Player* Owner);
};
