#ifndef SDL_H
#define SDL_H
#include <iostream>
#include <stack>
#include "../../helpers/headers/gameHelper.h"
#include "game.h"

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
	void playCard(Player * p);
	void goBack(Player * p);
	void executeChoice(int choice, Player * p);
	void gameState();
	void clean();

	SDL_Surface * loadPNG(std::string path);
	void drawBackground(SDL_Surface * bgImage);
	void clearScreen();

private:
	SDL_Window * window;
	SDL_Renderer* renderer;
	SDL_Texture* texture;
	SDL_Event e;

	SDL_Surface* screenSurface;
	SDL_Surface* bgImage; //our bg
	SDL_Event event;
	int timer;
};

#endif