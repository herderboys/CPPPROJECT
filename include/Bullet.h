#pragma once
#include "RoundSprite.h"

class Bullet : public RoundSprite
{

public:
    Bullet(GameEngine *engine, float x, float y, double angle);

    void tick() override;

    void onCollision(Sprite& other) override;

private:
    float vx, vy;
};