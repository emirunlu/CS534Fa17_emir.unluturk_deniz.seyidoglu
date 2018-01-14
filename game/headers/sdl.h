#ifndef SDL_H
#define SDL_H
#include <iostream>
#include <stack> 

#include <SDL.h>            // SDL2
#include <SDL_video.h>      // SDL2
#include <SDL_image.h>      // SDL2_Image
#include <SDL_ttf.h>        // SDL2_TTF
#include <SDL_mixer.h>      // SDL2_Mixer
#include <SDL_net.h>      // SDL2_Net

struct State
{
	void(*StatePointer)();
};

class SDL {
public:
	SDL();
	~SDL();

	int init();
	SDL_Surface * loadPNG(std::string path);
	void clean();

	void Menu();
	void Game();
	void Exit();

	void drawBackground(SDL_Surface* bgImage);
	void clearScreen();
	//void displayText(std::string text, int x, int y, int size,
	//	int fR, int fG, int fB, int bR, int bG, int bB);
	void handleMenuInput();
	void handleGameInput();
	void handleExitInput();

private:
	SDL_Window * window;
	SDL_Renderer* renderer;
	SDL_Texture* texture;

	SDL_Surface* bgImage;  // Our background image
	SDL_Surface* screenSurface;
	SDL_Event event;
	int timer;

	std::stack<State *> gameStack;
};

#endif