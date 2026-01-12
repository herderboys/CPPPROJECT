#include "Constants.h"
#include "Sprite.h"
#include "GameEngine.h"
#include <iostream>

Sprite::Sprite(GameEngine *eng, std::string name, const char *path, float x, float y) : engine(eng)
{
    texture = engine->getTexture(path);
    if (!texture)
    {
        rect = {x, y, 0, 0};
    }
    else
    {

        float w, h;
        SDL_GetTextureSize(texture, &w, &h);
        rect = {x, y, w, h};
    }
}

Sprite::~Sprite() {}

bool Sprite::collidedWith(Sprite &other)
{
    {

        /* round sprites are used in this game (earth, rotating player),
            so we have to use a custom function to check if a circle (sprite)
            has intersected with another circle.

            to check if circular sprite has collided with another sprite,
            check if distance between other and earth is less than earth's
            radius and other's radius. this is what's done here */

        // get earth radius and center x/y
        SDL_FRect myRect = getRect();

        float myRadius = myRect.w / 2.0f;
        float myCenterX = myRect.x + myRadius;
        float myCenterY = myRect.y + myRadius;

        // get other radius and center x/y
        SDL_FRect otherRect = other.getRect();

        // get earth radius and center x/y
        float otherRadius = otherRect.w / 2.0f;
        float otherCenterX = otherRect.x + otherRadius;
        float otherCenterY = otherRect.y + otherRadius;

        // use pythagorean theorem to calculate distance
        float dx = otherCenterX - myCenterX;
        float dy = otherCenterY - myCenterY;

        float distanceSquared = (dx * dx) + (dy * dy);
        float combinedRadius = otherRadius + myRadius;

        if (distanceSquared < (combinedRadius * combinedRadius))
        {
            return true;
        }
        return false;
    }
}

void Sprite::tick()
{
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
