#include "Animation.h"
#include "GameObject.h"
#include "Player.h"
#include "Textures.h"

Animation::Animation(int _maxFrames, int _nbrAnimation, float _frameDuration, int _spriteWidth, int _spriteHeight) {

    currentState = CharacterState::IDLERIGHT;
    previousState = CharacterState::IDLERIGHT;

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
            jump = false;
        }
    }

    jump = true;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)) {
        currentState = CharacterState::RIGHT;
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Q)) {
        currentState = CharacterState::LEFT;
    }

    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space)) {
        /*if (previousState == CharacterState::LEFT || previousState == CharacterState::IDLELEFT) {
            currentState = CharacterState::JUMPLEFT;
        }
        else if (previousState == CharacterState::RIGHT || previousState == CharacterState::IDLERIGHT) {
            currentState = CharacterState::JUMPRIGHT;
        }
        else if (jump == false){
            currentState = CharacterState::RIGHT;
        }*/
    }
    else if (previousState == CharacterState::RIGHT){
        currentState = CharacterState::IDLERIGHT;
    }
    else if (previousState == CharacterState::LEFT) {
        currentState = CharacterState::IDLELEFT;
    }

    if (currentState != previousState) {
        currentFrame = 0;
        animationTimer = 0.0f;
        previousState = currentState;
    }
}

void Animation::render(sf::RenderWindow& window) {

    switch (currentState) {
    case CharacterState::IDLERIGHT:
        texture = Textures::getMyTextures()->getTexture(Textures::texturesIndices::idleRight);
        break; 
    case CharacterState::IDLELEFT:
            texture = Textures::getMyTextures()->getTexture(Textures::texturesIndices::idleLeft);
            break;
    case CharacterState::LEFT:
        texture = Textures::getMyTextures()->getTexture(Textures::texturesIndices::walkLeft);
        break;
    case CharacterState::RIGHT:
        texture = Textures::getMyTextures()->getTexture(Textures::texturesIndices::walkRight);
        break;
    case CharacterState::JUMPRIGHT: 
    	texture = Textures::getMyTextures()->getTexture(Textures::texturesIndices::jumpRight);
        break; 
    case CharacterState::JUMPLEFT:
        texture = Textures::getMyTextures()->getTexture(Textures::texturesIndices::jumpLeft);
        break;
    }
    myStateRect = { {  currentFrame * spriteWidth, animationRow * spriteHeight}, {spriteWidth,spriteHeight} };
    
}