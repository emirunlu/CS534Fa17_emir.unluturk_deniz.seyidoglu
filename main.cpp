#include <iostream>
#include "game/headers/card.h"
#include "game/headers/map.h"
#include "game/headers/game.h"
#include "helpers/headers/gameHelper.h"

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

	cout << "Please enter your name" << endl;

	string name = "";
	cin >> name;

	GameHelper* gameHelper = new GameHelper(name, "green");
	gameHelper->addPlayer("testAI1", "red");
	gameHelper->addPlayer("testAI2", "blue");
	gameHelper->addPlayer("testAI3", "yellow");
	cout << "\n========================\n";
	cout << "Starting the Game!!!" << endl;
	cout << "========================\n\n";
	unsigned int turn = 1;
	gameHelper->updatePlayerTurn(turn);
	while (true) {
		Player* p = gameHelper->getCurrentPlayer();
		if (p != NULL) {
			cout << "Current player's turn: " << p->getName() << endl;
			cout << "Current player's color: " << p->getColor() << endl;
		}
		if (turn > gameHelper->getPlayers().size())
			turn = 0;

		cout << "Continue game? y or n" << endl;

		string cont = "";
		cin >> cont;
		if (cont == "n")
			break;
		gameHelper->updatePlayerTurn(++turn);
	}
}
