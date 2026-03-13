#pragma once
#include "Globals.h"
#include "Input.h"
#include "Player.h"

// Class for create an object
class GameObject
{
public:
    // Variable
    Texture* tex;
    Color color;

    Vector2f pos;
    Vector2f size;
    Vector2f scale;

    RectangleShape rect;
    bool visibility;

public:
    // Constructor/Destructor
    GameObject() = default;
    GameObject(float x, float y);
    GameObject(float x, float y, float w, float h);
    virtual ~GameObject();

    // Method get/set
    Texture* getTexture();
    Vector2f getPos();
    Vector2f getSize();

    void setTexture(Texture* tex);
    void setColor(Color nColor);
    void setPos(Vector2f nPos);
    void setSize(Vector2f nSize);
    void setScale(Vector2f scale);

    bool isColliding(GameObject& gameObject);
    void setVisibilityTrue();
    void setVisibilityFalse();

    // Method virtual
    virtual void resolveCollision(GameObject& gameObject);
    virtual void update(float& dt, Input& input);
    virtual void render(RenderWindow* window);
};