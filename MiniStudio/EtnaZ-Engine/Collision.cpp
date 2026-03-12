#include "Collision.h"
#include <cmath>

bool isColliding(GameObject& gameObject1, GameObject& gameObject2) 
{
	auto& rectpos1 = gameObject1.pos;
	auto& rectsize1 = gameObject1.size;
    auto& rectpos2 = gameObject2.pos;
	auto& rectsize2 = gameObject2.size; // w = size.x, h = size.y
    return (rectpos1.x < rectpos2.x + rectsize2.x &&
            rectpos1.x + rectsize1.x > rectpos2.x &&
            rectpos1.y < rectpos2.y + rectsize2.y &&
            rectpos1.y + rectsize1.y > rectpos2.y);
}