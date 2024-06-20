#pragma once

#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>

class Renderer {
    public:
        Renderer(SDL_Window* window);
        ~Renderer();
        SDL_Renderer* renderer;
};