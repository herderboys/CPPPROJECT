#include "RoundSprite.h"

bool RoundSprite::collidedWith(Sprite& other) {
     /* round sprites are used in this game (earth, rotating player),
            so we have to use a custom function for round sprites to check if a circle (sprite)
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