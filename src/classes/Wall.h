#pragma once

#include <SDL.h>

class Wall
{
    public:
        int x, y, width, height;
        Uint8 r, b, g, a;
        Wall(int _x, int _y, int _width, int _height, Uint8 _r, Uint8 _g, Uint8 _b, Uint8 _a);
};