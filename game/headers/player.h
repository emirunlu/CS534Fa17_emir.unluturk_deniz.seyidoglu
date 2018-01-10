#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <string>
#include <vector>
#include "../../game/headers/card.h"
#include "../../map/headers/pirate.h"

class Player {
private:
	std::string playerName;
	std::string playerColor;
	std::vector<Pirate*> pirateList;
	std::vector<Card*> cardList;

public:
	Player();
	~Player();
	Player(std::string name, std::string color);

	std::string getName();
	std::string getColor();

	void addCard(Card* c);
	void addPirate(Pirate* p);
	std::vector<Card*> getHand();
	Card * getCardInHand(int i);
	std::vector<Pirate*> getPirateList();
	Pirate * getPirateInList(int i);
};

#endif
