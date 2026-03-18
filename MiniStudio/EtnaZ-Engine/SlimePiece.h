#pragma once
#include "GameObject.h"

class SlimePiece : public GameObject {
public:
	bool onGround;

private:
	float velocityX;
	float velocityY;
	float gravity;

public:
	SlimePiece() = default;
	SlimePiece(float x, float y, float w, float h);
	~SlimePiece() = default;


	// Method virtual
	virtual void update(float& dt, Input& input) override;
	virtual void render(RenderWindow* window) override;
	virtual void resolveCollision(GameObject& gameObject) override;
};

