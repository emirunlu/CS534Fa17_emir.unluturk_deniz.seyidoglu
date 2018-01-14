
#include "../headers/cli.h"

using namespace std;

CLI::CLI() {
	
}

CLI::~CLI() {

}

void
CLI::printMenu() {
	cout << "1: Play card.\n";
	cout << "2: Move pirate backwards.\n";
	cout << "3: Skip this move.\n";
	cout << "========================\n";
	cout << "Choice: ";
}

void
CLI::playCard(Player* p) {
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
CLI::goBack(Player* p) {
	int pirateIndex;
	cout << "Which pirate?: ";
	cin >> pirateIndex;
	p->moveBack(pirateIndex);
	cout << "\n\nNew information..\n";
}

void
CLI::executeChoice(int choice, Player* p) {
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
CLI::init() {
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
	cout << "\n========================\n";
	cout << "Starting the Game!!!" << endl;
	cout << "========================\n\n";
	unsigned int turn = 1;
	int choice;
	gameHelper->updatePlayerTurn(turn);
	while (true) {
		Player* p = gameHelper->getCurrentPlayer();
		if (p != NULL) {
			for (int i = 0; i < 2; ++i) {
				p->print();
				printMenu();
				cin >> choice;
				if (choice < 0 || choice > 3) {
					cout << "Wrong choice, please try again!\n\n";
					--i;
				}
				else {
					executeChoice(choice, p);
					p->print();
					cout << "Press enter to continue" << endl;
					string temp;
					temp = cin.get();
					cin.ignore();
				}
			}
		}
		if (p->checkStatus()) {
			cout << "Game over!" << endl;
			cout << "Congrats " << p->getName() << "!!" << endl;
			delete game;
			return;
		}
		if (turn == gameHelper->getPlayers().size()) {
			turn = 0;
		}
		gameHelper->updatePlayerTurn(++turn);
	}
	delete game;
}