#include "Constants.h"
#include "Bullet.h"
#include <cmath>

namespace cnts = constants;

Bullet::Bullet(GameEngine *engine, float x, float y, double angle) : Sprite(engine, "bullet", cnts::bulletTexture.c_str(), x, y)
{

    double radians = (angle - 90.0) * (M_PI / 180.0);

    float speed = 10.0f;
    vx = std::cos(radians) * speed; // had to look this math up, don't know it
    vy = std::sin(radians) * speed;
}

void Bullet::tick()
{
    move(vx, vy);

    if (rect.x < 0 || rect.x > 1920 || rect.y < 0 || rect.y > 1080)
    {
        remove();
    }
}