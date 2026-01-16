#pragma once

#include "RoundSprite.h"

class Earth : public RoundSprite
{
public:
    using RoundSprite::RoundSprite;
    void takeDamage();
    int getHealth() { return health; } 
    void onCollision(Sprite& other) override;

private:
    int health = 500;
};