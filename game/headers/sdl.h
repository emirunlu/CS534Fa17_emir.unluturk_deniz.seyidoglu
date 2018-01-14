#ifndef SDL_H
#define SDL_H
#include <iostream>
#include <stack>
#include "state.h"
#include "stateManager.h"
#include "menuState.h"
#include "imageManager.h"

#include <SDL.h>            // SDL2
#include <SDL_video.h>      // SDL2
#include <SDL_image.h>      // SDL2_Image
#include <SDL_mixer.h>      // SDL2_Mixer
#include <SDL_net.h>      // SDL2_Net

class SDL {
public:
	SDL();
	~SDL();

	int init();
	void run();
	void clean();

	void clearScreen();

private:
	SDL_Window * window;
	SDL_Renderer* renderer;
	SDL_Texture* texture;
	SDL_Event e;

	SDL_Surface* screenSurface;
	SDL_Event event;
	int timer;
};

#endif