#include "Constants.h"
#include "Bullet.h"
#include <cmath>

namespace cnts = constants;

Bullet::Bullet(GameEngine *engine, float x, float y, double angle) : Sprite(engine, cnts::bulletTexture, "bullet", x, y)
{

double radians = (angle - 90.0) * (M_PI / 180.0);

float speed = 10.0f;
vx                    

}

void Bullet::tick()
{
}