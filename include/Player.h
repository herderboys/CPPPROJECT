#pragma once

#include "Sprite.h"
#include <iostream>

class Player : public Sprite
{
public:
    Player(GameEngine *engine, std::string name, const char *path, float x, float y);
    void onCollision(Sprite &other) override;
    void bounceFrom(Sprite &other);
    void takeDamage();
    void tick() override;
    int getHealth() { return health; }

private:
    int reloadTimer = 0;

    int health = 100;

    float vx = 0; // velocity, for bounce function
    float vy = 0;

    float maxSpeed = 2.0f;
    float friction = 0.98f; // felt this was a good half floaty friction
    float speed = 0.5f;
};