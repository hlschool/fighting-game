#ifndef AUDIO_H
#define AUDIO_H

#include <SDL.h>
#include <SDL_ttf.h>
#include <SDL_mixer.h>
#include <string>
#include "vector.h"
using namespace std;

static void playAudio(string audio_path) {
	Mix_Chunk* chunk = Mix_LoadWAV(audio_path.c_str());
	Mix_PlayChannel(-1, chunk, 0);
}



#endif
