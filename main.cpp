#include <iostream>
#include "game/headers/card.h"
#include "game/headers/map.h"
#include "game/headers/game.h"
using namespace std;

//Tnis will be our testbed
int 
main() {
	// Card* card = new Card();
	// card->getSymbol()->print();
	// Map* map = new Map();
	// map->printSegments();

	Game* game = new Game();
	cout << "Welcome to the Cartagena game!\n";
	cout << "\n========================\n";
	cout << "Printing map:\n";
	cout << "========================\n\n";
	Map* map = game->getMap();
	map->printSegments();

	std::vector<Card*> cards = game->getCards();
	cout << "\n========================\n";
	cout << "Printing cards:\n";
	cout << "========================\n\n";
	for (int i = 0; i < cards.size(); ++i) {
		cout << (i + 1);
		cout << "\t ";
		cards[i]->getSymbol()->print();
	}
}
