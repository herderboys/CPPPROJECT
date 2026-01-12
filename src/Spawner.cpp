#include "Constants.h"
#include "Spawner.h"
#include "GameEngine.h"
#include "Enemy.h"
#include <cstdlib>

Spawner::Spawner(GameEngine *engine) : Sprite(engine, "Spawner", "", 0, 0) {}

void Spawner::draw() const {}

void Spawner::tick() {
    spawnTimer++;
    if (spawnTimer > 500) {
        spawnEnemy();
        spawnTimer = 0;
    }
}

void Spawner::spawnEnemy()
{
    // random x spot within width
    // had to to width - 50 so it doesn't spawn half off edge
    float x = static_cast<float>(rand() % (constants::gScreenWidth - 50));

    auto enemy = std::make_shared<Enemy>(engine, x, -50.0f); // so it spawns over window

    engine->addSprite(enemy);
}