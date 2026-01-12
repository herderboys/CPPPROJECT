#pragma once
#include "Sprite.h"

class Enemy : public Sprite {
    public:
    Enemy(GameEngine* engine, float x, float y);
    void tick() override;

};