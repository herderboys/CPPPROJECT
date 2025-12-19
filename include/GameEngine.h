#pragma once

#include <SDL3/SDL.h>
#include <SDL3_image/SDL_image.h>
#include <SDL3_ttf/SDL_ttf.h>
#include <vector>
#include <memory>
#include <map>
#include "Constants.h"

namespace cnts = constants;

class Sprite;
typedef std::shared_ptr<Sprite> SpritePtr;

class GameEngine
{
public:
    GameEngine();
    ~GameEngine();

    SDL_Renderer *getRen() const { return ren; }
    SDL_Window *getWin() const { return win; }

    void run();
    SDL_Texture *getSpriteTexture(std::string);

private:
    SDL_Window *win;
    SDL_Renderer *ren;

    // sprite texture cache
    std::map<std::string, SDL_Texture *> spriteTextures;
};