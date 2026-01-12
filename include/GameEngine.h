#pragma once

#include <SDL3/SDL.h>
#include <SDL3_image/SDL_image.h>
#include <SDL3_ttf/SDL_ttf.h>
#include <vector>
#include <memory>
#include <map>

class Sprite;
typedef std::shared_ptr<Sprite> SpritePtr;

class MoveableSprite;
typedef std::shared_ptr<MoveableSprite> MovSpritePtr;

class GameEngine
{
public:
    GameEngine(const char *title);
    ~GameEngine();

    SDL_Renderer *getRen() const { return ren; }
    std::vector<SpritePtr> getSprites() { return sprites; }
    SDL_Texture *getTexture(const char *path);

    void addSprite(SpritePtr);

    void run();
    void quit() { running = false; }

    SDL_Texture *getSpriteTexture(std::string);

private:
    SDL_Window *win;
    SDL_Renderer *ren;

    const char *title;
    bool running = true;

    // vector holding all active sprites
    std::vector<SpritePtr> sprites;

    // vector holding all sprites waiting to be added
    std::vector<SpritePtr> addedSprites;

    // sprite texture cache
    std::map<std::string, SDL_Texture *> spriteTextures;
};
