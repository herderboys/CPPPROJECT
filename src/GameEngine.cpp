#include <iostream>
#include <map>
#include "Constants.h"
#include "Sprite.h"
#include "GameEngine.h"

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
    sprites.push_back(sprite);
}

// game loop
void GameEngine::run()
{

    // const int FPS = 60;
    // const int TICKINTERVAL = 1000 / FPS;

    bool running = true;

    while (running)
    {
        SDL_RenderClear(ren);

        SDL_Event event;

        while (SDL_PollEvent(&event))
        {

            if (event.type == SDL_EVENT_QUIT) {
                running = false;
                break;
            }
            /*

            */
        }


        for (auto &sprite : sprites)
        {
            sprite->tick();
            sprite->draw();
        }

        SDL_RenderPresent(ren);
    }
}

// find texture for Sprite
SDL_Texture *GameEngine::getSpriteTexture(std::string texture)
{
    return spriteTextures.at(texture);
}
