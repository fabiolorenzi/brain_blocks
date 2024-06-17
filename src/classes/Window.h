#pragma once

#include <SDL.h>
#include <stdio.h>
#include <iostream>

class Window
{
    public:
        Window();
        ~Window();
        int LoadMedia(std::string image);
    private:
        int width;
        int height;
        SDL_Window* gWindow;
        SDL_Surface* gScreenSurface;
        SDL_Surface* gHelloWorld;

        int Init();
};