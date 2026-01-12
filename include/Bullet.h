#pragma once
#include "Sprite.h"

class Bullet : public Sprite
{

public:
    Bullet(GameEngine *engine, float x, float y, double angle);

    void tick() override;
    void draw() const override;

private:
    float vx, vy;
};