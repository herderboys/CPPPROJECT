#include <iostream>
#include <map>
#include "Constants.h"
#include "GameEngine.h"

GameEngine::GameEngine()
{
    win = SDL_CreateWindow("Alien Attack", cnts::gScreenWidth, cnts::gScreenHeight, 0);
    ren = SDL_CreateRenderer(win, NULL);

    spriteTextures["playerShip"] = IMG_LoadTexture(ren, cnts::playerShipTexture.c_str());
    spriteTextures["ememyShip"] = IMG_LoadTexture(ren, cnts::enemyShipTexture.c_str());
    spriteTextures["earth"] = IMG_LoadTexture(ren, cnts::earthTexture.c_str());
    spriteTextures["background"] = IMG_LoadTexture(ren, cnts::backgroundTexture.c_str());
}

GameEngine::~GameEngine()
{
    SDL_DestroyRenderer(ren);
    SDL_DestroyWindow(win);
}

// game loop
void GameEngine::run()
{

    const int FPS = 60;
    const int TICKINTERVAL = 1000 / FPS;

    bool running = true;
    while (running)
    {
        SDL_Event event;

        while (SDL_PollEvent(&event))
        {
            switch (event.type)
            {
            case SDL_EVENT_QUIT:
                running = false;
                break;
            // case ...
            case SDL_EVENT_KEY_DOWN:
                if (event.key.key == SDLK_W)
                {
                    // move up
                }
                if (event.key.key == SDLK_A)
                {
                    // move left
                }
                if (event.key.key == SDLK_S)
                {
                    // move down
                }
                if (event.key.key == SDLK_D)
                {
                    // move right
                }
            }
        }
    }
}

// find texture for Sprite
SDL_Texture *GameEngine::getSpriteTexture(std::string texture)
{
    return spriteTextures.at(texture);
}