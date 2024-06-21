#include "Player.h"

Player::Player(int _x, int _y, int _width, int _height, Uint8 _r, Uint8 _g, Uint8 _b, Uint8 _a, int _maxHeight)
{
    x = _x;
    y = _y;
    width = _width;
    height = _height;
    r = _r;
    g = _g;
    b = _b;
    a = _a;
    horiSpeed = 2;
    verSpeed = -10;
    maxHeight = _maxHeight;
    isMovingLeft = false;
    isMovingRight = false;
    isTouchingFloor = false;
    isJumping = true;
    body = {x, y, width, height};
}

void Player::CheckWallsCollisions(std::vector<Wall*> walls)
{
    const SDL_Rect* playerBody = &body;
    for (Wall* wall : walls) {
        const SDL_Rect* wallBody = wall->GetBody();
        if (SDL_HasIntersection(playerBody, wallBody) && isMovingLeft && !wall->isFloor) {
            x += 10;
        } else if (SDL_HasIntersection(playerBody, wallBody) && isMovingRight && !wall->isFloor) {
            x -= 10;
        } else if (SDL_HasIntersection(playerBody, wallBody) && wall->isFloor) {
            isTouchingFloor = true;
        }
    }
}

void Player::SetMove(int moveIndex)
{
    if (moveIndex == 3) {
        isMovingLeft = true;
        isMovingRight = false;
    } else if (moveIndex == 4) {
        isMovingLeft = false;
        isMovingRight = true;
    } else if (moveIndex == 0) {
        isMovingLeft = false;
        isMovingRight = false;
    }
}

void Player::Move()
{
    if (isMovingLeft) {
        x -= horiSpeed;
        body.x = x;
    } else if (isMovingRight) {
        x += horiSpeed;
        body.x = x;
    }

    if (isTouchingFloor || y > maxHeight - (height + 20)) {
        verSpeed = 0;
        isJumping = false;
    } else {
        isJumping = true;
        y -= verSpeed;
        body.y = y;
    }
}