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


void GameObject::setTexture(Texture* nTex) 
{
    tex = nTex;
}

void GameObject::setColor(Color nColor) 
{
    rect.setFillColor(nColor);
}

void GameObject::setPos(Vector2f nPos) 
{
    rect.setPosition(nPos);
}

void GameObject::setSize(Vector2f nSize) 
{
    rect.setSize(nSize);
}

void GameObject::setScale(Vector2f nScale) 
{
    rect.setScale(nScale);
}


void GameObject::setVisibilityTrue() 
{
    visibility = true;
}

void GameObject::setVisibilityFalse() 
{
    visibility = false;
}


void GameObject::update(float& dt, Input& input) 
{

}

void GameObject::render(RenderWindow* window) 
{
    if (visibility) 
    {
        if (tex) 
        {
            rect.setTexture(tex);
        }
        window->draw(rect);
    }
}

bool GameObject::isColliding(Player& player, GameObject& gameObject)
{
  /*  auto& rectpos1 = player.position;
    auto& rectsize1 = player.shape;
    auto& rectpos2 = gameObject.pos;
    auto& rectsize2 = gameObject.size;*/ 
    return (player.position.x < gameObject.pos.x + gameObject.size.x &&     // w = size.x, h = size.y
        player.position.x + player.shape.getSize().x > gameObject.pos.x &&
        player.position.y < gameObject.pos.y + gameObject.size.y &&
        player.position.y + player.shape.getSize().y > gameObject.size.y);
}

void GameObject::resolveCollision(Player& player, GameObject& gameObject)
{
    float overlapLeft = (player.position.x + player.shape.getSize().x) - gameObject.pos.x;
    float overlapRight = (gameObject.pos.x + gameObject.size.x) - player.position.x;
    float overlapTop = (player.position.y + player.shape.getSize().y) - gameObject.pos.y;
    float overlapBottom = (gameObject.pos.y + gameObject.size.y) - player.position.y;

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