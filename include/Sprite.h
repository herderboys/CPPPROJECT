#pragma once

#include <SDL.h>
#include <SDL3_image/SDL_image.h>
#include <SDL3_ttf/SDL_ttf.h>

class Sprite {
    public:

    Sprite();
    ~Sprite();

    private:

        SDL_Texture* texture;

}