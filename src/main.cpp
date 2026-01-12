#include "Constants.h"
#include "GameEngine.h"
#include "Spawner.h"
#include "Sprite.h"
#include "Earth.h"
#include "Player.h"
#include <iostream>

namespace cnts = constants;

int main()
{

    GameEngine game("Alien Attack!");

    auto earth = std::make_shared<Earth>(&game, "earth", cnts::earthTexture.c_str(), 0, 0);

    // setting position of earth
    // honestly not very much though behind math for setting x and y pos,
    // this is what looked best when I tested different numbers
    earth->getRect().x = ((cnts::gScreenWidth / 2) - (earth->getRect().w / 2) - 50);
    earth->getRect().y = (earth->getRect().h / 2.1);

    game.addSprite(earth);

    auto player = std::make_shared<Player>(&game, "player", cnts::playerShipTexture.c_str(),(cnts::gScreenWidth / 2) - 72, (cnts::gScreenHeight / 2) - 72); // magic number, fix

    game.addSprite(player);

    auto spawner = std::make_shared<Spawner>(&game);
    game.addSprite(spawner);

    game.run();
    return 0;
}