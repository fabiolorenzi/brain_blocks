#define SDL_MAIN_HANDLED true

#include <SDL.h>
#include "classes/Window.h"
#include "functions/KeysManager.h"

int main() {
    SDL_SetMainReady();
    bool isRunning = true;
    Window* window = new Window();
    window->LoadMedia("assets/images/press.bmp");

    std::string images[5] = {"press", "up", "down", "left", "right"};

    while (isRunning) {
        SDL_Event e;
        while (SDL_PollEvent(&e) != 0) {
            if (e.type == SDL_QUIT) {
                isRunning = false;
            } else if (e.type == SDL_KEYDOWN) {
                window->LoadMedia("assets/images/" + images[KeyDownManager(e)] + ".bmp");
            }
        }
    }

    delete window;

    return 0;
}