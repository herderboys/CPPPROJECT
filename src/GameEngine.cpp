#include <iostream>
#include <map>
#include "Constants.h"
#include "Player.h"
#include "Earth.h"
#include "Enemy.h"
#include "Bullet.h"
#include "Sprite.h"
#include "GameEngine.h"

namespace cnts = constants;

GameEngine::GameEngine(const char *title)
{
    win = SDL_CreateWindow(title, cnts::gScreenWidth, cnts::gScreenHeight, 0);
    ren = SDL_CreateRenderer(win, NULL);
}

GameEngine::~GameEngine()
{
    SDL_DestroyRenderer(ren);
    SDL_DestroyWindow(win);
}

SDL_Texture *GameEngine::getTexture(const char *path)
{
    if (spriteTextures.find(path) == spriteTextures.end())
    {
        SDL_Texture *texture = IMG_LoadTexture(ren, path);
        spriteTextures[path] = texture;
    }
    return spriteTextures[path];
}

void GameEngine::addSprite(SpritePtr sprite)
{
    addedSprites.push_back(sprite);
}

// game loop
void GameEngine::run()
{

    const int FPS = 60;
    const int TICKINTERVAL = 1000 / FPS;
    int frameStart;
    int frameTime;

    while (running)
    {
        frameStart = SDL_GetTicks();

        if (!addedSprites.empty())
        {
            sprites.insert(sprites.end(), addedSprites.begin(), addedSprites.end());
            addedSprites.clear();
        }

        // removing removed sprites
        auto it = std::remove_if(sprites.begin(), sprites.end(), [](const SpritePtr &s)
                                 { return s->isRemoved(); });
        sprites.erase(it, sprites.end());

        SDL_RenderClear(ren);

        SDL_Event event;

        while (SDL_PollEvent(&event))
        {

            if (event.type == SDL_EVENT_QUIT)
            {
                running = false;
                break;
            }
        }

        for (auto &sprite : sprites)
        {
            sprite->tick();
            sprite->draw();
            for (auto &other : sprites)
            {
                if (sprite.get() == other.get())
                {
                    continue;
                }

                if (sprite->collidedWith(*other))
                {
                    sprite->onCollision(*other);
                    other->onCollision(*sprite);
                }
            }
        }

        SDL_RenderPresent(ren);

        // capping at 60fps so physics works the same independently of monitor refresh rate
        frameTime = SDL_GetTicks() - frameStart;

        if (TICKINTERVAL > frameTime)
        {
            SDL_Delay(TICKINTERVAL - frameTime);
        }
    }
}

// find texture for Sprite
SDL_Texture *GameEngine::getSpriteTexture(std::string texture)
{
    return spriteTextures.at(texture);
}
