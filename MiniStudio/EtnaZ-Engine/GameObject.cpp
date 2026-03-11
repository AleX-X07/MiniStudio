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

bool GameObject::isColliding(GameObject& gameObject1, GameObject& gameObject2)
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

void GameObject::resolveCollision(Player& player, GameObject& platform)
{
    float overlapLeft = (player.position.x + player.shape.getSize().x) - platform.pos.x;
    float overlapRight = (platform.pos.x + platform.size.x) - player.position.x;
    float overlapTop = (player.position.y + player.shape.getSize().y) - platform.pos.y;
    float overlapBottom = (platform.pos.y + platform.size.y) - player.position.y;

    bool fromLeft = std::abs(overlapLeft) < std::abs(overlapRight);
    bool fromTop = std::abs(overlapTop) < std::abs(overlapBottom);

    float minOverlapX = fromLeft ? overlapLeft : overlapRight;
    float minOverlapY = fromTop ? overlapTop : overlapBottom; 

    if (std::abs(minOverlapX) < std::abs(minOverlapY))
    {
        player.position.x += fromLeft ? -minOverlapX : minOverlapX;
        player.velocityX = 0;
    }
    else
    {
        if (fromTop)
        {
            player.position.y -= minOverlapY;
            player.velocityY = 0;
            player.onGround = true;
        }
        else
        {
            player.position.y += minOverlapY;
            player.velocityY = 0;
        }
    }
    player.shape.setPosition(player.position);
}