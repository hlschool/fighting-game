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
#include "SDL_image.h"
#include "character.h"
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

			//rectangle *r = new rectangle(60, 120);
			//r->moveTo({ (width / 2) - (float)(r->w / 2) , 0 });

			character *steve = new character();
			steve->moveTo({ (width / 2) - (float)(steve->w / 2) , 0 });

			platform *floor = new platform(width, 70);
			floor->setColor(35, 35, 35);
			floor->moveTo({ 0, 650 });
			
			platform *right_wall = new platform(30, height);
			right_wall->setColor(35, 35, 35);
			right_wall->moveTo({ (float)(width - right_wall->w), 0 });

			platform *left_wall = new platform(30, height);
			left_wall->setColor(35, 35, 35);
			left_wall->moveTo({ 0, 0 });

			platform *pl1 = new platform(150, 70);
			pl1->setColor(35, 35, 35);
			pl1->moveTo({ (float) ((width / 2) - (pl1->w / 2)), 350 });

			field playing_field;
			playing_field.setBackground(background);
			playing_field.setGravity(grav_acc);
			playing_field.add(steve);

			playing_field.addPlatform(floor);
			playing_field.addPlatform(pl1);
			playing_field.addPlatform(right_wall);
			playing_field.addPlatform(left_wall);

			TTF_Init();
			TTF_Font* Sans = TTF_OpenFont("OpenSans-Bold.ttf", 24);

			float vel_x = 0;
			//Main loop
			SDL_Event evt;
			bool programrunning = true;
			while (programrunning)
			{
				auto start = chrono::high_resolution_clock::now();

				
				while (SDL_PollEvent(&evt)) {
					if (evt.type == SDL_QUIT)
						programrunning = false;
					
					if (evt.type == SDL_KEYDOWN) {
						if (evt.key.keysym.sym == SDLK_SPACE) {
							if(evt.key.repeat == 0 && playing_field.collides(*steve, nullptr, nullptr, nullptr)) {
								steve->push({ 0, -7 });
							}
						}
						else if (evt.key.keysym.sym == SDLK_a) {
							if (evt.key.repeat == 0) {
								vel_x += -10;
							}
						}
						else if (evt.key.keysym.sym == SDLK_d) {
							if (evt.key.repeat == 0) {
								vel_x += 10;
							}
						}
					}
					if (evt.type == SDL_KEYUP) {
						if (evt.key.keysym.sym == SDLK_a) {
							if (evt.key.repeat == 0) {
								vel_x += 10;
							}
						}
						else if (evt.key.keysym.sym == SDLK_d) {
							if (evt.key.repeat == 0) {
								vel_x += -10;
							}
						}
					}
					
				}
				steve->vel.x = vel_x;

				playing_field.update();
				int *amt = new int;
				if (playing_field.collides(*steve, nullptr, nullptr, nullptr)) {
					steve->setColor(255, 0, 0);
				} else {
					steve->setColor(255, 255, 255);
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

