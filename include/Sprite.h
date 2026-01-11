#pragma once

#include "GameObject.h"
#include <iostream>
#include <SDL3/SDL.h>
#include <SDL3_image/SDL_image.h>
#include <SDL3_ttf/SDL_ttf.h>

class GameEngine;
class Sprite : public GameObject
{
public:
    Sprite(GameEngine* engine, std::string name, const char* texture, float x, float y);
    Sprite() = default;
    virtual ~Sprite();
    virtual void tick();

    void move(float dx, float dy);

    void draw() const;

    bool collidedWith(Sprite& other);

    SDL_FRect &getRect()
    {
        return rect;
    }

    SDL_Texture *getTexture() const
    {
        return texture;
    }

protected:
    SDL_FRect rect;
    SDL_Texture *texture;
    GameEngine* engine;
    double rotationAngle = 0.0;
};