#include "Constants.h"
#include "GameEngine.h"
#include "Sprite.h"
#include "Player.h"
#include <iostream>

namespace cnts = constants;

int main() {

    GameEngine game("Alien Attack!");

    auto earth = std::make_shared<Sprite>(
        &game, "earth", cnts::earthTexture.c_str(), 
        (cnts::gScreenWidth / 2) - 72, (cnts::gScreenHeight / 2));
    
        game.addSprite(earth);

    auto player = std::make_shared<Player>(
        &game, "player", cnts::playerShipTexture.c_str(), 
        (cnts::gScreenWidth / 2) - 72, (cnts::gScreenHeight / 2) - 72);

        game.addSprite(player);

    game.run();
}