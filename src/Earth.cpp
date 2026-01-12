#include "Earth.h"
#include "GameEngine.h"


void Earth::takeDamage() {
    health -= 10;
    if (health <= 0) {
        engine->quit();
    }
}