// #include "../headers/sdl.h"

// #define FPS 30
// #define FRAME_RATE 1000/FPS

// SDL::SDL() {
// 	window = 0;
// 	renderer = 0;
// }

// SDL::~SDL() {

// }


// int 
// SDL::init() {
// 	// Initialize SDL subsystems(video and mixer) 
// 	SDL_Init(SDL_INIT_EVERYTHING);
// 	if (TTF_Init() == -1) {
// 		printf("TTF_Init: %s\n", TTF_GetError());
// 		exit(2);
// 	}
// 	window = SDL_CreateWindow("Cartagena Board Game - v1.0.0", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, SDL_WINDOW_SHOWN | SDL_WINDOW_OPENGL);
// 	if (!window) {
// 		std::cout << "Error creating window:" << SDL_GetError() << std::endl;
// 		return -1;
// 	}

// 	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_PRESENTVSYNC | SDL_RENDERER_ACCELERATED);
// 	if (!renderer) {
// 		std::cout << "Error creating renderer:" << SDL_GetError() << std::endl;
// 		return -1;
// 	}
// 	timer = SDL_GetTicks();

// 	//PNG init
// 	int imgFlags = IMG_INIT_PNG;
// 	if( !( IMG_Init( imgFlags ) & imgFlags ) ) {
// 		printf( "SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError() );
// 	}
// 	else {
// 		screenSurface = SDL_GetWindowSurface(window);
// 	}
	
// 	bgImage = loadPNG("test.png");
// 	if (bgImage == NULL) { printf("Unable to load image %s! SDL Error: %s\n", "../../resources/test.bmp", SDL_GetError()); }

// 	bool quit = false;
// 	while (!quit)
// 	{
// 		//Handle events on queue
// 		while (SDL_PollEvent(&e) != 0)
// 		{
// 			//User requests quit
// 			if (e.type == SDL_QUIT)
// 			{
// 				quit = true;
// 			}
// 		}

// 		//Clear screen
// 		SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
// 		SDL_RenderClear(renderer);

// 		//Test menu for now
// 		drawBackground(bgImage); // draws test background for now
// 		SDL_UpdateWindowSurface(window);

// 		//Render current frame
// 		displayText("Start (G)ame", 350, 250, 12, 255, 255, 255, 0, 0, 0);
	
// 		displayText("(Q)uit Game", 350, 270, 12, 255, 255, 255, 0, 0, 0);

// 		//Update screen
// 		SDL_RenderPresent(renderer);
// 	}

// 	clean();

// 	return 0;
// }

// SDL_Surface* SDL::loadPNG(std::string path)
// {
// 	SDL_Surface* pngFile = NULL;

// 	SDL_Surface* load = IMG_Load(path.c_str());
// 	if (load == NULL)
// 	{
// 		printf("Unable to load image %s! SDL_image Error: %s\n", path.c_str(), IMG_GetError());
// 	}
// 	else
// 	{
// 		//Convert surface to screen format
// 		pngFile = SDL_ConvertSurface(load, screenSurface->format, NULL);
// 		if (pngFile == NULL)
// 		{
// 			printf("Unable to optimize image %s! SDL Error: %s\n", path.c_str(), SDL_GetError());
// 		}

// 		//Get rid of old loaded surface
// 		SDL_FreeSurface(load);
// 	}

// 	return pngFile;
// }

// void
// SDL::clean() {
// 	// Clean resources
// 	SDL_DestroyTexture(texture);
// 	// Clean renderer and window
// 	SDL_DestroyRenderer(renderer);
// 	SDL_DestroyWindow(window);
// 	TTF_Quit();
// 	IMG_Quit();
// 	SDL_Quit();
// }

// void 
// SDL::Menu() {
// 	if ((SDL_GetTicks() - timer) >= FRAME_RATE)
// 	{
// 		handleMenuInput();
// 		clearScreen();

// 		displayText("Start (G)ame", 350, 250, 12, 255, 255, 255, 0, 0, 0);
// 		displayText("(Q)uit Game", 350, 270, 12, 255, 255, 255, 0, 0, 0);

// 		SDL_RenderPresent(renderer);

// 		timer = SDL_GetTicks();
// 	}
// }

// void 
// SDL::Game() {

// }

// void 
// SDL::Exit() {

// }

// void 
// SDL::drawBackground(SDL_Surface* bgImage) {
// 	SDL_Rect source = { 0, 0, 800, 600 };
// 	SDL_Rect destination = { 0, 0, 800, 600 };

// 	SDL_BlitSurface(bgImage, &source, screenSurface, &destination);
// }

// void 
// SDL::clearScreen() {
// 	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
// 	SDL_RenderClear(renderer);
// }

// void 
// SDL::displayText(std::string text, int x, int y, int size, int fR, int fG, int fB, int bR, int bG, int bB) {
// 	TTF_Font* font = TTF_OpenFont("arial.ttf", size);

// 	SDL_Color foreground = { fR, fG, fB };
// 	SDL_Color background = { bR, bG, bB };

// 	SDL_Surface* temp = TTF_RenderText_Shaded(font, text.c_str(), foreground, background);

// 	SDL_Texture* textureText = SDL_CreateTextureFromSurface(renderer, temp);
// 	SDL_Rect destination = { x, y, 0, 0 };

// 	//SDL_BlitSurface(temp, NULL, screenSurface, &destination);

// 	SDL_RenderCopy(renderer, textureText, NULL, &destination);

// 	SDL_FreeSurface(temp);

// 	TTF_CloseFont(font);
// }

// void 
// SDL::handleMenuInput() {

// }

// void 
// SDL::handleGameInput() {

// }

// void 
// SDL::handleExitInput() {

// }
