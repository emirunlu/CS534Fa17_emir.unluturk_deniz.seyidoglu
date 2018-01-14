#include <iostream>
#include "game/headers/card.h"
#include "game/headers/map.h"
#include "game/headers/game.h"
#include "helpers/headers/gameHelper.h"
#include "game/headers/sdl.h"
using namespace std;

void 
printMenu(){
	cout << "1: Play card.\n";
	cout << "2: Move pirate backwards.\n";
	cout << "3: Skip this move.\n";
	cout << "========================\n";
	cout << "Choice: ";
}

int 
main(int argc, char* args[]) {
	cout << "Welcome to the Cartagena game!\n";
	cout << "\n========================\n";
	cout << "Printing map:\n";		
 	cout << "========================\n\n";		

	SDL* gui = new SDL();
	gui->init();

	return -1;
}