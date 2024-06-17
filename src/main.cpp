#define SDL_MAIN_HANDLED true

#include "classes/Window.h"

int main() {
    Window* window = new Window();
    window->LoadMedia();

    delete window;

    return 0;
}