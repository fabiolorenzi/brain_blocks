#include "Window.h"

Window::Window()
{
    width = 1280;
    height = 720;

    Init();
}

Window::~Window()
{
    SDL_FreeSurface( gHelloWorld );
	gHelloWorld = NULL;
	SDL_DestroyWindow( gWindow );
	gWindow = NULL;
	SDL_Quit();
}

int Window::Init()
{
    if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
	{
		printf( "SDL could not initialize! SDL_Error: %s\n", SDL_GetError() );
		return -1;
	}
	else
	{
		gWindow = SDL_CreateWindow(
            "Test",
            SDL_WINDOWPOS_CENTERED,
            SDL_WINDOWPOS_CENTERED,
            width,
            height,
            SDL_WINDOW_SHOWN
        );

		if(gWindow == NULL) {
			printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
			return -1;
		} else {
			gScreenSurface = SDL_GetWindowSurface(gWindow);
		}
	}
	return 0;
}

int Window::LoadMedia()
{
    gHelloWorld = SDL_LoadBMP("assets/images/test.bmp");
	if (gHelloWorld == NULL) {
		printf( "Unable to load image %s! SDL Error: %s\n", "assets/images/test.bmp", SDL_GetError());
		return -1;
	}
	SDL_BlitSurface(gHelloWorld, NULL, gScreenSurface, NULL);
	SDL_UpdateWindowSurface(gWindow);
	SDL_Delay(10000);
    return 0;
}