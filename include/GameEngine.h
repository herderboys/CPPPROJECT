#pragma once

#include <SDL3/SDL.h>
#include <SDL3_image/SDL_image.h>
#include <SDL3_ttf/SDL_ttf.h>
#include <vector>
#include <memory>
#include <map>

namespace cnts = constants;

class Sprite;
typedef std::shared_ptr<Sprite> SpritePtr;

class MoveableSprite;
typedef std::shared_ptr<MoveableSprite> MovSpritePtr;

class GameEngine
{
public:
    GameEngine(const char* title);
    ~GameEngine();

    SDL_Renderer *getRen() const { return ren; }

    SDL_Texture* getTexture(const char* path);

    void addSprite(SpritePtr);

    void run();

    SDL_Texture *getSpriteTexture(std::string);

private:
    SDL_Window *win;
    SDL_Renderer *ren;

    const char* title;

    SpritePtr player;
    SpritePtr earth;

    // vector holding all active sprites
    std::vector<SpritePtr> sprites;

    // sprite texture cache
    std::map<std::string, SDL_Texture *> spriteTextures;
};
