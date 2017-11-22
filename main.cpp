#include <iostream>
#include "game/headers/card.h"
#include "game/headers/map.h"
using namespace std;

int 
main() {
	//Tnis will be our testbed
	// Card* card = new Card();
	// card->getSymbol()->print();
	Map* map = new Map();
	map->printSegments();
}
