#pragma once

#include "Sprite.h"
#include <iostream>

class Player : public Sprite
{
public:
    Player(std::string name, std::string texture, float x, float y);
};