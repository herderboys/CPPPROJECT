#include "Constants.h"
#include "Sprite.h"
#include "GameEngine.h"
#include <iostream>

Sprite::Sprite(std::string name, std::string textureName, float x, float y)
{
    texture = engine.getSpriteTexture(textureName);
    if (!texture)
    {
        std::cerr << "No such file: " << textureName << std::endl;
    }
    rect = {x,
            y,
            static_cast<float>(texture->w),
            static_cast<float>(texture->h)};
        }

Sprite::~Sprite() {}

void Sprite::move(float dx, float dy)
{
    SDL_FRect &rect = getRect();
    rect.x += dx;
    rect.y += dy;
}


void Sprite::draw() const {
    SDL_RenderTexture(engine.getRen(), getTexture(), NULL, &rect);
};