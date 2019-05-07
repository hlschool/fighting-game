/*This source code copyrighted by Lazy Foo' Productions (2004-2019)
and may not be redistributed without written permission.*/

//Using SDL and standard IO
//hey guys this is my first try -jim
#include <SDL.h>
#include <SDL_ttf.h>
#include <stdio.h>
#include <ctime>
#include <iostream>
#include <string>
#include <chrono>
#include "vector.h"
#include "rectangle.h"
#include "field.h"
#include "platform.h"
using namespace std;

//Screen dimension constants
const int width = 1080;
const int height = 720;

const int fps_lock = 60;
const double spf = 1 / (double)fps_lock;

const vector grav_acc = { 0, 0.2 };

const SDL_Color white = { 255, 255, 255 }; //asdasdasdasdasdasdasdasdasdasdassdfgdfgfdgdfgdefjgldisfjhglksdjfhgldksjfhglkjdsfhgkdjshlgkjsdlhksdjfhlgkj

int main(int argc, char* args[])
{
	//The window we'll be rendering to
	SDL_Window* window = NULL;

	//The renderer which draws shapes
	SDL_Renderer* gRenderer = NULL;

	int frames = 0;
	int fps_count = 0;

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
			//Creating renderer...
			gRenderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

			//background rectangle
			rectangle background = { width, height };
			background.setColor(70, 70, 70);

			rectangle *r = new rectangle(250, 250);
			r->moveTo({ (width / 2) - (float)(r->w / 2) , 0 });

			rectangle *floor = new rectangle(width, 70);
			floor->fixed = true;
			floor->setColor(35, 35, 35);
			floor->moveTo({ 0, 650 });

			platform *pl1 = new platform(250, 100);
			pl1->fixed = true;
			pl1->setColor(35, 35, 35);
			pl1->moveTo({ 0, 0 });

			field playing_field;
			playing_field.setBackground(background);
			playing_field.setGravity(grav_acc);
			playing_field.add(r);
			playing_field.add(floor);
			playing_field.add(pl1);

			TTF_Init();
			TTF_Font* Sans = TTF_OpenFont("OpenSans-Bold.ttf", 24);


			//Main loop
			SDL_Event evt;
			bool programrunning = true;
			while (programrunning)
			{
				auto start = chrono::high_resolution_clock::now();

				while (SDL_PollEvent(&evt)) {
					if (evt.type == SDL_QUIT)
						programrunning = false;
					else if (evt.type == SDL_KEYDOWN) {
						if (evt.key.keysym.sym == SDLK_SPACE) {
							if(evt.key.repeat == 0) {
								r->push({ 0, -6 });
							}
							
						}
						
					}
				}
				
				playing_field.update();
				if (r->collidesWith(*floor, nullptr, nullptr)) {
					r->setColor(255, 0, 0);
				} else {
					r->setColor(255, 255, 255);
				}
				playing_field.draw(gRenderer);

				//FPS counter
				string fps_string = to_string(fps_count);
				const char* fps_char = fps_string.c_str();
				SDL_Surface* message_surf = TTF_RenderText_Solid(Sans, fps_char, white);
				SDL_Texture* message = SDL_CreateTextureFromSurface(gRenderer, message_surf);
				SDL_FreeSurface(message_surf);
				SDL_Rect message_rect = { 0, 0, 100, 100 };
				SDL_RenderCopy(gRenderer, message, NULL, &message_rect);

				//Update the surface
				SDL_RenderPresent(gRenderer);
				
				auto f_finish = chrono::high_resolution_clock::now();
				chrono::nanoseconds f_elapsed = f_finish - start;
				double f_elapsed_s = f_elapsed.count() * 1E-9;
				if(f_elapsed_s < spf) {
					SDL_Delay((spf - f_elapsed_s) * 1000);
				}

				auto finish = chrono::high_resolution_clock::now();
				chrono::nanoseconds elapsed = finish - start;
				double elapsed_s = elapsed.count() * 1E-9;
				fps_count = 1 / elapsed_s;
				
			}
		}
	}

	//Destroy window
	SDL_DestroyWindow(window);

	//Quit SDL subsystems
	SDL_Quit();

	return 0;
}