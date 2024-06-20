#define SDL_MAIN_HANDLED true

#include <SDL.h>
#include "classes/Timer.h"
#include "classes/Window.h"
#include "functions/KeysManager.h"

int main() {
    SDL_SetMainReady();
    bool isRunning = true;
    Window* window = new Window();
    Timer* timer = new Timer();
    window->LoadMedia("assets/textures/texture.png");

    while (isRunning) {
        timer->ResetStartLoop();
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
        timer->BalanceFps();
    }

    delete timer;
    delete window;

    return 0;
}