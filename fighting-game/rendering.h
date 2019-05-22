#ifndef RENDERING_H
#define RENDERING_H

#include <SDL.h>
#include <SDL_ttf.h>
#include <string>
#include "vector.h"
using namespace std;

static void renderText(SDL_Renderer* renderer, TTF_Font* font, string message, const vector pos, SDL_Color color) {
	const char* message_char = message.c_str();
	SDL_Surface* message_surf = TTF_RenderText_Solid(font, message_char, color);
	SDL_Texture* message_texture = SDL_CreateTextureFromSurface(renderer, message_surf);
	SDL_Rect message_rect = { pos.x - (message_surf->w / 2), pos.y - (message_surf->h / 2), message_surf->w, message_surf->h };
	SDL_FreeSurface(message_surf);
	SDL_RenderCopy(renderer, message_texture, NULL, &message_rect);
}

static void renderImage(SDL_Renderer* renderer, string path, const vector pos) {
	SDL_Surface* surface = IMG_Load(path.c_str());
	SDL_Rect fillRect = { pos.x, pos.y, surface->w, surface->h };
	SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);
	SDL_RenderCopy(renderer, texture, NULL, &fillRect);
}



#endif