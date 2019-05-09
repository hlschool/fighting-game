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

			const Uint8 *keystate = SDL_GetKeyboardState(NULL);

			//background rectangle
			rectangle background = { width, height };
			background.setColor(70, 70, 70);

			character *steve_1 = new character();
			steve_1->moveTo({ (width / 2) - (float)(steve_1->w / 2) - 300 , 0 });

			character *steve_2 = new character();
			steve_2->moveTo({ (width / 2) - (float)(steve_2->w / 2) + 300 , 0 });

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

			playing_field.addCharacter(steve_1);
			playing_field.addCharacter(steve_2);

			playing_field.addPlatform(floor);
			playing_field.addPlatform(pl1);
			playing_field.addPlatform(right_wall);
			playing_field.addPlatform(left_wall);

			TTF_Init();
			TTF_Font* Sans = TTF_OpenFont("OpenSans-Bold.ttf", 24);

			float vel_x_1 = 0;
			float vel_x_2 = 0;
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

						//steve_1
						if (evt.key.keysym.sym == SDLK_w) {
							if(evt.key.repeat == 0 && playing_field.hitsPlatform(*steve_1, nullptr, nullptr, nullptr)) {
								steve_1->push({ 0, -7 });
							}
						}
						else if (evt.key.keysym.sym == SDLK_g && keystate[SDL_SCANCODE_S]) {
							if (evt.key.repeat == 0) {
								steve_1->attack(true);
							}
						}
						else if (evt.key.keysym.sym == SDLK_g) {
							if (evt.key.repeat == 0) {
								steve_1->attack(false);
							}
						}
						else if (evt.key.keysym.sym == SDLK_a) {
							if (evt.key.repeat == 0) {
								vel_x_1 += -10;
							}
						}
						else if (evt.key.keysym.sym == SDLK_d) {
							if (evt.key.repeat == 0) {
								vel_x_1 += 10;
							}
						}

						//steve_2
						if (evt.key.keysym.sym == SDLK_UP) {
							if (evt.key.repeat == 0 && playing_field.hitsPlatform(*steve_2, nullptr, nullptr, nullptr)) {
								steve_2->push({ 0, -7 });
							}
						}
						else if (evt.key.keysym.sym == SDLK_KP_0 && keystate[SDL_SCANCODE_DOWN]) {
							if (evt.key.repeat == 0) {
								steve_2->attack(true);
							}
						}
						else if (evt.key.keysym.sym == SDLK_KP_0) {
							if (evt.key.repeat == 0) {
								steve_2->attack(false);
							}
						}
						else if (evt.key.keysym.sym == SDLK_LEFT) {
							if (evt.key.repeat == 0) {
								vel_x_2 += -10;
							}
						}
						else if (evt.key.keysym.sym == SDLK_RIGHT) {
							if (evt.key.repeat == 0) {
								vel_x_2 += 10;
							}
						}
					}
					if (evt.type == SDL_KEYUP) {

						//steve_1
						if (evt.key.keysym.sym == SDLK_a) {
							if (evt.key.repeat == 0) {
								vel_x_1 += 10;
							}
						}
						else if (evt.key.keysym.sym == SDLK_d) {
							if (evt.key.repeat == 0) {
								vel_x_1 += -10;
							}
						}

						//steve_2
						if (evt.key.keysym.sym == SDLK_LEFT) {
							if (evt.key.repeat == 0) {
								vel_x_2 += 10;
							}
						}
						else if (evt.key.keysym.sym == SDLK_RIGHT) {
							if (evt.key.repeat == 0) {
								vel_x_2 += -10;
							}
						}
					}
					
				}
				steve_1->vel.x = vel_x_1;
				steve_2->vel.x = vel_x_2;

				playing_field.update();
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

