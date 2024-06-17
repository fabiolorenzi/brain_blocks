#include "KeysManager.h"

int KeyDownManager(SDL_Event e)
{
    switch (e.key.keysym.sym) {
        case SDLK_UP:
            return KeyCodes::KEY_PRESS_SURFACE_UP;
            break;
        case SDLK_DOWN:
            return KeyCodes::KEY_PRESS_SURFACE_DOWN;
            break;
        case SDLK_LEFT:
            return KeyCodes::KEY_PRESS_SURFACE_LEFT;
            break;
        case SDLK_RIGHT:
            return KeyCodes::KEY_PRESS_SURFACE_RIGHT;
            break;
        default:
            return KeyCodes::KEY_PRESS_SURFACE_DEFAULT;
            break;
    }
}