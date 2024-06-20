#pragma once

#include <SDL.h>
#include <stdio.h>
#include <iostream>

class Window
{
    public:
        Window();
        ~Window();
        int LoadMedia(std::string imagePath);
    private:
        int width;
        int height;
        SDL_Window* gWindow;
        SDL_Surface* gScreenSurface;
        SDL_Surface* gStretched;

        int Init();
        SDL_Surface* LoadSurface(std::string imagePath);
};