
#include "RoundSprite.h"
#include "Constants.h"
#include "GameEngine.h"
#include "Player.h"
#include "Bullet.h"
#include "Enemy.h"
#include "Earth.h"
#include <cmath>
#include <iostream>

namespace cnts = constants;

Player::Player(GameEngine *engine, std::string name, const char *path, float x, float y) : RoundSprite(engine, name, path, x, y) {}

void Player::onCollision(Sprite& other) {
    if (dynamic_cast<Enemy*>(&other)) {
        bounceFrom(other);
        takeDamage();
    }

    if (dynamic_cast<Earth*>(&other)) {
        bounceFrom(other);
        takeDamage();
    }
}

void Player::bounceFrom(Sprite &other)
{
    SDL_FRect &myRect = getRect();
    float myCenterX = myRect.x + (myRect.w / 2.0f);
    float myCenterY = myRect.y + (myRect.h / 2.0f);

    SDL_FRect &otherRect = other.getRect();
    float otherCenterX = otherRect.x + (otherRect.w / 2.0f);
    float otherCenterY = otherRect.y + (otherRect.h / 2.0f);

    // calculating direction player should bounce from
    float dirX = myCenterX - otherCenterX;
    float dirY = myCenterY - otherCenterY;

    // normalize vector to 1 so it doesn't bounce off screen
    float length = std::sqrt(dirX * dirX + dirY * dirY);
    if (length != 0)
    {
        dirX /= length;
        dirY /= length;
    }

    float pushDistance = 15.0f; // ensure that player no longer colliding in next frame
    rect.x += dirX * pushDistance;
    rect.y += dirY * pushDistance;

    // bounce player
    float bounceForce = 10.0f;
    vx = dirX * bounceForce;
    vy = dirY * bounceForce;
}

void Player::takeDamage() {
    health -= 10;
    if (health <= 0) {
        engine->quit();
    }
}

void Player::tick()
{

    SDL_FRect &r = getRect();

    const bool *state = SDL_GetKeyboardState(NULL);

    if (state[SDL_SCANCODE_W])
    {
        vy -= speed;
    }
    if (state[SDL_SCANCODE_A])
    {
        vx -= speed;
    }
    if (state[SDL_SCANCODE_S])
    {
        vy += speed;
    }
    if (state[SDL_SCANCODE_D])
    {
        vx += speed;
    }

    if (vx > maxSpeed) { vx = maxSpeed; }
    if (vx < -maxSpeed) { vx = -maxSpeed; }
    if (vy > maxSpeed) { vy = maxSpeed; }
    if (vy < -maxSpeed) { vy = -maxSpeed; }

    move(vx, vy);

    vx *= friction;
    vy *= friction;

    // no out of bounds for player sprite
    if (r.x < 0)
    {
        r.x = 0;
    }
    else if (r.x + r.w > cnts::gScreenWidth)
    {
        r.x = cnts::gScreenWidth - r.w;
    }

    if (r.y < 0)
    {
        r.y = 0;
    }
    else if (r.y + r.h > cnts::gScreenHeight)
    {
        r.y = cnts::gScreenHeight - r.h;
    }

    // rotating player to it always faces mouse cursor
    // mouse cursor current position
    float mouseX, mouseY;
    SDL_MouseButtonFlags mouseState = SDL_GetMouseState(&mouseX, &mouseY);

    // center of sprite
    float centerX = r.x + (r.w / 2);
    float centerY = r.y + (r.h / 2);

    // calculate distance between sprite and cursor
    float dx = mouseX - centerX;
    float dy = mouseY - centerY;

    // calculating angle in radians
    double angleRadians = std::atan2(dy, dx);

    // converting to degrees for SDL
    double angleDegrees = angleRadians * (180.0 / M_PI);
    // + 90 because ship points up, otherwise would point to left
    rotationAngle = angleDegrees + 90;

    // shooting logic
    if (reloadTimer > 0) { reloadTimer--; }

    if ((mouseState & SDL_BUTTON_LMASK) && reloadTimer == 0) {
        reloadTimer = 10;

        float spawnX = rect.x + (rect.w / 2) - 5;
        float spawnY = rect.y + (rect.h / 2) - 5;

        auto bullet = std::make_shared<Bullet>(engine, spawnX, spawnY, rotationAngle);
        engine->addSprite(bullet);
    }
}
