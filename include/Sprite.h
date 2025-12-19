#pragma once

#include "GameObject.h"
#include <iostream>
#include <SDL3/SDL.h>
#include <SDL3_image/SDL_image.h>
#include <SDL3_ttf/SDL_ttf.h>

class Sprite : GameObject
{
public:
    Sprite(std::string name, std::string texture, float x, float y);
    Sprite() = default;
    virtual ~Sprite();

    void move(float dx, float dy);

    void draw() const;

    SDL_FRect &getRect()
    {
        return rect;
    }

    SDL_Texture *getTexture() const
    {
        return texture;
    }

private:
    SDL_FRect rect;
    SDL_Texture *texture;
};