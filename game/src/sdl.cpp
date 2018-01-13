#include "../headers/sdl.h"

#define FPS 30
#define FRAME_RATE 1000/FPS

SDL::SDL() {
	window = 0;
	renderer = 0;
}

SDL::~SDL() {

}


int 
SDL::init() {
	// Initialize SDL subsystems(video and mixer) 
	SDL_Init(SDL_INIT_EVERYTHING);

	window = SDL_CreateWindow("Cartagena Board Game - v1.0.0", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, SDL_WINDOW_SHOWN | SDL_WINDOW_OPENGL);
	if (!window) {
		std::cout << "Error creating window:" << SDL_GetError() << std::endl;
		return -1;
	}

	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_PRESENTVSYNC | SDL_RENDERER_ACCELERATED);
	if (!renderer) {
		std::cout << "Error creating renderer:" << SDL_GetError() << std::endl;
		return -1;
	}
	timer = SDL_GetTicks();
	screenSurface = SDL_GetWindowSurface(window);

	bgImage = SDL_LoadBMP("test2.bmp");
	if (bgImage == NULL) { printf("Unable to load image %s! SDL Error: %s\n", "../../resources/test.bmp", SDL_GetError()); }
	drawBackground(bgImage); // draws test background for now

	SDL_UpdateWindowSurface(window);
	SDL_Delay(10000);

	clean();

	return 0;
}

void
SDL::clean() {
	// Clean resources
	SDL_DestroyTexture(texture);
	//TTF_Quit();
	// Clean renderer and window
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
}

void 
SDL::Menu() {
	if ((SDL_GetTicks() - timer) >= FRAME_RATE)
	{
		handleMenuInput();
		clearScreen();

		//displayText("Start (G)ame", 350, 250, 12, 255, 255, 255, 0, 0, 0);
		//displayText("(Q)uit Game", 350, 270, 12, 255, 255, 255, 0, 0, 0);

		SDL_RenderPresent(renderer);

		timer = SDL_GetTicks();
	}
}

void 
SDL::Game() {

}

void 
SDL::Exit() {

}

void 
SDL::drawBackground(SDL_Surface* bgImage) {
	SDL_Rect source = { 0, 0, 800, 600 };
	SDL_Rect destination = { 0, 0, 800, 600 };

	SDL_BlitSurface(bgImage, &source, screenSurface, &destination);
}

void 
SDL::clearScreen() {
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_RenderClear(renderer);
}
/*
void 
SDL::displayText(std::string text, int x, int y, int size, int fR, int fG, int fB, int bR, int bG, int bB) {
	TTF_Font* font = TTF_OpenFont("arial.ttf", size);

	SDL_Color foreground = { fR, fG, fB };
	SDL_Color background = { bR, bG, bB };

	SDL_Surface* temp = TTF_RenderText_Shaded(font, text.c_str(), foreground, background);

	SDL_Rect destination = { x, y, 0, 0 };

	SDL_BlitSurface(temp, NULL, backBuffer, &destination);

	SDL_FreeSurface(temp);

	TTF_CloseFont(font);
}
*/
void 
SDL::handleMenuInput() {

}

void 
SDL::handleGameInput() {

}

void 
SDL::handleExitInput() {

}
