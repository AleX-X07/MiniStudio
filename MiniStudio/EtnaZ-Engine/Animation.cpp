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
    defautlDuration = _frameDuration;
    spriteWidth = _spriteWidth/maxFrames;
    spriteHeight = _spriteHeight/nbrAnimation;

    animationTimer = 0;
    currentFrame = 0;
    animationRow = 0;
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

void Animation::update(float dt, Input& input, Player* Owner) {
    animationTimer += dt;
    if (animationTimer >= frameDuration) {
        animationTimer = 0.0f;
        currentFrame++;

        if (currentFrame >= maxFrames) {
            currentFrame = 0;
        }
    }

    if (!(Owner->currentStates == Player::SlimeStates::death)) {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)) {
            if (Owner->onGround) {
                currentState = CharacterState::RIGHT;
                if (Owner->runBool) currentState = CharacterState::RUNRIGHT;
            }
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Q)) {
            if (Owner->onGround) {
                currentState = CharacterState::LEFT;
                if (Owner->runBool) currentState = CharacterState::RUNLEFT;
            }
        }

        else if (previousState == CharacterState::RIGHT) {
            currentState = CharacterState::IDLERIGHT;
        }
        else if (previousState == CharacterState::LEFT) {
            currentState = CharacterState::IDLELEFT;
        }

        if (!Owner->onGround && input.isKeyPressed(sf::Keyboard::Key::Space)) {
            if (currentState == CharacterState::LEFT || currentState == CharacterState::IDLELEFT || currentState == CharacterState::RUNLEFT) {
                currentState = CharacterState::JUMPLEFT;
            }
            else if (currentState == CharacterState::RIGHT || currentState == CharacterState::IDLERIGHT || currentState == CharacterState::RUNRIGHT) {
                currentState = CharacterState::JUMPRIGHT;
            }
        }

        else if ((!Owner->onGround && currentState == CharacterState::JUMPRIGHT)) {
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Q)) {

                currentState = CharacterState::JUMPLEFT;
            }
        }
        else if ((!Owner->onGround && currentState == CharacterState::JUMPLEFT)) {
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)) {

                currentState = CharacterState::JUMPRIGHT;
            }
        }

        else if ((currentState == CharacterState::JUMPRIGHT) && Owner->onGround) {
            currentState = CharacterState::IDLERIGHT;
        }
        else if ((currentState == CharacterState::JUMPLEFT) && Owner->onGround) {
            currentState = CharacterState::IDLELEFT;
        }
    }

    else {
        if (previousState == CharacterState::RIGHT || previousState == CharacterState::IDLERIGHT || previousState == CharacterState::JUMPRIGHT || previousState == CharacterState::RUNRIGHT) {
            currentState = CharacterState::DEATHRIGHT;

        }
        else if (previousState == CharacterState::LEFT || previousState == CharacterState::IDLELEFT || previousState == CharacterState::JUMPLEFT || previousState == CharacterState::RUNLEFT) {
            currentState = CharacterState::DEATHLEFT;
        }
    }

    if (currentState != previousState) {
        currentFrame = 0;
        animationTimer = 0.0f;
        previousState = currentState;
    }
}

void Animation::render(sf::RenderWindow& window, Player* Owner) {
    switch (Owner->currentStates) {
    case Player::SlimeStates::normal:
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
		case CharacterState::RUNRIGHT:
            texture = Textures::getMyTextures()->getTexture(Textures::texturesIndices::runRight);
            break; 
        case CharacterState::RUNLEFT:
            texture = Textures::getMyTextures()->getTexture(Textures::texturesIndices::runLeft);
            break;
        case CharacterState::JUMPRIGHT:
            texture = Textures::getMyTextures()->getTexture(Textures::texturesIndices::jumpRight);
            break;
        case CharacterState::JUMPLEFT:
            texture = Textures::getMyTextures()->getTexture(Textures::texturesIndices::jumpLeft);
            break;
        }
		break;
    case Player::SlimeStates::heavy:
        switch (currentState) {
        case CharacterState::IDLERIGHT:
            texture = Textures::getMyTextures()->getTexture(Textures::texturesIndices::idleRightHeavy);
            break;
        case CharacterState::IDLELEFT:
            texture = Textures::getMyTextures()->getTexture(Textures::texturesIndices::idleLeftHeavy);
            break;
        case CharacterState::LEFT:
            texture = Textures::getMyTextures()->getTexture(Textures::texturesIndices::walkLeftHeavy);
            break;
        case CharacterState::RIGHT:
            texture = Textures::getMyTextures()->getTexture(Textures::texturesIndices::walkRightHeavy);
            break;
        case CharacterState::RUNRIGHT:
            texture = Textures::getMyTextures()->getTexture(Textures::texturesIndices::walkRightHeavy);
            break;
        case CharacterState::RUNLEFT:
            texture = Textures::getMyTextures()->getTexture(Textures::texturesIndices::walkLeftHeavy);
            break;
        case CharacterState::JUMPRIGHT:
            texture = Textures::getMyTextures()->getTexture(Textures::texturesIndices::jumpRightHeavy);
            break;
        case CharacterState::JUMPLEFT:
            texture = Textures::getMyTextures()->getTexture(Textures::texturesIndices::jumpLeftHeavy);
            break;
        }
        break;
    case Player::SlimeStates::light:
        switch (currentState) {
        case CharacterState::IDLERIGHT:
            texture = Textures::getMyTextures()->getTexture(Textures::texturesIndices::idleRightLight);
            break;
        case CharacterState::IDLELEFT:
            texture = Textures::getMyTextures()->getTexture(Textures::texturesIndices::idleLeftLight);
            break;
        case CharacterState::LEFT:
            texture = Textures::getMyTextures()->getTexture(Textures::texturesIndices::walkLeftLight);
            break;
        case CharacterState::RIGHT:
            texture = Textures::getMyTextures()->getTexture(Textures::texturesIndices::walkRightLight);
            break;
        case CharacterState::RUNRIGHT:
            texture = Textures::getMyTextures()->getTexture(Textures::texturesIndices::walkRightLight);
            break;
        case CharacterState::RUNLEFT:
            texture = Textures::getMyTextures()->getTexture(Textures::texturesIndices::walkLeftLight);
            break;
        case CharacterState::JUMPRIGHT:
            texture = Textures::getMyTextures()->getTexture(Textures::texturesIndices::jumpRightLight);
            break;
        case CharacterState::JUMPLEFT:
            texture = Textures::getMyTextures()->getTexture(Textures::texturesIndices::jumpLeftLight);
            break;
        }
        break;
  //  case Player::SlimeStates::death:
  //      switch (currentState) {
		//case CharacterState::DEATHRIGHT:
	 //       texture = Textures::getMyTextures()->getTexture(Textures::texturesIndices::deadRight);
	 //       break;
		//case CharacterState::DEATHLEFT:
	 //       texture = Textures::getMyTextures()->getTexture(Textures::texturesIndices::deadLeft);
	 //       break;
  //      }
  //      break;
  }
   
    myStateRect = { {  currentFrame * spriteWidth, animationRow * spriteHeight}, {spriteWidth,spriteHeight} };
}