#include "Timer.h"

Timer::Timer()
{
    fps = 60;
    desiredDelta = 1000 / fps;
    startLoop = 0;
}

void Timer::ResetStartLoop()
{
    startLoop = SDL_GetTicks();
}

void Timer::BalanceFps()
{
    int delta = SDL_GetTicks() - startLoop;
    if (delta < desiredDelta) {
        SDL_Delay(desiredDelta - delta);
    }
}