#include "Animation.h"
#include "GameObject.h"
#include "Player.h"

Animation::Animation() : Animation(nullptr, 0, 0, 0, 0) {

}

Animation::Animation(const char* _pathSpriteSheet, int _maxFrames, float _frameDuration, int _spriteWidth, int _spriteHeight) {

    currentState = CharacterState::IDLE;
    previousState = CharacterState::IDLE;

    pathSpriteSheet = _pathSpriteSheet;
    maxFrames = _maxFrames;
    frameDuration = _frameDuration;
    spriteWidth = _spriteWidth;
    spriteHeight = _spriteHeight;

    animationTimer = 0;
    currentFrame = 0;
    animationRow = 0;
}


Animation::~Animation() {

}

CharacterState Animation::getCurrentState() {
    return currentState;
}

void Animation::setCurrentState(CharacterState state) {
    currentState = state;
}

void Animation::updatePNJ(float dt)
{
    animationTimer += dt;
    if (animationTimer >= frameDuration) {
        animationTimer = 0.0f;
        currentFrame++;

        if (currentFrame >= maxFrames) {
            currentFrame = 0;
        }
    }

    if (currentState != previousState) {
        currentFrame = 0;
        animationTimer = 0.0f;
        previousState = currentState;
    }
}

void Animation::update(float dt) {
    animationTimer += dt;
    if (animationTimer >= frameDuration) {
        animationTimer = 0.0f;
        currentFrame++;

        if (currentFrame >= maxFrames) {
            currentFrame = 0;
        }
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)) {
        currentState = CharacterState::RIGHT;
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Q)) {
        currentState = CharacterState::LEFT;
    }
    else {
        currentState = CharacterState::IDLE;
    }

    if (currentState != previousState) {
        currentFrame = 0;
        animationTimer = 0.0f;
        previousState = currentState;
    }
}

void Animation::render(sf::RenderWindow& window) {

    switch (currentState) {
    case CharacterState::IDLE:
        animationRow = 0;
        break;
    case CharacterState::LEFT:
        animationRow = 1;
        break;
    case CharacterState::RIGHT:
        animationRow = 2;
        break;
    }

    if (currentState != CharacterState::IDLE) {
        myStateRect = { {currentFrame * spriteWidth, animationRow * spriteHeight}, {spriteWidth,spriteHeight} };
    }
    else {
        myStateRect = { {0 * spriteWidth, animationRow * spriteHeight}, {spriteWidth,spriteHeight} };
    }
}