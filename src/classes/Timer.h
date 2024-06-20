#pragma once

#include <SDL.h>

class Timer
{
    public:
        int fps;
        int desiredDelta;
        int startLoop;
        Timer();
        void ResetStartLoop();
        void BalanceFps();
};