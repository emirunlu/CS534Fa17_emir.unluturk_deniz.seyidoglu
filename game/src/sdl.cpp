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

	//PNG init
	int imgFlags = IMG_INIT_PNG;
	if( !( IMG_Init( imgFlags ) & imgFlags ) ) {
		printf( "SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError() );
	}
	else {
		screenSurface = SDL_GetWindowSurface(window);
	}

	stateManager::setState(new menuState());

	run();

	clean();

	return 0;
}

void
SDL::run() {
	bool quit = false;
	while (!quit)
	{
		while (SDL_PollEvent(&e)) {

			stateManager::getState()->handleEvents(e);

			if (event.type == SDL_QUIT) {
				quit = true;
			}
		}

		stateManager::getState()->Update();

		SDL_RenderClear(renderer);

		stateManager::getState()->Render();

		SDL_RenderPresent(renderer);
	}
}

void
SDL::clean() {
	// Clean resources
	SDL_DestroyTexture(texture);
	// Clean renderer and window
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	IMG_Quit();
	SDL_Quit();
}

void 
SDL::clearScreen() {
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_RenderClear(renderer);
}
