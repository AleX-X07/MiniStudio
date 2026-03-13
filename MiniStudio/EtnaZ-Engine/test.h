#pragma once
#include "GameObject.h"

class test : public GameObject
{
	virtual void update(float& dt, Input& input) override;
};

