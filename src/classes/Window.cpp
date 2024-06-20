#include "Window.h"

Window::Window()
{
    width = 1280;
    height = 720;

    Init();
}

Window::~Window()
{
    SDL_FreeSurface(gStretched);
	gStretched = NULL;
	SDL_DestroyWindow(gWindow);
	gWindow = NULL;
	SDL_Quit();
}

int Window::Init()
{
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
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

int Window::LoadMedia(std::string imagePath)
{
    gStretched = LoadSurface(imagePath.c_str());
	if (gStretched == NULL) {
		printf( "Unable to load image %s! SDL Error: %s\n", imagePath, SDL_GetError());
		return -1;
	}
	SDL_Rect stretchRect;
	stretchRect.x = 0;
	stretchRect.y = 0;
	stretchRect.w = width;
	stretchRect.h = height;
	SDL_BlitScaled(gStretched, NULL, gScreenSurface, &stretchRect);
	SDL_UpdateWindowSurface(gWindow);
    return 0;
}

SDL_Surface* Window::LoadSurface(std::string imagePath)
{
	SDL_Surface* optimizedSurface = NULL;
	SDL_Surface* loadedSurface = SDL_LoadBMP(imagePath.c_str());
	if (loadedSurface == NULL) {
		printf("Unable to load image %s! SDL Error: %s\n", imagePath.c_str(), SDL_GetError());
	} else {
		optimizedSurface = SDL_ConvertSurface(loadedSurface, gScreenSurface->format, 0);
		if (optimizedSurface == NULL) {
			printf("Unable to optimize image %s! SDL Error: %s\n", imagePath.c_str(), SDL_GetError());
		}

		SDL_FreeSurface(loadedSurface);
	}

	return optimizedSurface;
}