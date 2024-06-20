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
}

Player::~Player()
{
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
        x -= 1;
    } else if (isMovingRight) {
        x += 1;
    }
}