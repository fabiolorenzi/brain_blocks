#include "Wall.h"

Wall::Wall(int _x, int _y, int _width, int _height, Uint8 _r, Uint8 _g, Uint8 _b, Uint8 _a)
{
    x = _x;
    y = _y;
    width = _width;
    height = _height;
    r = _r;
    g = _g;
    b = _b;
    a = _a;
    body = {x, y, width, height};
}

const SDL_Rect* Wall::GetBody()
{
    const SDL_Rect* constBody = &body;
    return constBody;
}