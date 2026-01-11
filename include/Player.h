#pragma once

#include "Sprite.h"
#include <iostream>

class Player : public Sprite
{
public:
    Player(GameEngine* engine, std::string name, const char* path, float x, float y);
    void tick() override;
};