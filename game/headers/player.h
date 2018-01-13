#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <string>
#include <vector>
#include "../../game/headers/card.h"
#include "../../map/headers/pirate.h"
#include "./game.h"

using namespace std;

class Player {
public:
	Player();
	~Player();
	Player(string name, string color, Game* game);

	string getName();
	string getColor();

	void addPirate(Pirate* p);
	void movePirate(int index, Cell* c);
	vector<Pirate*> getPirateList();
	Pirate * getPirateInList(int i);

	vector<Card*> getHand();
	Card * getCardInHand(int i);
	void playCard(int cardIndex, int pirateIndex);
	void addCard(Card* c);
	void getCard();

	void print();
protected:
private:
	Game* game;
	string playerName;
	string playerColor;
	vector<Pirate*> pirateList;
	vector<Card*> cardList;
};

#endif
