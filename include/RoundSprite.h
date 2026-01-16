#pragma once
#include "Sprite.h"

class RoundSprite : public Sprite
{
public:
    using Sprite::Sprite;
    bool collidedWith(Sprite &other) override;
};
