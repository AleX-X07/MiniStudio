#include "GameObject.h"

GameObject::GameObject(float x, float y) : GameObject(x, y, 50, 50) {

}

GameObject::GameObject(float x, float y, float w, float h) : pos({ x,y }), size({ w,h }), visibility(true), tex(nullptr), color({ 255,0,0,255 }), scale({ 1,1 }) {
    rect.setFillColor(color);
    rect.setPosition(pos);
    rect.setSize(size);
    rect.setScale(scale);
}

GameObject::~GameObject() {

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
    rect.setPosition(nPos);
}

void GameObject::setSize(Vector2f nSize) {
    rect.setSize(nSize);
}

void GameObject::setScale(Vector2f nScale) {
    rect.setScale(nScale);
}


void GameObject::setVisibilityTrue() {
    visibility = true;
}

void GameObject::setVisibilityFalse() {
    visibility = false;
}

bool GameObject::isColliding(GameObject& gameObject) {
    return (pos.x > gameObject.pos.x &&
        pos.x + size.x < gameObject.pos.x + gameObject.size.x &&
        pos.y > gameObject.pos.y &&
        pos.y + size.y < gameObject.pos.y + gameObject.size.y);
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
    float overlapLeft = (pos.x + size.x) - gameObject.pos.x;
    float overlapRight = (gameObject.pos.x + gameObject.size.x) - pos.x;
    float overlapTop = (pos.y + size.y) - gameObject.pos.y;
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
