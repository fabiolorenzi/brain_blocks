#include "Renderer.h"

Renderer::Renderer(SDL_Window* window)
{
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (renderer == NULL) {
        SDL_Log("Accelerated renderer could not be created! SDL_Error: %s\nSwitching to software renderer", SDL_GetError());
        renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_SOFTWARE);
    }

    if (renderer == NULL) {
        printf("Renderer could not be created! SDL Error: %s\n", SDL_GetError());
    } else {
        SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
        int imgFlags = IMG_INIT_PNG;
        if (!(IMG_Init(imgFlags) && imgFlags)) {
            printf("SDL_image could not initialize! SDL_Error: %s\n", SDL_GetError());
        }
    }
}

Renderer::~Renderer()
{
    SDL_DestroyRenderer(renderer);
    IMG_Quit();
}

void Renderer::Reset()
{
    SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
	SDL_RenderClear(renderer);
}

void Renderer::Draw(int x, int y, int width, int height, Uint8 r, Uint8 g, Uint8 b, Uint8 a)
{
    SDL_Rect drawing = {x, y, width, height};
    SDL_SetRenderDrawColor(renderer, r, g, b, a);		
	SDL_RenderFillRect(renderer, &drawing);
}

void Renderer::Draw(Player* player)
{
    SDL_Rect drawing = {player->x, player->y, player->width, player->height};
    SDL_SetRenderDrawColor(renderer, player->r, player->g, player->b, player->a);
    SDL_RenderFillRect(renderer, &drawing);
    SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0x00, 0x00);
    SDL_RenderDrawRect(renderer, &drawing);
}

void Renderer::Draw(Wall* wall)
{
    SDL_Rect drawing = {wall->x, wall->y, wall->width, wall->height};
    SDL_SetRenderDrawColor(renderer, wall->r, wall->g, wall->b, wall->a);
    SDL_RenderFillRect(renderer, &drawing);
    SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0x00, 0x00);
    SDL_RenderDrawRect(renderer, &drawing);
}