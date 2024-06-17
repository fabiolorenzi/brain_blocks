#pragma once

#include <SDL.h>
#include <stdio.h>

class Window
{
    public:
        Window();
        ~Window();
        int Init();
        int LoadMedia();
        int width;
        int height;
        SDL_Window* gWindow;
        SDL_Surface* gScreenSurface;
        SDL_Surface* gHelloWorld;
};