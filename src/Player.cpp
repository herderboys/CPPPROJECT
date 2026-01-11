
#include "Sprite.h"
#include "Constants.h"
#include "Player.h"
#include <iostream>

namespace cnts = constants;

Player::Player(GameEngine *engine, std::string name, const char *path, float x, float y) : 
        Sprite(engine, name, path, x, y) {}

void Player::tick()
{
    const bool *state = SDL_GetKeyboardState(NULL);


        if (state[SDL_SCANCODE_W]) { move(0, -5); }
        if (state[SDL_SCANCODE_A]) { move(-5, 0); }
        if (state[SDL_SCANCODE_S]) { move(0, 5); }
        if (state[SDL_SCANCODE_D]) { move(5, 0); }

        SDL_FRect& r = getRect();


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

        
}
