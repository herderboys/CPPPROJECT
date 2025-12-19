#pragma once

#include "GameObject.h"
#include <SDL.h>
#include <SDL3_image/SDL_image.h>
#include <SDL3_ttf/SDL_ttf.h>

class Sprite : GameObject {
    public:

    Sprite();
    ~Sprite();

    private:

        SDL_Texture* texture;

}