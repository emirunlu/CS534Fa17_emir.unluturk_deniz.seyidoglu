#include <iostream>
#include "game/headers/card.h"
#include "game/headers/map.h"
#include "game/headers/game.h"
#include "helpers/headers/gameHelper.h"

using namespace std;

void 
printMenu(){
	cout << "1: Play card.\n";
	cout << "2: Move pirate backwards.\n";
	cout << "3: Skip this move.\n";
	cout << "========================\n";
	cout << "Choice: ";
}

void
playCard(Player* p){
	int cardIndex, pirateIndex;
	cout << "Choose a card to use: ";
	cin >> cardIndex;
	cout << "Which pirate?: ";
	cin >> pirateIndex;
	p->playCard(cardIndex, pirateIndex);
	cout << "\n\nCard played! New information..\n";
}

void 
goBack(Player* p) {
	int pirateIndex;	
	cout << "Which pirate?: ";
	cin >> pirateIndex;
	p->moveBack(pirateIndex);
	cout << "\n\nPirate moved back! New information..\n";
}

void
executeChoice(int choice, Player* p){
	switch(choice){
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
	// gameHelper->addPlayer("testAI1", "yellow");
	// gameHelper->addPlayer("testAI2", "red");
	// gameHelper->addPlayer("testAI3", "green");
	cout << "\n========================\n";
	cout << "Starting the Game!!!" << endl;
	cout << "========================\n\n";
	unsigned int turn = 1;
	int choice;
	gameHelper->updatePlayerTurn(turn);
	while (true) {
		Player* p = gameHelper->getCurrentPlayer();
		if (p != NULL) {
			for (int i = 0; i < 2; ++i){
				p->print();
				printMenu();
				cin >> choice;
				if (choice < 0 || choice > 3){
					cout << "Wrong choice, please try again!\n\n";
					--i;
				} else {
					executeChoice(choice, p);
					p->print();	
					cout << "Press enter to continue" << endl;
					getchar();
				}
			}
		}
		if (p->checkStatus()){
			cout << "Game over!" << endl;
			cout << "Congrats " << p->getName() << "!!" << endl;
			delete game;
			return 0;	
		}
		if (turn > gameHelper->getPlayers().size())
			turn = 1;
		gameHelper->updatePlayerTurn(++turn);
	}
	delete game;
	return -1;
}