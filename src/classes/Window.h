#pragma once

#include <SDL.h>
#include <stdio.h>
#include <iostream>
#include "Player.h"
#include "Renderer.h"
#include "Wall.h"

class Window
{
    public:
        Player* player;
        Wall* floor;
        Wall* wallLeft;
        Wall* wallRight;
        Window();
        ~Window();
        int LoadMedia(std::string imagePath);
        SDL_Texture* LoadTexture(std::string texturePath);
        void RenderElements();
    private:
        int width;
        int height;
        SDL_Window* gWindow;
        SDL_Surface* gScreenSurface;
        SDL_Surface* gStretched;
        Renderer* gRenderer;

        int Init();
        SDL_Surface* LoadSurface(std::string imagePath);
};