
#include "Sprite.h"
#include "Constants.h"
#include "Player.h"
#include <iostream>


Player::Player(std::string name, std::string texture, float x, float y ) : Sprite(name, texture, x, y) {
    name = "player";
    texture = "playerShip";

}