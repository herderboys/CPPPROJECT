#pragma once
#include "Sprite.h"

class Spawner : public Sprite
{

public:
    Spawner(GameEngine *engine);

    void tick() override;
    void draw() const override;

private:
    int spawnTimer = 0;
    void spawnEnemy();
};