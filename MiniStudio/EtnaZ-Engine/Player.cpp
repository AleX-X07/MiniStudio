#include "Player.h"
#include "GameEngine.h"

Player::Player(float x, float y) : GameObject(x, y)
{
    speed = 300.0f;
}

void Player::clampInScreen() {
    pos.x = std::max(0.f, std::min(pos.x, (float)(level_size_width - size.x)));
    pos.y = std::max(0.f, std::min(pos.y, (float)(level_size_heigt - size.y)));
    setPos(pos);
}

void Player::render(RenderWindow* window)
{
    if (window) {
        window->draw(rect);
    }
}

void Player::update(float& dt, Input& input) 
{
    if (Keyboard::isKeyPressed(Keyboard::Key::Left)) 
    {
        pos.x -= speed * dt;
    }
    if (Keyboard::isKeyPressed(Keyboard::Key::Right)) 
    {
        pos.x += speed * dt;
    }
    if (Keyboard::isKeyPressed(Keyboard::Key::Up))
    {
        jump();
    }
    if (!onGround)
    {
        velocityY += gravity * dt;
        if (velocityY > 600.0f) velocityY = 600.0f;

        pos.y += velocityY * dt;
        pos.x += velocityX * dt;
        velocityX = 0;
    }
    clampInScreen();
    setPos(pos);
}

void Player::resolveCollision(GameObject& gameObject)
{
    float overlapLeft = (pos.x + size.x) - gameObject.pos.x;
    float overlapRight = (gameObject.pos.x + gameObject.size.x) - pos.x;
    float overlapTop = (pos.y + size.y) - gameObject.pos.y;
    float overlapBottom = (gameObject.pos.y + gameObject.size.y) - pos.y;

    bool fromLeft = std::abs(overlapLeft) < std::abs(overlapRight);
    bool fromTop = std::abs(overlapTop) < std::abs(overlapBottom);

    float minOverlapX = fromLeft ? overlapLeft : overlapRight;
    float minOverlapY = fromTop ? overlapTop : overlapBottom;

    if (std::abs(minOverlapX) < std::abs(minOverlapY))
    {
        pos.x += fromLeft ? -minOverlapX : minOverlapX;
        velocityX = 0;
    }
    else
    {
        if (fromTop)
        {
            pos.y -= minOverlapY;
            velocityY = 0;
            onGround = true;
        }
        else
        {
            pos.y += minOverlapY;
            velocityY = 0;
        }
    }

    setPos(pos);
}

void Player::jump() 
{
	if (onGround) 
	{
		velocityY = jumpForce;
		onGround = false;
	}
}