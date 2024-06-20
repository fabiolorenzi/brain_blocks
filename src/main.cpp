#define SDL_MAIN_HANDLED true

#include <SDL.h>
#include "classes/Window.h"
#include "functions/KeysManager.h"

int main() {
    SDL_SetMainReady();
    bool isRunning = true;
    Window* window = new Window();
    window->LoadMedia("assets/textures/texture.png");

    while (isRunning) {
        SDL_Event e;
        while (SDL_PollEvent(&e) != 0) {
            if (e.type == SDL_QUIT) {
                isRunning = false;
            }
        }

        window->RenderSquares();
    }

    delete window;

    return 0;
}