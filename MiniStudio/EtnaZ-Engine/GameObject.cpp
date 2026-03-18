#include "GameObject.h"

GameObject::GameObject(float x, float y) : GameObject(x, y, 50, 50) {

}

GameObject::GameObject(float x, float y, float w, float h) : pos({ x,y }), size({ w,h }), visibility(true), tex(nullptr), scale({ 1,1 }) {
    color = Color::White;
    rect.setFillColor(color);
    rect.setPosition(pos);
    rect.setSize(size);
    rect.setScale(scale);
}

Texture* GameObject::getTexture() {
    return tex;
}

Vector2f GameObject::getPos() {
    return pos;
}

Vector2f GameObject::getSize() {
    return size;
}


void GameObject::setTexture(Texture* nTex) {
    tex = nTex;
}

void GameObject::setColor(Color nColor) {
    rect.setFillColor(nColor);
}

void GameObject::setPos(Vector2f nPos) {
    pos = nPos;
    rect.setPosition(nPos);
}

void GameObject::setSize(Vector2f nSize) {
    size = nSize;
    rect.setSize(nSize);
}

void GameObject::setScale(Vector2f nScale) {
    scale = nScale;
    rect.setScale(nScale);
}


void GameObject::setVisibilityTrue() {
    visibility = true;
}

void GameObject::setVisibilityFalse() {
    visibility = false;
}

void GameObject::applyGravity(){
    /*float overlapLeft = (pos.x + size.x) - gameObject.pos.x;
    float overlapright = (gameObject.pos.x + gameObject.size.x) - pos.x;
    float overlaptop = (pos.y + size.y) - gameObject.pos.y;
    float overlapbottom = (gameObject.pos.y + gameObject.size.y) - pos.y;

    bool fromleft = std::abs(overlapLeft) < std::abs(overlapright);
    bool fromtop = std::abs(overlaptop) < std::abs(overlapbottom);

    float minoverlapx = fromleft ? overlapLeft : overlapright;
    float minoverlapy = fromtop ? overlaptop : overlapbottom;

    if (std::abs(minoverlapx) < std::abs(minoverlapy)) {
        pos.x += fromleft ? -minoverlapx : minoverlapx;
        velocityX = 0;
    }
    else {
        if (fromtop) {
            pos.y -= minoverlapy;
            velocityY = 0;
            onGround = true;
        }
        else {
            pos.y += minoverlapy;
            velocityY = 0;
        }
    }
    setPos(pos);*/
}

bool GameObject::isColliding(GameObject& gameObject) {
    if (pos.x < gameObject.pos.x + gameObject.size.x &&
        pos.x + size.x > gameObject.pos.x &&
        pos.y < gameObject.pos.y + gameObject.size.y &&
        pos.y + size.y > gameObject.pos.y) {
        return true;
	}
    else if(pos.x + size.x < gameObject.pos.x ||
            pos.x > gameObject.pos.x + gameObject.size.x ||
            pos.y + size.y < gameObject.pos.y ||
            pos.y > gameObject.pos.y + gameObject.size.y) {
        return false;
	}
}

void GameObject::update(float& dt, Input& input) {

}

void GameObject::render(RenderWindow* window) {
    if (visibility) {
        if (tex) {
            rect.setTexture(tex);
        }
        window->draw(rect);
    }
}

void GameObject::resolveCollision(GameObject& gameObject) {
    float overlapLeft   = (pos.x + size.x) - gameObject.pos.x;
    float overlapRight  = (gameObject.pos.x + gameObject.size.x) - pos.x;
    float overlapTop    = (pos.y + size.y) - gameObject.pos.y;
    float overlapBottom = (gameObject.pos.y + gameObject.size.y) - pos.y;

    bool fromLeft = std::abs(overlapLeft) < std::abs(overlapRight);
    bool fromTop = std::abs(overlapTop) < std::abs(overlapBottom);

    float minOverlapX = fromLeft ? overlapLeft : overlapRight;
    float minOverlapY = fromTop ? overlapTop : overlapBottom;

    if (std::abs(minOverlapX) < std::abs(minOverlapY)) {
        pos.x += fromLeft ? -minOverlapX : minOverlapX;
    }
    else {
        if (fromTop) {
            pos.y -= minOverlapY;
        }
        else {
            pos.y += minOverlapY;
        }
    }
    setPos(pos);
}
