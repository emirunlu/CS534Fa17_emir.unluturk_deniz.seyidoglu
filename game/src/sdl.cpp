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

	run();

	clean();

	return 0;
}

void
SDL::run() {
	bool quit = false;

	bgImage = loadPNG("test.png");
	if (bgImage == NULL) { printf("Unable to load image %s! SDL Error: %s\n", "../../resources/test.bmp", SDL_GetError()); }
	drawBackground(bgImage);
	SDL_FreeSurface(bgImage);
	SDL_UpdateWindowSurface(window);

	SDL_ShowSimpleMessageBox(0, "Cartagena Menu", "Play with the (p) key!", window);

	while (!quit)
	{
		//Handle events on queue
		while (SDL_PollEvent(&e) != 0)
		{
			//User requests quit
			if (e.type == SDL_QUIT)
			{
				return;
			}
		}
		const Uint8* currentKeyStates = SDL_GetKeyboardState(NULL);
		if (currentKeyStates[SDL_SCANCODE_P])
			quit = true;
	}
	gameState();
}


void
SDL::playCard(Player* p) {
	int cardIndex, pirateIndex;
	cout << "Choose a card to use: ";
	cin >> cardIndex;
	cout << "Entered cardIndex: " << cardIndex << endl;
	cout << "Which pirate?: ";
	cin >> pirateIndex;
	cout << "Entered pirateIndex: " << pirateIndex << endl;
	p->playCard(cardIndex, pirateIndex);
	cout << "\n\nCard played! New information..\n";
}

void
SDL::goBack(Player* p) {
	int pirateIndex;
	cout << "Which pirate?: ";
	cin >> pirateIndex;
	p->moveBack(pirateIndex);
	cout << "\n\nNew information..\n";
}

void
SDL::executeChoice(int choice, Player* p) {
	switch (choice) {
	case 1:
		playCard(p);
		break;
	case 2:
		goBack(p);
		break;
	case 3:
		cout << "\n\nSkipping..\n";
		break;
	}
}

void
SDL::gameState() {
	bool quit = false;

	//Clear screen
	SDL_SetRenderDrawColor( renderer, 0xFF, 0xFF, 0xFF, 0xFF );
	SDL_RenderClear(renderer);
	const Uint8* currentKeyStates = SDL_GetKeyboardState(NULL);

	SDL_ShowSimpleMessageBox(0, "Cartagena InGame Instructions", "1) (M)ove card 2) Move Pirate (B)ackwards 3) (S)kip Turn", window);

	//Add Players
	Game* game = new Game();
	GameHelper* gameHelper = new GameHelper(game);
	Map* map = game->getMap();
	map->print();

	gameHelper->addPlayer("< blank >", "blue");
	gameHelper->addPlayer("AIPlayer2", "yellow");
	int playerCount;
	cout << "How many players?: (2-5)";
	cin >> playerCount;
	switch (playerCount) {
	case 2:
		break;
	case 3:
		gameHelper->addPlayer("AIPlayer3", "red");
		break;
	case 4:
		gameHelper->addPlayer("AIPlayer3", "red");
		gameHelper->addPlayer("AIPlayer4", "green");
		break;
	case 5:
		gameHelper->addPlayer("AIPlayer3", "red");
		gameHelper->addPlayer("AIPlayer4", "green");
		gameHelper->addPlayer("AIPlayer5", "brown");
		break;
	}

	unsigned int turn = 1;
	gameHelper->updatePlayerTurn(turn);
	Player* p = gameHelper->getCurrentPlayer();
	p->print();
	while (!quit)
	{
		Player* p = gameHelper->getCurrentPlayer();

		while (SDL_PollEvent(&e) != 0)
		{
			if (e.type == SDL_QUIT)
			{
				quit = true;
			}
		}

		if (currentKeyStates[SDL_SCANCODE_M]) { // Move card
			executeChoice(1, p);
			p->print();
			cout << "Press enter to continue" << endl;
			string temp;
			temp = cin.get();
			cin.ignore();
			if (turn == gameHelper->getPlayers().size())
				turn = 0;
			gameHelper->updatePlayerTurn(++turn);
			SDL_ShowSimpleMessageBox(0, "Cartagena InGame Instructions", "1) (M)ove card 2) Move Pirate (B)ackwards 3) (S)kip Turn", window);
		}
		else if (currentKeyStates[SDL_SCANCODE_B]) { // Move pirate backwards
			executeChoice(2, p);
			p->print();
			cout << "Press enter to continue" << endl;
			string temp;
			temp = cin.get();
			cin.ignore();
			if (turn == gameHelper->getPlayers().size())
				turn = 0;
			gameHelper->updatePlayerTurn(++turn);
			SDL_ShowSimpleMessageBox(0, "Cartagena InGame Instructions", "1) (M)ove card 2) Move Pirate (B)ackwards 3) (S)kip Turn", window);

		}
		else if (currentKeyStates[SDL_SCANCODE_S]) { // Skip turn
			executeChoice(3, p);
			p->print();
			cout << "Press enter to continue" << endl;
			string temp;
			temp = cin.get();
			cin.ignore();
			if (turn == gameHelper->getPlayers().size())
				turn = 0;
			gameHelper->updatePlayerTurn(++turn);
			SDL_ShowSimpleMessageBox(0, "Cartagena InGame Instructions", "1) (M)ove card 2) Move Pirate (B)ackwards 3) (S)kip Turn", window);

		}

		if (p->checkStatus()) {
			cout << "Game over!" << endl;
			cout << "Congrats " << p->getName() << "!!" << endl;
			delete game;
			return;
			
		}	
	}
	delete game;
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

SDL_Surface*
SDL::loadPNG(std::string path) {
	SDL_Surface* pngFile = NULL;

	SDL_Surface* load = IMG_Load(path.c_str());
	if (load == NULL)
	{
		printf("Unable to load image %s! SDL_image Error: %s\n", path.c_str(), IMG_GetError());
	}
	else
	{
		pngFile = SDL_ConvertSurface(load, screenSurface->format, NULL);
		if (pngFile == NULL)
		{
			printf("Unable to optimize image %s! SDL Error: %s\n", path.c_str(), SDL_GetError());
		}

		SDL_FreeSurface(load);
	}

	return pngFile;
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
