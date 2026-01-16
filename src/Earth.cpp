#include "Earth.h"
#include "Player.h"
#include "Enemy.h"
#include "Bullet.h"
#include "GameEngine.h"

void Earth::takeDamage() {
    health -= 10;
    if (health <= 0) {
        engine->quit();
    }
}

void Earth::onCollision(Sprite& other) {
    if (dynamic_cast<Player*>(&other)) {
        takeDamage();
    }

    if (dynamic_cast<Enemy*>(&other)) {
        takeDamage();
    }

    if (dynamic_cast<Bullet*>(&other)) {
        takeDamage();
    }
}