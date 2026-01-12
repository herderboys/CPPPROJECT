#include "Sprite.h"

class Earth : public Sprite
{
public:
    using Sprite::Sprite;
    void takeDamage();
    int getHealth() { return health; }
    void onCollision(Sprite& other) override;

private:
    int health = 500;
};