#pragma once

#include <SDL.h>
#include <stdio.h>
#include <iostream>
#include <vector>
#include "Wall.h"

class Player
{
    public:
        int x, y, width, height;
        Uint8 r, b, g, a;
        SDL_Rect body;
        Player(int _x, int _y, int _width, int _height, Uint8 _r, Uint8 _g, Uint8 _b, Uint8 _a, int _maxHeight);
        void CheckWallsCollisions(std::vector<Wall*> walls);
        void SetMove(int moveIndex);
        void Move();
    private:
        bool isMovingLeft, isMovingRight, isTouchingFloor;
        bool isJumping;
        int horiSpeed, verSpeed;
        int maxHeight;
};