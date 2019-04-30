/*This source code copyrighted by Lazy Foo' Productions (2004-2019)
and may not be redistributed without written permission.*/

//Using SDL and standard IO
#include <SDL.h>
#include <stdio.h>
#include "vector.h"

//Screen dimension constants
const int width = 640;
const int height = 480;

int main(int argc, char* args[])
{
	//The window we'll be rendering to
	SDL_Window* window = NULL;

	//The surface contained by the window
	SDL_Surface* screenSurface = NULL;

	SDL_Renderer* gRenderer = NULL;

	const vector grav_acc = { 0, 0.00001 };

	vector pos = { width / 4, 0 };
	vector vel = { 0, 0 };
	vector acc = grav_acc;


	//Initialize SDL
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
	}
	else
	{
		//Create window
		window = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_SHOWN);
		if (window == NULL)
		{
			printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
		}
		else
		{
			//Get window surface
			screenSurface = SDL_GetWindowSurface(window);

			gRenderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

			SDL_Rect backRect = { 0, 0, width, height };
			SDL_SetRenderDrawColor(gRenderer, 90, 90, 90, 0xFF);
			SDL_RenderFillRect(gRenderer, &backRect);

			SDL_Rect fillRect = { pos.x, pos.y, width / 2, height / 2 };
			SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
			SDL_RenderFillRect(gRenderer, &fillRect);


			SDL_Event evt;
			bool programrunning = true;
			while (programrunning)
			{

				while (SDL_PollEvent(&evt)) {
					if (evt.type == SDL_QUIT)
						programrunning = false;
					else if (evt.type == SDL_MOUSEBUTTONDOWN) {
						if (evt.button.button == SDL_BUTTON_LEFT) {
							acc.x += 0.01;
						}
						
					}
				}

				pos += vel;
				vel += acc;
				acc = grav_acc;

				SDL_SetRenderDrawColor(gRenderer, 90, 90, 90, 0xFF);
				SDL_RenderFillRect(gRenderer, &backRect);

				fillRect.x = pos.x;
				fillRect.y = pos.y;
				SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
				SDL_RenderFillRect(gRenderer, &fillRect);

				//Update the surface
				SDL_RenderPresent(gRenderer);
				
			}
		}
	}

	//Destroy window
	SDL_DestroyWindow(window);

	//Quit SDL subsystems
	SDL_Quit();

	return 0;
}