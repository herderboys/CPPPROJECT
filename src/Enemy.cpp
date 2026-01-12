#include "Enemy.h"
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