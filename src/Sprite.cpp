#include "Constants.h"
#include "Sprite.h"
#include "GameEngine.h"
#include <iostream>

Sprite::Sprite(GameEngine* eng, std::string name, const char* path, float x, float y) : 
engine(eng)
{
    texture = engine->getTexture(path);
    if (!texture)
    {
        std::cerr << "No such file: " << path << std::endl;
    }

    float w, h;
    SDL_GetTextureSize(texture, &w, &h);
    rect = {x, y, w, h};
}

Sprite::~Sprite() {}

bool Sprite::collidedWith(Sprite &other)
{
    return SDL_HasRectIntersectionFloat(&rect, &other.rect);
}

void Sprite::tick() {

}

void Sprite::move(float dx, float dy)
{
    SDL_FRect &rect = getRect();
    rect.x += dx;
    rect.y += dy;
}

void Sprite::draw() const
{
    SDL_RenderTextureRotated(engine->getRen(), getTexture(), 
    NULL, &rect, rotationAngle, NULL, SDL_FLIP_NONE);
};
