#pragma once
#include "Globals.h"
#include "Input.h"

// Class for create an object
class GameObject
{
public:
    // Variable
    sf::Texture* tex;
    sf::Color color;

    sf::Vector2f pos;
    sf::Vector2f size;
    sf::Vector2f scale;

    sf::RectangleShape rect;
    bool visibility;

public:
    // Constructor/Destructor
    GameObject() = default;
    GameObject(float x, float y);
    GameObject(float x, float y, float w, float h);
    ~GameObject() = default;

    // Method get/set
    sf::Texture* getTexture();
    sf::Vector2f getPos();
    sf::Vector2f getSize();

    void setTexture(sf::Texture* tex);
    void setColor(sf::Color nColor);
    void setPos(sf::Vector2f nPos);
    void setSize(sf::Vector2f nSize);
    void setScale(sf::Vector2f scale);

    void setVisibilityTrue();
    void setVisibilityFalse();

    void applyGravity();
    bool isColliding(GameObject& gameObject);

    // Method virtual
    virtual void update(float& dt, Input& input);
    virtual void render(sf::RenderWindow* window);
    virtual void resolveCollision(GameObject& gameObject);
};