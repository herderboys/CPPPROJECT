
#include "Sprite.h"
#include "Constants.h"
#include "Player.h"
#include <cmath>
#include <iostream>

namespace cnts = constants;

Player::Player(GameEngine *engine, std::string name, const char *path, float x, float y) : 
        Sprite(engine, name, path, x, y) {}

void Player::tick()
{
    
    SDL_FRect& r = getRect();
    
    const bool *state = SDL_GetKeyboardState(NULL);


        if (state[SDL_SCANCODE_W]) { move(0, -1); }
        if (state[SDL_SCANCODE_A]) { move(-1, 0); }
        if (state[SDL_SCANCODE_S]) { move(0, 1); }
        if (state[SDL_SCANCODE_D]) { move(1, 0); }

        // no out of bounds for player sprite
        if (r.x < 0) {
            r.x = 0;
        }
        else if (r.x + r.w > cnts::gScreenWidth) {
            r.x = cnts::gScreenWidth - r.w;
        }

        if (r.y < 0) {
            r.y = 0;
        }
        else if (r.y + r.h > cnts::gScreenHeight) {
            r.y = cnts::gScreenHeight - r.h;
        }


    // rotating player to it always faces mouse cursor
    
    // mouse cursor current position
    float mouseX, mouseY;
    SDL_GetMouseState(&mouseX, &mouseY);

    // center of sprite
    float centerX = r.x + (r.w/2);
    float centerY = r.y + (r.h/2);

    // calculate distance between sprite and cursor
    float dx = mouseX - centerX;
    float dy = mouseY - centerY;

    // calculating angle in radians
    double angleRadians = std::atan2(dy, dx);

    // converting to degrees for SDL
    double angleDegrees = angleRadians * (180.0 / M_PI);
    // + 90 because ship points up, otherwise would point to left
    rotationAngle = angleDegrees + 90;
    
}
