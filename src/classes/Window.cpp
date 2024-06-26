#include "Window.h"

Window::Window()
{
    width = 1280;
    height = 720;

    Init();
}

Window::~Window()
{
	delete gRenderer;
	delete player;
	for (Wall* wall : walls) {
		delete wall;
	}
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
			walls.push_back(new Wall(0, height - 10, width, 10, 0x8B, 0x45, 0x13, 0x00, true));
			walls.push_back(new Wall(0, 0, 10, height - 10, 0x80, 0x80, 0x80, 0x00, false));
			walls.push_back(new Wall(width - 10, 0, 10, height - 10, 0x80, 0x80, 0x80, 0x00, false));
			player = new Player(40, height / 2, 40, 40, 0xFF, 0x00, 0x00, 0xFF, height);
			gRenderer = new Renderer(gWindow);
		}
	}
	return 0;
}

int Window::LoadMedia(std::string imagePath)
{
    gStretched = LoadSurface(imagePath.c_str());
	if (gStretched == NULL) {
		printf("Unable to load image %s! SDL Error: %s\n", imagePath.c_str(), SDL_GetError());
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

SDL_Texture* Window::LoadTexture(std::string texturePath)
{
	SDL_Texture* texture = NULL;
	SDL_Surface* loadedSurface = IMG_Load(texturePath.c_str());
	if (loadedSurface == NULL) {
		printf("Unable to load image %s! SDL_image Error: %s\n", texturePath.c_str(), IMG_GetError());
	} else {
		texture = SDL_CreateTextureFromSurface(gRenderer->renderer, loadedSurface);
		if (texture == NULL) {
			printf("Unable to create texture from %s! SDL Error: %s\n", texturePath.c_str(), SDL_GetError());
		}
		SDL_FreeSurface(loadedSurface);
	}
	return texture;
}

SDL_Surface* Window::LoadSurface(std::string imagePath)
{
	SDL_Surface* optimizedSurface = NULL;
	SDL_Surface* loadedSurface = IMG_Load(imagePath.c_str());
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

void Window::RenderElements()
{
	gRenderer->Reset();
	gRenderer->Draw(player);

	for (Wall* wall : walls) {
		gRenderer->Draw(wall);
	}

	SDL_RenderPresent(gRenderer->renderer);
}