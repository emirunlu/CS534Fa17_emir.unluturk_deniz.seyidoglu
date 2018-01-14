#ifndef CLI_H
#define CLI_H

#include <iostream>
#include "card.h"
#include "map.h"
#include "game.h"
#include "../../helpers/headers/gameHelper.h"

class CLI {
public:
	CLI();
	~CLI();

	void printMenu();
	void playCard(Player * p);
	void goBack(Player * p);
	void executeChoice(int choice, Player * p);
	void init();

protected:
private:

};

#endif