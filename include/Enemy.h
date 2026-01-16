#pragma once
#include "RoundSprite.h"

class Enemy : public RoundSprite {
    public:
    Enemy(GameEngine* engine, float x, float y);
    void tick() override;
    void onCollision(Sprite& other) override;

};