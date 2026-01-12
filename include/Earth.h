#include "Sprite.h"

class Earth : public Sprite
{
public:
    using Sprite::Sprite;
    void takeDamage();
    int getHealth() { return health; }

private:
    int health = 5000;
};