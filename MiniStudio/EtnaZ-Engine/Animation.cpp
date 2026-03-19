#include "Animation.h"
#include "GameObject.h"
#include "Player.h"

Animation::Animation(sf::Texture _texture, int _maxFrames, int _nbrAnimation, float _frameDuration, int _spriteWidth, int _spriteHeight) {

    currentState = CharacterState::IDLE;
    previousState = CharacterState::IDLE;

    texture = _texture;
    maxFrames = _maxFrames;
    nbrAnimation = _nbrAnimation;
    frameDuration = _frameDuration;
    spriteWidth = _spriteWidth/maxFrames;
    spriteHeight = _spriteHeight/nbrAnimation;

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
        animationRow = 0;
        break;
    case CharacterState::RIGHT:
        animationRow = 0;
        break;
    }

    if (currentState != CharacterState::IDLE) {
        myStateRect = { {  currentFrame * spriteWidth, animationRow * spriteHeight}, {spriteWidth,spriteHeight} };
    }
    else {
        myStateRect = { {0 * spriteWidth, animationRow * spriteHeight}, {spriteWidth,spriteHeight} };
    }
}