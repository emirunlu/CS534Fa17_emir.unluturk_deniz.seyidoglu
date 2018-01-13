#include <iostream>
#include "game/headers/card.h"
#include "game/headers/map.h"
#include "game/headers/game.h"
#include "helpers/headers/gameHelper.h"

using namespace std;

int 
main() {
	Game* game = new Game();
	cout << "Welcome to the Cartagena game!\n";
	cout << "\n========================\n";
	cout << "Printing map:\n";		
 	cout << "========================\n\n";		
 	Map* map = game->getMap();		
 	map->print();

	cout << "\n\nPlease enter your name" << endl;

	string name = "";
	// cin >> name;
	name = "< blank >";

	GameHelper* gameHelper = new GameHelper(game);
	gameHelper->addPlayer(name, "blue");
	gameHelper->addPlayer("testAI1", "yellow");
	gameHelper->addPlayer("testAI2", "red");
	gameHelper->addPlayer("testAI3", "green");
	cout << "\n========================\n";
	cout << "Starting the Game!!!" << endl;
	cout << "========================\n\n";
	unsigned int turn = 1;
	gameHelper->updatePlayerTurn(turn);
	while (true) {
		Player* p = gameHelper->getCurrentPlayer();
		if (p != NULL) {
			p->print();
			int cardIndex, pirateIndex;
			cout << "Choose a card to use: ";
			cin >> cardIndex;
			cout << "Which pirate? ";
			cin >> pirateIndex;
			p->playCard(cardIndex, pirateIndex);
			cout << "\n\nCard played! New information..";
			p->print();
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

	delete game;
}
