#include "Enemy.h"
#include "Player.h"
#include "Earth.h"
#include "Bullet.h"
#include "Constants.h"

Enemy::Enemy(GameEngine* engine, float x, float y) : 
Sprite(engine, "enemy", constants::enemyShipTexture.c_str(), x, y) {}
 
void Enemy::tick() {
    float speed = 0.3f;
    move(0, speed);

    if (getRect().y > 1080) {
        remove();
    }
    
}

void Enemy::onCollision(Sprite& other) {
    if (dynamic_cast<Player*>(&other)) {
        remove();
    }

    if (dynamic_cast<Bullet*>(&other)) {
        remove();
    }

    if (dynamic_cast<Earth*>(&other)) {
        remove();
    }
}