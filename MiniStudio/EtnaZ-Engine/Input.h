#pragma once
#include "Globals.h"

struct Input
{
	const Event::KeyPressed* currentInputKey;
	const Event::MouseButtonPressed* currentInputMouse;

	Input() = default;
	~Input() = default;

	void setInputKey(const Event::KeyPressed* input);
	void setInputMouse(const Event::MouseButtonPressed* input);
};

