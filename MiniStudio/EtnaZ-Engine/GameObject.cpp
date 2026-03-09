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
    delete tex;
    tex = nullptr;
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