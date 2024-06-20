#pragma once

#include <SDL.h>
#include <stdio.h>
#include <iostream>

class Player
{
    public:
        int x, y, width, height;
        Uint8 r, b, g, a;
        Player(int _x, int _y, int _width, int _height, Uint8 _r, Uint8 _g, Uint8 _b, Uint8 _a);
        void SetMove(int moveIndex);
        void Move();
    private:
        bool isMovingLeft, isMovingRight;
};