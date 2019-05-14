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

const vector grav_acc = { 0, 0.3 };

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

			character *fighter_1 = new character();
			fighter_1->moveTo({ (width / 2) - (float)(fighter_1->w / 2) - 300 , 0 });

			character *fighter_2 = new character();
			fighter_2->moveTo({ (width / 2) - (float)(fighter_2->w / 2) + 300 , 0 });

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

			playing_field.addCharacter(fighter_1);
			playing_field.addCharacter(fighter_2);

			playing_field.addPlatform(floor);
			playing_field.addPlatform(pl1);
			playing_field.addPlatform(right_wall);
			playing_field.addPlatform(left_wall);

			TTF_Init();
			TTF_Font* Sans = TTF_OpenFont("OpenSans-Bold.ttf", 24);

			bool hold_right_1 = false;
			bool hold_left_1 = false;
			bool hold_right_2 = false;
			bool hold_left_2 = false;
			//Main loop
			SDL_Event evt;
			bool programrunning = true;
			while (programrunning)
			{
				auto start = chrono::high_resolution_clock::now();

				while (SDL_PollEvent(&evt)) {
					if (evt.type == SDL_QUIT)
						programrunning = false;
					
					if (evt.type == SDL_KEYDOWN && evt.key.repeat == 0) {

						//steve_1
						if (evt.key.keysym.sym == SDLK_w && playing_field.hitsPlatform(*fighter_1, nullptr, nullptr, nullptr)) {
							fighter_1->push({ 0, -9 });
						}
						else if (evt.key.keysym.sym == SDLK_g && !playing_field.hitsGround(*fighter_1)) {
							fighter_1->startAttack(AERIAL);
						}
						else if (evt.key.keysym.sym == SDLK_a) {
							hold_left_1 = true;
						}
						else if (evt.key.keysym.sym == SDLK_d) {
							hold_right_1 = true;
						}

						//steve_2
						if (evt.key.keysym.sym == SDLK_UP && playing_field.hitsPlatform(*fighter_2, nullptr, nullptr, nullptr)) {
							fighter_2->push({ 0, -9 });
						}
						else if (evt.key.keysym.sym == SDLK_KP_0 && !playing_field.hitsGround(*fighter_2)) {
							fighter_2->startAttack(AERIAL);
						}
						else if (evt.key.keysym.sym == SDLK_LEFT) {
							hold_left_2 = true;
						}
						else if (evt.key.keysym.sym == SDLK_RIGHT) {
							hold_right_2 = true;
						}
					}
					if (evt.type == SDL_KEYUP && evt.key.repeat == 0) {

						//steve_1
						if (evt.key.keysym.sym == SDLK_a) {
							hold_left_1 = false;
						}
						else if (evt.key.keysym.sym == SDLK_d) {
							hold_right_1 = false;
						}

						//steve_2
						if (evt.key.keysym.sym == SDLK_LEFT) {
							hold_left_2 = false;
						}
						else if (evt.key.keysym.sym == SDLK_RIGHT) {
							hold_right_2 = false;
						}
					}
					
				}
				if (hold_left_1)
					fighter_1->control({ -10, 0 });
				if (hold_right_1)
					fighter_1->control({ 10, 0 });
				if (hold_left_2)
					fighter_2->control({ -10, 0 });
				if (hold_right_2)
					fighter_2->control({ 10, 0 });

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

