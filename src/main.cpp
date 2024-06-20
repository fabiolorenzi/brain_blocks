#define SDL_MAIN_HANDLED true

#include <SDL.h>
#include "classes/Window.h"
#include "functions/KeysManager.h"

int main() {
    SDL_SetMainReady();
    bool isRunning = true;
    Window* window = new Window();
    window->LoadMedia("assets/textures/texture.png");
    int x {0};

    while (isRunning) {
        SDL_Event e;
        while (SDL_PollEvent(&e) != 0) {
            if (e.type == SDL_QUIT) {
                isRunning = false;
            } else if (e.type == SDL_KEYDOWN) {
                window->player->SetMove(KeyDownManager(e));
            } else if (e.type == SDL_KEYUP) {
                window->player->SetMove(0);
            }
        }
        window->player->Move();
        window->RenderElements();
    }

    delete window;

    return 0;
}