#include "AnimationPlayer.h"


void AnimationPlayer::setAnimation(Player* Owner) {
	// walk right
	Animation* walk = new Animation(Textures::getMyTextures()->getTexture(Textures::texturesIndices::walk), 4, 1, 0.09f, 1024, 256);
	Owner->setAnimation(walk);

	// idl right
	Animation* idlright = new Animation(Textures::getMyTextures()->getTexture(Textures::texturesIndices::idlright), 4, 1, 0.09f, 1024, 256);
	Owner->setAnimation(idlright);

}
