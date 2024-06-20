#include "Player.h"

Player::Player(int _x, int _y, int _width, int _height, Uint8 _r, Uint8 _g, Uint8 _b, Uint8 _a)
{
    x = _x;
    y = _y;
    width = _width;
    height = _height;
    r = _r;
    g = _g;
    b = _b;
    a = _a;
    isMovingLeft = false;
    isMovingRight = false;
    blockedDirection = 99;
    body = {x, y, width, height};
}

void Player::CheckWallsCollisions(std::vector<Wall*> walls)
{
    const SDL_Rect* playerBody = &body;
    for (Wall* wall : walls) {
        const SDL_Rect* wallBody = wall->GetBody();
        if (SDL_HasIntersection(playerBody, wallBody) && isMovingLeft) {
            blockedDirection = 3;
        } else if (SDL_HasIntersection(playerBody, wallBody) && isMovingRight) {
            blockedDirection = 4;
        }
    }
}

void Player::SetMove(int moveIndex)
{
    if (moveIndex == 3) {
        isMovingLeft = true;
        isMovingRight = false;
        blockedDirection = 99;
    } else if (moveIndex == 4) {
        isMovingLeft = false;
        isMovingRight = true;
        blockedDirection = 99;
    } else if (moveIndex == 0) {
        isMovingLeft = false;
        isMovingRight = false;
    }
}

void Player::Move()
{
    if (isMovingLeft && blockedDirection != 3) {
        x -= 1;
        body.x = x;
    } else if (isMovingRight && blockedDirection != 4) {
        x += 1;
        body.x = x;
    }
}